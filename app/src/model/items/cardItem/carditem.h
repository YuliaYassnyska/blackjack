#pragma once

#include "enums/cardEnums/cardenums.h"
#include "icard.h"

namespace Model
{
class CardItem : public ICard
{
public:
    CardItem(Suit suit, Card card, unsigned id);

    int value() const override;
    Suit suit() const override;
    Card card() const override;
    unsigned id() const override;
    void setOpen(bool isOpen) override;
    bool isOpen() const override;

private:
    Suit _suit;
    Card _card;
    unsigned _id;
    bool _isOpen{ false };
};

} // namespace Model
