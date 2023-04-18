#pragma once

#include "enums/cardEnums/cardenums.h"
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

    QGraphicsScene *_scene;
    std::vector<Scene::ICard *> _cards;
    ModelController *_modelController;
    Theme _theme;
    QGraphicsItem *_hitButton;
    QGraphicsItem *_standButton;
    QGraphicsItem *_dib;
    QGraphicsItem *_dibLabel;
    QGraphicsItem *_player;
    QGraphicsItem *_dealer;
};
