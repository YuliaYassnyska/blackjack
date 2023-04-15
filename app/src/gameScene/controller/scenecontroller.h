#pragma once

#include "enums/cardEnums/cardenums.h"
#include <vector>

namespace Scene
{
class ICard;
}
class ModelController;

class QGraphicsScene;
class QWidget;

class SceneController
{
public:
    SceneController(QGraphicsScene *scene, ModelController *modelController, Theme theme);
    std::vector<Scene::ICard *> cards();

private:
    void createCards();
    void makeDeck();

    QGraphicsScene *_scene;
    std::vector<Scene::ICard *> _cards;
    ModelController *_modelController;
    Theme _theme;
};