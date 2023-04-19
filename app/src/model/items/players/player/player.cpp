#include "player.h"

namespace Model
{
Player::Player(unsigned id) : _id{ id }
{
}

int Player::score()
{
    int score{ 0 };
    for (auto *card : _cards)
    {
        score += card->value();
    }
    return score;
}

void Player::addCard(ICard *card)
{
    _cards.push_back(card);
}

unsigned Player::id() const
{
    return _id;
}
} // namespace Model
