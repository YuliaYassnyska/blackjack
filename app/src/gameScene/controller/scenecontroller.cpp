#include "scenecontroller.h"
#include "animations/cardAnimator/cardanimator.h"
#include "enums/resultEnums/resultenums.h"
#include "items/buttonItem/buttonitem.h"
#include "items/cardItem/icard.h"
#include "items/cashLabel/cashlabel.h"
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

#include <algorithm>
#include <random>

SceneController::SceneController(QGraphicsScene *scene, ModelController *modelController,
                                 Theme theme)
    : _modelController{ modelController },
      _deckPlace{ new QGraphicsRectItem },
      _theme{ theme },
      _scene{ scene },
      _hitButton{ new Scene::ButtonItem(":/images/buttons/resources/hit.png",
                                        [this]() { addCardAfterHit(); }) },
      _standButton{ new Scene::ButtonItem(":/images/buttons/resources/stand.png",
                                          [this]() { stand(); }) },
      _dib{ new Scene::DibItem(":/images/resources/dib.png") },
      _dibLabel{ new Scene::BetLabel(5) },
      _cardAnimator{ new Scene::CardAnimator(this) },
      _restartPopup{ new Scene::Popup([this]() { startGame(); },
                                      ":/images/resources/restart.png") },
      _newGamePopup{ new Scene::Popup([this]() { newGame(); },
                                      ":/images/resources/new_game.jpeg") },
      _addCardTimer{ new QTimeLine(50, this) }
{
    connectSignals();
    createCards();
    addCardsToScene();
    createNewGamePopup();
    initDeckPlace();
    createButtons();
    createDib();
    createPlayers();
    addPlayersToScene();
    addCashLabelToScene();
    setupPopup();
    startGame();
}

SceneController::~SceneController()
{
    delete _hitButton;
    delete _standButton;
    delete _dib;
    delete _dibLabel;
    delete _restartPopup;
    delete _newGamePopup;
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
    for (auto *card : _cards)
    {
        auto *item{ dynamic_cast<QGraphicsItem *>(card) };
        _scene->addItem(item);
    }
}

void SceneController::makeDeck()
{
    double moveMargin{ 0 };
    for (auto *card : _cards)
    {
        card->close();

        auto *item{ dynamic_cast<QGraphicsItem *>(card) };

        if (item == nullptr)
            continue;

        item->setPos(_deckPlace->mapToScene(-moveMargin, moveMargin));
        moveMargin += 0.1;
    }
    _lastCardInDeck = 0;
}

void SceneController::shuffleDeck()
{
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(_cards), std::end(_cards), rng);
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

void SceneController::addCashLabelToScene()
{
    _cashLabel = new Scene::CashLabel(_players.back());
    _scene->addItem(_cashLabel);
    _cashLabel->setZValue(200);

    QPointF labelPos{ _scene->sceneRect().left(),
                      _scene->sceneRect().bottom() - _cashLabel->boundingRect().height() };
    _cashLabel->setPos(labelPos);
}

void SceneController::createNewGamePopup()
{
    _scene->addItem(_newGamePopup);

    QPointF newGamePos{ (_scene->sceneRect().width() - _restartPopup->boundingRect().width()) / 2,
                        (_scene->sceneRect().height() - _restartPopup->boundingRect().height())
                            / 2 };
    _newGamePopup->setPos(newGamePos);

    _newGamePopup->setupContent();
    _newGamePopup->show();
    _newGamePopup->updateText(getGameText(Game::NEW));
}

void SceneController::stand()
{
    Scene::Dealer *dealer = dynamic_cast<Scene::Dealer *>(_players.front());

    if (dealer == nullptr)
        return;

    auto cardId{ dealer->showClosedCard() };
    _modelController->setCardOpen(cardId, true);
    dealer->updatePointLabel();

    addCardsForDealer(dealer);
}

void SceneController::addCardAfterHit()
{
    auto *player{ _players.back() };

    addCardForPlayer(player);
}

void SceneController::addCardForPlayer(Scene::IPlayer *player)
{
    if (_cardAnimator->isRunning())
        return;

    Scene::ICard *neededCard = _cards.at(_lastCardInDeck);
    QGraphicsItem *card{ dynamic_cast<QGraphicsItem *>(neededCard) };

    if (card == nullptr)
        return;

    card->setZValue(100);
    player->addCard(card);
    moveCardAnimation(card, player);
    _lastCardInDeck++;
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

void SceneController::moveCardAnimation(QGraphicsItem *card, Scene::IPlayer *player)
{
    _cardAnimator->setCard(card);
    _cardAnimator->moveToPlayer(player);
}

void SceneController::updatePlayerCards(QGraphicsItem *item, Scene::IPlayer *player)
{
    Scene::ICard *card{ dynamic_cast<Scene::ICard *>(item) };

    if (card == nullptr)
        return;

    player->updateCards();

    _modelController->addCardForPlayer(player->modelId(), card->modelId(), card->isOpen());

    player->updatePointLabel();

    emit cardAdded(player->modelId());
}

void SceneController::connectSignals()
{
    QObject::connect(_cardAnimator, &Scene::CardAnimator::animated, this,
                     &SceneController::updatePlayerCards);
    QObject::connect(_modelController, &ModelController::roundEnd, this,
                     &SceneController::summaryResults);
    QObject::connect(this, &SceneController::addForDealer, this, &SceneController::onAddForDealer);
}

void SceneController::summaryResults()
{
    _restartPopup->updateText(getResultText(_players.back()->result()));
    _cashLabel->updateContent();
    _restartPopup->show();
}

void SceneController::startGame()
{
    _restartPopup->hide();
    shuffleDeck();
    makeDeck();
    clearPlayersCards();
    takeCardsOnStart();
}

void SceneController::setupPopup()
{
    _scene->addItem(_restartPopup);
    QPointF popupPos{ (_scene->sceneRect().width() - _restartPopup->boundingRect().width()) / 2,
                      (_scene->sceneRect().height() - _restartPopup->boundingRect().height()) / 2 };
    _restartPopup->setPos(popupPos);
    _restartPopup->setupContent();
}

void SceneController::clearPlayersCards()
{
    _modelController->clearPlayerCards();
    for (auto *player : _players)
    {
        player->clearCards();
        player->updatePointLabel();
    }
}

void SceneController::takeCardsOnStart()
{
    connect(_addCardTimer, &QTimeLine::finished, this, &SceneController::onCardAdded);
    _addCardTimer->start();
}

void SceneController::newGame()
{
    _newGamePopup->hide();
    _players.back()->resetCash();
    _cashLabel->updateContent();
    startGame();
}

void SceneController::onCardAdded()
{
    auto playerIt{ std::find_if(_players.cbegin(), _players.cend(),
                                [](Scene::IPlayer *player) { return player->cardsSize() < 2; }) };
    if (playerIt == _players.cend())
    {
        disconnect(_addCardTimer, &QTimeLine::finished, this, &SceneController::onCardAdded);
        return;
    }

    addCardForPlayer(*playerIt);
    _addCardTimer->start();
}

void SceneController::addCardsForDealer(Scene::Dealer *dealer)
{
    connect(_addCardTimer, &QTimeLine::finished,
            [dealer, this]() { SceneController::onAddForDealer(dealer); });
    _addCardTimer->start();
}

void SceneController::onAddForDealer(Scene::Dealer *dealer)
{
    if (dealer->currentScore() >= 17)
    {
        disconnect(_addCardTimer, nullptr, nullptr, nullptr);
        _modelController->summaryResults(dealer->modelId());
        return;
    }
    addCardForPlayer(dealer);
    _addCardTimer->start();
}
