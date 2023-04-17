#pragma once

#include "items/labels/ilabel.h"

#include <QGraphicsItem>

namespace Scene
{
class BetLabel : public ILabel, public QGraphicsItem
{
public:
    BetLabel(int value);

    void updateText(int value) override;

    QRectF boundingRect() const override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
               QWidget *widget = nullptr) override;

private:
    int _value;
};
} // namespace Scene
