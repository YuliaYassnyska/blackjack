#pragma once

#include <QObject>
#include <QPointF>

#include <vector>

class QTimeLine;
class QObject;
class QGraphicsItem;
class QGraphicsItemAnimation;

namespace Scene
{
class IPlayer;

class CardAnimator : public QObject
{
    Q_OBJECT
public:
    CardAnimator(QObject *parent);

    void moveTo(QPointF pos);
    void setCard(QGraphicsItem *card);

    bool isRunning();

signals:
    void animated(QGraphicsItem *card);

private:
    void onTimerFinished();

    QTimeLine *_timer;
    QGraphicsItemAnimation *_animation;
};
} // namespace Scene
