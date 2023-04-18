#pragma once

#include "model/items/cardItem/icard.h"
#include "model/items/players/iplayer.h"
#include <vector>

namespace Model
{
class Player : public IPlayer
{
public:
    Player();

    int score() override;
    void addCard(ICard *card) override;

private:
    std::vector<ICard *> _cards;
};
} // namespace Model
