#include "player.h"

namespace Model
{
Player::Player(unsigned id, int cash) : _id{ id }, _cash{ cash }
{
}

int Player::score()
{
    int score{ 0 };
    for (auto *card : _cards)
    {
        if (card->isOpen())
        {
            if (card->card() == Card::Ace && isAceWithCourtiers())
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

bool Player::isAceWithCourtiers()
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
    _cash -= _bet;
}

void Player::win()
{
    _isLoser = false;
    _cash += 2 * _bet;
}

void Player::clearCards()
{
    _cards.clear();
    _isLoser = false;
}

int Player::cash() const
{
    return _cash;
}

int Player::bet() const
{
    return _bet;
}

void Player::resetCash()
{
    _cash = 100;
}
} // namespace Model
