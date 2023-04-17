#include "scenecontroller.h"
#include "items/buttonItem/buttonitem.h"
#include "items/cardItem/icard.h"
#include "items/factory/cardfactory.h"
#include "model/controller/modelcontroller.h"

#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>

SceneController::SceneController(QGraphicsScene *scene, ModelController *modelController,
                                 Theme theme)
    : _modelController{ modelController },
      _theme{ theme },
      _scene{ scene },
      _hitButton{ new Scene::ButtonItem(":/images/buttons/resources/hit.png") },
      _standButton(new Scene::ButtonItem(":/images/buttons/resources/stand.png"))
{
    createCards();
    addCardsToScene();
    makeDeck();
    createButtons();
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
