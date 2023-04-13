#include "cardenums.h"

#include <QString>

QString getSuitPath(Suit suit)
{
    switch (suit)
    {
    case Suit::Clubs:
        return QStringLiteral("clubs");
    case Suit::Diamonds:
        return QStringLiteral("diamonds");
    case Suit::Hearts:
        return QStringLiteral("hearts");
    case Suit::Spades:
        return QStringLiteral("spades");
    }

    return QLatin1String();
}

QString getModePath(Mode mode)
{
    switch(mode)
    {
    case Mode::Dark:
        return QStringLiteral("lightMode");
    case Mode::Light:
        return QStringLiteral("darkMode");
    }

    return QLatin1String();
}

QString getCardPath(Card card)
{
    switch(card)
    {
    case Card::Ace:
        return QStringLiteral("ace.png");
    case Card::Two:
        return QStringLiteral("two.png");
    case Card::Three:
        return QStringLiteral("three.png");
    case Card::Four:
        return QStringLiteral("four.png");
    case Card::Five:
        return QStringLiteral("five.png");
    case Card::Six:
        return QStringLiteral("six.png");
    case Card::Seven:
        return QStringLiteral("seven.png");
    case Card::Eignt:
        return QStringLiteral("eight.png");
    case Card::Nine:
        return QStringLiteral("nine.png");
    case Card::Ten:
        return QStringLiteral("ten.png");
    case Card::Jack:
        return QStringLiteral("jack.png");
    case Card::Queen:
        return QStringLiteral("queen.png");
    case Card::King:
        return QStringLiteral("king.png");
    }

    return QLatin1String();
}
