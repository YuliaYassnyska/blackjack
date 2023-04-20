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
    const auto it{ std::find_if(_cards.cbegin(), _cards.cend(),
                                [](ICard *card)
                                {
                                    return card->card() == Card::Jack || card->card() == Card::Queen
                                           || card->card() == Card::King;
                                }) };
    return it != _cards.end();
}

unsigned Player::id() const
{
    return _id;
}

bool Player::isLoser() const
{
    return _isLoser;
}

void Player::lose()
{
    _isLoser = true;
}

void Player::clearCards()
{
    _cards.clear();
}
} // namespace Model
