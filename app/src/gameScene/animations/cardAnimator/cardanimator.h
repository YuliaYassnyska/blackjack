#pragma once

#include <QPointF>
#include <vector>

class QTimeLine;
class QObject;
class QGraphicsItem;
class QGraphicsItemAnimation;

namespace Scene
{
class IPlayer;

class CardAnimator
{
public:
    CardAnimator(QObject *parent);

    void moveTo(QPointF pos);
    void setCard(QGraphicsItem *card);
    void connectPlayers(std::vector<Scene::IPlayer *> players);

    bool isRunning();

private:
    QTimeLine *_timer;
    QGraphicsItemAnimation *_animation;
};
} // namespace Scene
