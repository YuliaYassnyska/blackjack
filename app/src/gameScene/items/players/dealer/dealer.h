#pragma once

#include "items/players/iplayer.h"

#include <QGraphicsItem>

namespace Scene
{
class Dealer : public IPlayer, public QGraphicsItem
{
public:
    Dealer();

    QRectF boundingRect() const override;

    void updateCardsPos() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
};
} // namespace Scene
