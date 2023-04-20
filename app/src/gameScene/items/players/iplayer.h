#pragma once

#include "enums/resultEnums/resultenums.h"
#include "items/cardItem/icard.h"

#include <QPointF>

#include <vector>

class QGraphicsItem;

namespace Scene
{
class IPlayer
{
public:
    virtual void updateCards() = 0;
    virtual void addCard(QGraphicsItem *card) = 0;
    virtual unsigned modelId() const = 0;
    virtual void init() = 0;
    virtual void setupPointLabel() = 0;
    virtual void updatePointLabel() = 0;
    virtual QPointF cardStart() = 0;
    virtual Result result() const = 0;
    virtual void clearCards() = 0;
    virtual int cardsSize() const = 0;
    virtual int cash() const = 0;
    virtual int bet() const = 0;
    virtual std::vector<QGraphicsItem *> cards() const = 0;
};
} // namespace Scene
