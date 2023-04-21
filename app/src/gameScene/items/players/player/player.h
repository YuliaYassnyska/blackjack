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

class Player : public IPlayer, public QGraphicsItem
{
public:
    Player(Model::IPlayer *modelPlayer);

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
    int cash() const override;
    int bet() const override;
    std::vector<QGraphicsItem *> cards() const override;
    void resetCash() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QPointF _cardPoint;

private:
    std::vector<QGraphicsItem *> _cards;
    Model::IPlayer *_modelPlayer;
    PointLabel *_pointLabel;
};
} // namespace Scene
