#pragma once

#include <items/cards/icard.h>

#include <QGraphicsItem>

class QPaintEvent;

class DigitCard : public ICard, public QGraphicsItem
{
public:
    DigitCard(const QString &text, const QString &imagePath);

    QRectF boundingRect() const override;

    void open() override;
    void clode() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
               QWidget *widget = nullptr) override;

private:
    QString _text;
    QString _imagePath;
};
