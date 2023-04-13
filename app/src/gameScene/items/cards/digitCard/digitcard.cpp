#include "digitcard.h"

#include <QBitmap>
#include <QPainter>

DigitCard::DigitCard(const QString &text, const QString &imageFrontPath,
                     const QString &imageBackPath)
    : QGraphicsItem(),
      _imageFrontPath{ imageFrontPath },
      _text{ text },
      _imageBackPath{ imageBackPath }
{
}

void DigitCard::paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
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

void DigitCard::paintFrontSide(QPainter *painter, const QRect &borderRect, int cornerRadius)
{

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBackgroundMode(Qt::OpaqueMode);

    painter->setBackground(QBrush(Qt::white));

    QBrush brush{ Qt::white };
    painter->setBrush(brush);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);

    QSize suitSize{ borderRect.size().width() / 2, borderRect.size().height() / 2 };
    QPixmap pixmap{ QPixmap{ _imageFrontPath }.scaled(suitSize) };

    QPointF suitStart{ (boundingRect().width() - suitSize.width()) / 2,
                       (boundingRect().height() - suitSize.height()) / 2 };
    painter->drawPixmap(suitStart, pixmap);

    QSize textSize{ borderRect.size().width() - 18, borderRect.size().height() - 18 };
    QPointF textStart{ (boundingRect().width() - textSize.width()) / 2,
                       (boundingRect().height() - textSize.height()) / 2 };
    QRectF textRect{ textStart, textSize };
    painter->setPen(Qt::black);
    painter->setFont(QFont{ "serif", 18, 60 });
    painter->drawText(textRect, Qt::AlignTop | Qt::AlignLeft, _text);
    textRect.translate(-boundingRect().width(), -boundingRect().height());
    painter->rotate(180);
    painter->drawText(textRect, Qt::AlignTop | Qt::AlignLeft, _text);
}

void DigitCard::paintBackSide(QPainter *painter, const QRect &borderRect, int cornerRadius)
{

    QPixmap pixmap{ QPixmap{ _imageBackPath }.scaled(borderRect.size()) };

    QBrush brush{ pixmap };
    painter->setBrush(brush);
    painter->drawRoundedRect(borderRect, cornerRadius, cornerRadius);
}

QRectF DigitCard::boundingRect() const
{
    return QRectF(0, 0, 120, 180);
}

void DigitCard::open()
{
    _isOpen = true;
}

void DigitCard::close()
{
    _isOpen = false;
}
