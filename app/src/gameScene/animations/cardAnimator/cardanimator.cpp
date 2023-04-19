#include "cardanimator.h"
#include "items/players/iplayer.h"

#include <QGraphicsItem>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

namespace Scene
{
CardAnimator::CardAnimator(QObject *parent)
    : _timer{ new QTimeLine(1000, parent) }, _animation{ new QGraphicsItemAnimation(parent) }
{
    _animation->setTimeLine(_timer);
    _timer->setFrameRange(0, 100);

    connect(_timer, &QTimeLine::finished, this, &CardAnimator::onTimerFinished);
}

void CardAnimator::moveTo(QPointF pos)
{
    _animation->setPosAt(1 / 2.0, pos);

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
    emit animated(_animation->item());
}
} // namespace Scene
