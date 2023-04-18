#include "scenecontroller.h"
#include "items/buttonItem/buttonitem.h"
#include "items/cardItem/icard.h"
#include "items/dibItem/dibitem.h"
#include "items/factory/cardfactory.h"
#include "items/labels/betLabel/betlabel.h"
#include "items/players/dealer/dealer.h"
#include "items/players/player/player.h"
#include "model/controller/modelcontroller.h"
#include "model/items/players/iplayer.h"

#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>

SceneController::SceneController(QGraphicsScene *scene, ModelController *modelController,
                                 Theme theme)
    : _modelController{ modelController },
      _theme{ theme },
      _scene{ scene },
      _hitButton{ new Scene::ButtonItem(":/images/buttons/resources/hit.png",
                                        [this]() { addCardForPlayer(); }) },
      _standButton{ new Scene::ButtonItem(":/images/buttons/resources/stand.png",
                                          [this]() { playersResults(); }) },
      _dib{ new Scene::DibItem(":/images/resources/dib.png") },
      _dibLabel{ new Scene::BetLabel(5) }
{
    createCards();
    addCardsToScene();
    makeDeck();
    createButtons();
    createDib();
    createPlayers();
    addPlayersToScene();
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
    const double deckMargin{ 20 };
    double moveMargin{ 0 };

    for (auto *card : cards())
    {
        auto *item{ dynamic_cast<QGraphicsItem *>(card) };

        QPointF deckPos{ _scene->sceneRect().topRight().x() - item->boundingRect().width()
                             - moveMargin - deckMargin,
                         _scene->sceneRect().topRight().y() + deckMargin + moveMargin };

        if (item == nullptr)
            continue;

        item->setPos(deckPos);
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
}

void SceneController::addCardForPlayer()
{
    Scene::ICard *card{ _cards.at(_lastCardInDeck) };
}

void SceneController::addPlayersToScene()
{
    for (auto *player : _players)
    {
        auto *item = dynamic_cast<QGraphicsItem *>(player);

        if (item == nullptr)
            continue;

        _scene->addItem(item);
        player->init();
    }
}
