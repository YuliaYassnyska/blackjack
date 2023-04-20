#pragma once

#include "model/items/cardItem/icard.h"
#include "model/items/players/iplayer.h"
#include <vector>

namespace Model
{
class Player : public IPlayer
{
public:
    Player(unsigned id);

    int score() override;
    void addCard(ICard *card) override;
    bool isAceWithСourtiers() override;
    unsigned id() const override;
    bool isLoser() const override;
    void lose() override;
    void clearCards() override;

private:
    std::vector<ICard *> _cards;
    unsigned _id;
    bool _isLoser{ false };
};
} // namespace Model
