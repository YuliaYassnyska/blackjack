#pragma once

#include <QGraphicsItem>

namespace Scene
{
class ThemeItem : public QGraphicsItem
{
public:
    ThemeItem(const QString &text, std::function<void(void)> callback);

    QRectF boundingRect() const override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QString _text;
    std::function<void(void)> _callback;
};
} // namespace Scene
