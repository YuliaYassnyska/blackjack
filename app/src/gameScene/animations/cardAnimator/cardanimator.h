#pragma once

#include <QObject>

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
    explicit CardAnimator(QObject *parent);

    void moveToPlayer(Scene::IPlayer *player);
    void setCard(QGraphicsItem *card);

    bool isRunning();

signals:
    void animated(QGraphicsItem *card, Scene::IPlayer *player);

private:
    void onTimerFinished();

    QTimeLine *_timer{ nullptr };
    Scene::IPlayer *_player{ nullptr };
    QGraphicsItemAnimation *_animation{ nullptr };
};
} // namespace Scene
