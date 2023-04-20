#include "cardanimator.h"
#include "items/players/iplayer.h"

#include <QGraphicsItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

namespace Scene
{
CardAnimator::CardAnimator(QObject *parent)
    : _timer{ new QTimeLine(500, parent) }, _animation{ new QGraphicsItemAnimation(parent) }
{
    _animation->setTimeLine(_timer);
    _timer->setFrameRange(0, 1000);

    connect(_timer, &QTimeLine::finished, this, &CardAnimator::onTimerFinished);
}

void CardAnimator::moveToPlayer(Scene::IPlayer *player)
{
    _player = player;

    _animation->setPosAt(1 / 2.0, _player->cardStart());

    _timer->start();
}

void CardAnimator::setCard(QGraphicsItem *card)
{
    _animation->setItem(card);
}

bool CardAnimator::isRunning()
{
    return _timer->state() == QTimeLine::Running;
}

void CardAnimator::onTimerFinished()
{
    emit animated(_animation->item(), _player);
}
} // namespace Scene
