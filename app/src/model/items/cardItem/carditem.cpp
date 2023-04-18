#include "carditem.h"
#include "enums/cardEnums/cardenums.h"

namespace Model
{
CardItem::CardItem(Suit suit, Card card, unsigned id) : _suit{ suit }, _card{ card }, _id{ id }
{
}

int CardItem::value() const
{
    return getCardValue(_card);
}

Suit CardItem::suit() const
{
    return _suit;
}

Card CardItem::card() const
{
    return _card;
}

unsigned CardItem::id() const
{
    return _id;
}
} // namespace Model
