#pragma once

#include <QString>

namespace Model
{
class ICard;

class IPlayer
{
public:
    virtual int score() = 0;
    virtual void addCard(ICard *card) = 0;
    virtual unsigned id() const = 0;
    virtual bool isAceWithCourtiers() = 0;
    virtual bool isLoser() const = 0;
    virtual void lose() = 0;
    virtual void clearCards() = 0;
    virtual int cash() const = 0;
    virtual int bet() const = 0;
    virtual void win() = 0;
    virtual void resetCash() = 0;
    virtual QString gameOver() = 0;
};
} // namespace Model
