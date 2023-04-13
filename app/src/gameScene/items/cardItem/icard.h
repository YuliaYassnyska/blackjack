#pragma once

class ICard
{
public:
    virtual void open() = 0;
    virtual void close() = 0;
};

enum class Suit
{
    Club,
    Diamond,
    Heart,
    Spade
};

#include <QString>
QString getSuitPath(Suit suit)
{
    switch (suit)
    {
    case Suit::Club:
        return QStringLiteral("club");
    case Suit::Diamond:
        return QStringLiteral("diamond");
    case Suit::Heart:
        return QStringLiteral("heart");
    case Suit::Spade:
        return QStringLiteral("spade");
    }
    return QLatin1String();
}
