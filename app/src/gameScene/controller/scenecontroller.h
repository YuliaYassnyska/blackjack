#pragma once

#include "enums/cardEnums/cardenums.h"
#include "items/players/iplayer.h"

#include <vector>

namespace Scene
{
class ICard;
}
class ModelController;

class QGraphicsScene;
class QGraphicsItem;
class QWidget;

class SceneController
{
public:
    SceneController(QGraphicsScene *scene, ModelController *modelController, Theme theme);
    std::vector<Scene::ICard *> cards();

private:
    void createCards();
    void addCardsToScene();
    void makeDeck();
    void createButtons();
    void createDib();
    void createPlayers();
    void playersResults();
    void addCardForPlayer();
    void addPlayersToScene();

    QGraphicsScene *_scene;
    std::vector<Scene::ICard *> _cards;
    ModelController *_modelController;
    Theme _theme;
    QGraphicsItem *_hitButton;
    QGraphicsItem *_standButton;
    QGraphicsItem *_dib;
    QGraphicsItem *_dibLabel;
    int _lastCardInDeck{ 0 };
    std::vector<Scene::IPlayer *> _players;
};
