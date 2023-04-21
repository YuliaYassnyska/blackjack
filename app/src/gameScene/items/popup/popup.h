#pragma once

#include <QGraphicsItem>
#include <QString>

namespace Scene
{
class Popup : public QGraphicsItem
{
public:
    Popup(std::function<void(void)> callback, const QString &imagePath);

    QRectF boundingRect() const override;

    void updateText(QString text);
    void setupContent();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QString _text;
    QGraphicsItem *_restartButton;
};
} // namespace Scene
