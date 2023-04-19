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

void CardAnimator::connectPlayers(std::vector<IPlayer *> players)
{
    for (auto *player : players)
    {
        QObject::connect(_timer, &QTimeLine::finished, [player]() { player->updateCardsPos(); });
    }
}

bool CardAnimator::isRunning()
{
    return _timer->state() == QTimeLine::Running;
}
} // namespace Scene
