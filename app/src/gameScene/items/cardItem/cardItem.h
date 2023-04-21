#pragma once

#include <items/cardItem/icard.h>

#include <QGraphicsItem>

class QPaintEvent;

namespace Scene
{
class CardItem : public ICard, public QGraphicsItem
{
public:
    CardItem(const QString &themePath, const QString &imageFrontPath, const QString &imageBackPath,
             unsigned modelId);

    QRectF boundingRect() const override;

    void open() override;
    void close() override;
    void setPos(double x, double y) override;
    unsigned modelId() const override;
    bool isOpen() const override;
    void updateTheme(QString theme) override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/,
               QWidget *widget = nullptr) override;

private:
    QString _imageFrontPath;
    QString _imageBackPath;

    QPixmap _imageFront;
    QPixmap _imageBack;

    bool _isOpen{ false };
    unsigned _modelId;

    void paintFrontSide(QPainter *painter, const QRect &borderRect, int cornerRadius);

    void paintBackSide(QPainter *painter, const QRect &borderRect, int cornerRadius);
};
} // namespace Scene
