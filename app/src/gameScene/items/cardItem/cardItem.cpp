#include "items/cardItem/cardItem.h"

#include <QPainter>

CardItem::CardItem(const QString &imageFrontPath, const QString &imageBackPath)
    : QGraphicsItem(),
      _imageFront{ QPixmap{ imageFrontPath }.scaled(boundingRect().size().toSize()) },
      _imageBack{ QPixmap{ imageBackPath }.scaled(boundingRect().size().toSize()) }
{
}

void CardItem::paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
                     QWidget * /*widget*/)
{

    const int penWidth{ 1 };
    const int cornerRadius{ 10 };
    QRect rect{ boundingRect().toRect() };
    QRect borderRect{ QRect{ rect.x() + penWidth, rect.y() + penWidth, rect.width() - penWidth * 2,
                             rect.height() - penWidth * 2 } };

    if (_isOpen)
        paintFrontSide(painter, borderRect, cornerRadius);
    else
        paintBackSide(painter, borderRect, cornerRadius);
}

void CardItem::paintFrontSide(QPainter *painter, const QRect &borderRect, int cornerRadius)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(_imageFront);
    painter->drawRoundedRect(boundingRect().toRect(), 10, 10);
}

void CardItem::paintBackSide(QPainter *painter, const QRect &borderRect, int cornerRadius)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(_imageBack);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);
}

QRectF CardItem::boundingRect() const
{
    return QRectF(0, 0, 120, 180);
}

void CardItem::open()
{
    _isOpen = true;
}

void CardItem::close()
{
    _isOpen = false;
}
