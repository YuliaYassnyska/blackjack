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

    void updateCardsPos() override;
    void addCard(QGraphicsItem *card) override;
    unsigned modelId() const override;
    void init() override;
    void setupPointLabel() override;
    void updatePointLabel() override;
    QPointF cardStart() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    std::vector<QGraphicsItem *> _cards;
    Model::IPlayer *_modelPlayer;
    PointLabel *_pointLabel;
    QPointF _cardStart;
};
} // namespace Scene
