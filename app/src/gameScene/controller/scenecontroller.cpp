#include "scenecontroller.h"
#include "items/cardItem/icard.h"
#include "items/factory/cardfactory.h"
#include "model/controller/modelcontroller.h"

#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>

SceneController::SceneController(QGraphicsScene *scene, ModelController *modelController,
                                 Theme theme)
    : _modelController{ modelController }, _theme{ theme }, _scene{ scene }
{
    createCards();
    makeDeck();
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

        _scene->addItem(item);
        item->setPos(deckPos);
        moveMargin += 0.1;
    }
}
