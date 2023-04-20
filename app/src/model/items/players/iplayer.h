#pragma once

namespace Model
{
class ICard;

class IPlayer
{
public:
    virtual int score() = 0;
    virtual void addCard(ICard *card) = 0;
    virtual unsigned id() const = 0;
    virtual bool isAceWithСourtiers() = 0;
    virtual bool isLoser() const = 0;
    virtual void lose() = 0;
    virtual void clearCards() = 0;
};
} // namespace Model
