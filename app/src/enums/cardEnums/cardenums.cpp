#include "cardenums.h"

QString getSuitPath(Suit suit)
{
    switch (suit)
    {
    case Suit::Clubs:
        return QStringLiteral("/clubs");
    case Suit::Diamonds:
        return QStringLiteral("/diamonds");
    case Suit::Hearts:
        return QStringLiteral("/hearts");
    case Suit::Spades:
        return QStringLiteral("/spades");
    }

    return QLatin1String();
}

QString getThemePath(Theme theme)
{
    switch (theme)
    {
    case Theme::Light:
        return QStringLiteral("/lightMode");
    case Theme::Dark:
        return QStringLiteral("/darkMode");
    }

    return QLatin1String();
}

QString getCardPath(Card card)
{
    switch (card)
    {
    case Card::Ace:
        return QStringLiteral("/ace.png");
    case Card::Two:
        return QStringLiteral("/two.png");
    case Card::Three:
        return QStringLiteral("/three.png");
    case Card::Four:
        return QStringLiteral("/four.png");
    case Card::Five:
        return QStringLiteral("/five.png");
    case Card::Six:
        return QStringLiteral("/six.png");
    case Card::Seven:
        return QStringLiteral("/seven.png");
    case Card::Eignt:
        return QStringLiteral("/eight.png");
    case Card::Nine:
        return QStringLiteral("/nine.png");
    case Card::Ten:
        return QStringLiteral("/ten.png");
    case Card::Jack:
        return QStringLiteral("/jack.png");
    case Card::Queen:
        return QStringLiteral("/queen.png");
    case Card::King:
        return QStringLiteral("/king.png");
    }

    return QLatin1String();
}

int getCardValue(Card card)
{
    switch (card)
    {
    case Card::Ace:
        return 1;
    case Card::Two:
        return 2;
    case Card::Three:
        return 3;
    case Card::Four:
        return 4;
    case Card::Five:
        return 5;
    case Card::Six:
        return 6;
    case Card::Seven:
        return 7;
    case Card::Eignt:
        return 8;
    case Card::Nine:
        return 9;
    case Card::Ten:
        return 10;
    case Card::Jack:
        return 10;
    case Card::Queen:
        return 10;
    case Card::King:
        return 10;
    }

    return 0;
}
