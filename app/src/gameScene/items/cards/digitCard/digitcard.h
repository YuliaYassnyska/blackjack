#pragma once

#include <items/cards/icard.h>

#include <QGraphicsItem>

class QPaintEvent;

class DigitCard : public ICard, public QGraphicsItem
{
public:
    DigitCard(const QString &text, const QString &imageFrontPath, const QString &imageBackPath);

    QRectF boundingRect() const override;

    void open() override;
    void close() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
               QWidget *widget = nullptr) override;

private:
    QString _text;
    QString _imageFrontPath;
    QString _imageBackPath;
    bool _isOpen{ false };

    void paintFrontSide(QPainter *painter, const QRect &borderRect, int cornerRadius);

    void paintBackSide(QPainter *painter, const QRect &borderRect, int cornerRadius);
};
