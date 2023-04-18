#pragma once

namespace Model
{
class ICard;

class IPlayer
{
public:
    virtual int score() = 0;
    virtual void addCard(ICard *card) = 0;
};
} // namespace Model
