#pragma once

#include "items/labels/ilabel.h"

#include <QGraphicsItem>

namespace Scene
{
class PointLabel : public ILabel, public QGraphicsItem
{
public:
    PointLabel(int value);

    void updateText(int value) override;

    QRectF boundingRect() const override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
               QWidget *widget = nullptr) override;

private:
    int _value;
};
} // namespace Scene
