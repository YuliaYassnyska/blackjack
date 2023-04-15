#pragma once

#include "enums/cardEnums/cardenums.h"
#include <vector>

namespace Scene
{
class ICard;
}

class ModelController;

class SceneController
{
public:
    SceneController(ModelController *modelController, Theme theme);
    std::vector<Scene::ICard *> cards();

private:
    void createCards();

    std::vector<Scene::ICard *> _cards;
    ModelController *_modelController;
    Theme _theme;
};
