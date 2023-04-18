#pragma once

#include "items/players/iplayer.h"

#include <QGraphicsItem>

namespace Model
{
class IPlayer;
}

namespace Scene
{
class Dealer : public IPlayer, public QGraphicsItem
{
public:
    Dealer(Model::IPlayer *modelDealer);

    QRectF boundingRect() const override;

    void updateCardsPos() override;
    void addCard(QGraphicsItem *card) override;
    unsigned modelId() const override;
    void init() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    std::vector<QGraphicsItem *> _cards;
    Model::IPlayer *_modelDealer;
};
} // namespace Scene
