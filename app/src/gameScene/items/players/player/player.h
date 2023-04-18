#pragma once
#include "items/cardItem/icard.h"
#include "items/players/iplayer.h"

#include <QGraphicsItem>

namespace Scene
{
class Player : public IPlayer, public QGraphicsItem
{
public:
    Player();

    QRectF boundingRect() const override;

    void updateCardsPos() override;
    void addCard(ICard *card) override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    std::vector<ICard *> _cards;
};
} // namespace Scene
