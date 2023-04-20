#include "scenecontroller.h"
#include "animations/cardAnimator/cardanimator.h"
#include "items/buttonItem/buttonitem.h"
#include "items/cardItem/icard.h"
#include "items/dibItem/dibitem.h"
#include "items/factory/cardfactory.h"
#include "items/labels/betLabel/betlabel.h"
#include "items/players/dealer/dealer.h"
#include "items/players/player/player.h"
#include "items/popup/popup.h"
#include "model/controller/modelcontroller.h"
#include "model/items/players/iplayer.h"

#include <QGraphicsItem>
#include <QGraphicsItemAnimation>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QTimeLine>

SceneController::SceneController(QGraphicsScene *scene, ModelController *modelController,
                                 Theme theme)
    : _modelController{ modelController },
      _deckPlace{ new QGraphicsRectItem },
      _theme{ theme },
      _scene{ scene },
      _hitButton{ new Scene::ButtonItem(":/images/buttons/resources/hit.png",
                                        [this]() { addCardForPlayer(); }) },
      _standButton{ new Scene::ButtonItem(":/images/buttons/resources/stand.png",
                                          [this]() { playersResults(); }) },
      _dib{ new Scene::DibItem(":/images/resources/dib.png") },
      _dibLabel{ new Scene::BetLabel(5) },
      _cardAnimator{ new Scene::CardAnimator(this) },
      _restartPopup{ new Scene::Popup([this]() { startGame(); }) }
{
    createCards();
    addCardsToScene();
    initDeckPlace();
    createButtons();
    createDib();
    createPlayers();
    addPlayersToScene();
    setupPopup();
    connectSignals();
}

std::vector<Scene::ICard *> SceneController::cards()
{
    return _cards;
}

void SceneController::createCards()
{
    for (auto *card : _modelController->cards())
    {
        CardFactory cardFactory{ card, _theme };
        _cards.push_back(cardFactory.create());
    }
}

void SceneController::initDeckPlace()
{
    _scene->addItem(_deckPlace);

    const double deckMargin{ 20 };

    QRectF cardRect{ dynamic_cast<QGraphicsItem *>(_cards.front())->boundingRect() };
    QPointF deckPos{ _scene->sceneRect().topRight().x() - cardRect.width() - deckMargin,
                     _scene->sceneRect().topRight().y() + deckMargin };
    _deckPlace->setPos(deckPos);
}

void SceneController::addCardsToScene()
{
    for (auto *card : cards())
    {
        auto *item{ dynamic_cast<QGraphicsItem *>(card) };
        _scene->addItem(item);
    }
}

void SceneController::makeDeck()
{
    double moveMargin{ 0 };
    for (auto *card : cards())
    {
        card->close();

        auto *item{ dynamic_cast<QGraphicsItem *>(card) };

        if (item == nullptr)
            continue;

        item->setParentItem(nullptr);
        item->setPos(_deckPlace->mapToScene(-moveMargin, moveMargin));
        moveMargin += 0.1;
    }
    _lastCardInDeck = cards().size() - 1;
}

void SceneController::createButtons()
{
    _scene->addItem(_hitButton);

    QPointF hitPos{ _scene->sceneRect().topRight().x() - 115,
                    _scene->sceneRect().topRight().y() + 250 };
    _hitButton->setPos(hitPos);

    _scene->addItem(_standButton);

    QPointF standPos{ _scene->sceneRect().topRight().x() - 115,
                      _scene->sceneRect().topRight().y() + 350 };
    _standButton->setPos(standPos);
}

void SceneController::createDib()
{
    _scene->addItem(_dib);

    QPointF dibPos{ _scene->sceneRect().topLeft().x() + 25,
                    _scene->sceneRect().topLeft().y() + 250 };
    _dib->setPos(dibPos);

    _scene->addItem(_dibLabel);
    _dibLabel->setParentItem(_dib);
    _dibLabel->moveBy(5, -10);
}

void SceneController::createPlayers()
{
    for (auto *player : _modelController->players())
    {

        if (player->id() == 0)
            _players.push_back(new Scene::Dealer(player));
        else
            _players.push_back(new Scene::Player(player));
    }
}

void SceneController::playersResults()
{
    changeTurn();
}

void SceneController::addCardForPlayer()
{
    if (_cardAnimator->isRunning())
        return;

    Scene::ICard *neededCard = _cards.at(_lastCardInDeck);
    QGraphicsItem *card{ dynamic_cast<QGraphicsItem *>(neededCard) };

    if (card == nullptr)
        return;

    auto *player{ _players.at(_currentPlayerTurn) };
    card->setZValue(100);
    player->addCard(card);
    moveCardAnimation(card, player);
    _lastCardInDeck--;
}

void SceneController::addPlayersToScene()
{
    for (auto *player : _players)
    {
        auto *item{ dynamic_cast<QGraphicsItem *>(player) };

        if (item == nullptr)
            continue;

        _scene->addItem(item);
        player->init();
        player->setupPointLabel();
    }
}

void SceneController::changeTurn()
{
    if (_currentPlayerTurn == 0)
        _currentPlayerTurn++;
    else
        _currentPlayerTurn -= _currentPlayerTurn;
}

void SceneController::moveCardAnimation(QGraphicsItem *card, Scene::IPlayer *player)
{
    _cardAnimator->setCard(card);
    _cardAnimator->moveTo(player->cardStart());
}

void SceneController::updateCurrentPlayerCards(QGraphicsItem *item)
{
    Scene::ICard *card{ dynamic_cast<Scene::ICard *>(item) };

    if (card == nullptr)
        return;

    auto *player{ _players.at(_currentPlayerTurn) };
    player->updateCards();

    _modelController->addCardForPlayer(player->modelId(), card->modelId(), card->isOpen());

    player->updatePointLabel();
}

void SceneController::connectSignals()
{
    QObject::connect(_cardAnimator, &Scene::CardAnimator::animated, this,
                     &SceneController::updateCurrentPlayerCards);
void SceneController::setupPopup()
{
    _scene->addItem(_restartPopup);
    QPointF popupPos{ (_scene->sceneRect().width() - _restartPopup->boundingRect().width()) / 2,
                      (_scene->sceneRect().height() - _restartPopup->boundingRect().height()) / 2 };
    _restartPopup->setPos(popupPos);
    _restartPopup->setupContent();
}
}
