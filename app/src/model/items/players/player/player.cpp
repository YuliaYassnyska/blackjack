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
        if (card->isOpen())
        {
            if (card->card() == Card::Ace && isAceWithСourtiers())
                score += 11;
            else
                score += card->value();
        }
    }
    return score;
}

void Player::addCard(ICard *card)
{
    _cards.push_back(card);
}

bool Player::isAceWithСourtiers()
{
    if (std::find_if(_cards.begin(), _cards.end(),
                     [](ICard *card) {
                         return card->card() == Card::Jack || card->card() == Card::Queen
                                || card->card() == Card::King;
                     })
        != _cards.end())
        return true;
    else
        return false;
}

unsigned Player::id() const
{
    return _id;
}
} // namespace Model
