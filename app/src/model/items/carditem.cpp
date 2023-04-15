#include "carditem.h"
#include "enums/cardEnums/cardenums.h"

namespace Model
{
CardItem::CardItem(Suit suit, Card card) : _suit{ suit }, _card{ card }
{
}

int CardItem::value()
{
    return getCardValue(_card);
}

Suit CardItem::suit()
{
    return _suit;
}

Card CardItem::card()
{
    return _card;
}
} // namespace Model
