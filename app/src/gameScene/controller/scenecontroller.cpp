#include "scenecontroller.h"
#include "items/factory/cardfactory.h"
#include "model/controller/modelcontroller.h"

SceneController::SceneController(ModelController *modelController, Theme theme)
    : _modelController{ modelController }, _theme{ theme }
{
    createCards();
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
