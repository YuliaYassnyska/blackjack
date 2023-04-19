#pragma once

#include "items/cardItem/icard.h"

class QGraphicsItem;

namespace Scene
{
class IPlayer
{
public:
    virtual void updateCardsPos() = 0;
    virtual void addCard(QGraphicsItem *card) = 0;
    virtual unsigned modelId() const = 0;
    virtual void init() = 0;
    virtual void setupPointLabel() = 0;
    virtual void updatePointLabel() = 0;
};
} // namespace Scene
