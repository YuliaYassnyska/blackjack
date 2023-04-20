#pragma once

#include <QGraphicsItem>

namespace Scene
{
class IPlayer;

class CashLabel : public QGraphicsItem
{
public:
    CashLabel(IPlayer *player);

    QRectF boundingRect() const override;

    void updateContent();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int _cash;
    int _bet;
    IPlayer *_player;
};
} // namespace Scene
