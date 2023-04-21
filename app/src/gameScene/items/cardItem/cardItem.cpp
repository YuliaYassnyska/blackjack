#include "items/cardItem/cardItem.h"

#include <QPainter>

namespace Scene
{
CardItem::CardItem(const QString &themePath, const QString &imageFrontPath,
                   const QString &imageBackPath, unsigned modelId)
    : QGraphicsItem(),
      _imageFront{ QPixmap{ themePath + imageFrontPath }.scaled(boundingRect().size().toSize()) },
      _imageBack{ QPixmap{ themePath + imageBackPath }.scaled(boundingRect().size().toSize()) },
      _modelId{ modelId },
      _imageFrontPath{ imageFrontPath },
      _imageBackPath{ imageBackPath }
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

    painter->setPen(Qt::white);

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
    update();
}

void CardItem::close()
{
    _isOpen = false;
    update();
}

void CardItem::setPos(double x, double y)
{
    setPos(x, y);
}

unsigned CardItem::modelId() const
{
    return _modelId;
}

bool CardItem::isOpen() const
{
    return _isOpen;
}

void CardItem::updateTheme(QString theme)
{
    _imageFront = QPixmap{ theme + _imageFrontPath }.scaled(boundingRect().size().toSize());
    _imageBack = QPixmap{ theme + _imageBackPath }.scaled(boundingRect().size().toSize());
    update();
}
} // namespace Scene
