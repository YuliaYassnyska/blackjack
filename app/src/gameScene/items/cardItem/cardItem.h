#pragma once

#include <items/cardItem/icard.h>

#include <QGraphicsItem>

class QPaintEvent;

namespace Scene
{
class CardItem : public ICard, public QGraphicsItem
{
public:
    CardItem(const QString &themePath, const QString &imageFrontPath, const QString &imageBackPath);

    QRectF boundingRect() const override;

    void open() override;
    void close() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
               QWidget *widget = nullptr) override;

private:
    QPixmap _imageFront;
    QPixmap _imageBack;
    bool _isOpen{ true };

    void paintFrontSide(QPainter *painter, const QRect &borderRect, int cornerRadius);

    void paintBackSide(QPainter *painter, const QRect &borderRect, int cornerRadius);
};
} // namespace Scene
