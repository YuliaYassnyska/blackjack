#pragma once

#include <QGraphicsItem>

namespace Scene
{
class DibItem : public QGraphicsItem
{
public:
    DibItem(const QString &imagePath);

    QRectF boundingRect() const override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
               QWidget *widget = nullptr) override;

private:
    QPixmap _image;
};
} // namespace Scene
