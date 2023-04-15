#pragma once

#include <QString>

enum class Suit : unsigned
{
    MIN_VALUE,
    Clubs = MIN_VALUE,
    Diamonds,
    Hearts,
    Spades,
    MAX_VALUE = Spades,

};

enum class Theme : unsigned
{
    MIN_VALUE,
    Light = MIN_VALUE,
    Dark,
    MAX_VALUE = Dark
};

enum class Card : unsigned
{
    MIN_VALUE,
    Ace = MIN_VALUE,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eignt,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    MAX_VALUE = King
};

int getCardValue(Card card);
QString getCardPath(Card card);
QString getThemePath(Theme theme);
QString getSuitPath(Suit suit);
