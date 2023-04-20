#pragma once

#include "items/players/iplayer.h"

#include <QGraphicsItem>

namespace Model
{
class IPlayer;
}

namespace Scene
{
class PointLabel;

class Dealer : public IPlayer, public QGraphicsItem
{
public:
    Dealer(Model::IPlayer *modelDealer);

    QRectF boundingRect() const override;

    void updateCards() override;
    void addCard(QGraphicsItem *card) override;
    unsigned modelId() const override;
    void init() override;
    void setupPointLabel() override;
    void updatePointLabel() override;
    Result result() const override;
    QPointF cardStart() override;
    void clearCards() override;
    int cardsSize() const override;

    int showClosedCard();
    int currentScore();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    std::vector<QGraphicsItem *> _cards;
    Model::IPlayer *_modelDealer;
    PointLabel *_pointLabel;
    QPointF _cardStart;
};
} // namespace Scene
