#pragma once

#include "enums/cardEnums/cardenums.h"
#include "icard.h"

namespace Model
{
class CardItem : public ICard
{
public:
    CardItem(Suit suit, Card card);

    int value() override;
    Suit suit() override;
    Card card() override;

private:
    Suit _suit;
    Card _card;
};

} // namespace Model
