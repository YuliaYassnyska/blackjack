#pragma once

#include "items/players/player/player.h"

#include <QGraphicsItem>

namespace Model
{
class IPlayer;
}

namespace Scene
{
class PointLabel;

class Dealer : public Player
{
public:
    Dealer(Model::IPlayer *modelDealer);

    void updateCards() override;
    void init() override;

    int showClosedCard();
    int currentScore();

private:
    Model::IPlayer *_modelDealer;
};
} // namespace Scene
