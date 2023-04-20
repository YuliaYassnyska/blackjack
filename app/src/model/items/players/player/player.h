#pragma once

#include "model/items/cardItem/icard.h"
#include "model/items/players/iplayer.h"
#include <vector>

namespace Model
{
class Player : public IPlayer
{
public:
    Player(unsigned id, int cash);

    int score() override;
    void addCard(ICard *card) override;
    bool isAceWithCourtiers() override;
    unsigned id() const override;
    bool isLoser() const override;
    void lose() override;
    void win() override;
    void clearCards() override;
    int cash() const override;
    int bet() const override;

private:
    std::vector<ICard *> _cards;
    unsigned _id;
    bool _isLoser{ false };
    int _cash{ 0 };
    int _bet{ 5 };
};
} // namespace Model
