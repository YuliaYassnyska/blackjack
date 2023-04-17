#pragma once

#include <QGraphicsItem>

namespace Scene
{
class ButtonItem : public QGraphicsItem
{
public:
    ButtonItem(const QString &imagePath);

    QRectF boundingRect() const override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
               QWidget *widget = nullptr) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QPixmap _image;
};
} // namespace Scene
