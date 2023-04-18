#include "modelcontroller.h"
#include "enums/cardEnums/cardenums.h"
#include "model/items/cardItem/carditem.h"
#include "model/items/players/player/player.h"

ModelController::ModelController()
{
    createCards();
    createPlayers();
}

std::vector<Model::ICard *> ModelController::cards()
{
    return _cards;
}

std::vector<Model::IPlayer *> ModelController::players()
{
    return _players;
}

void ModelController::createCards()
{
    unsigned id{ 0 };
    for (unsigned suit = static_cast<unsigned>(Suit::MIN_VALUE);
         suit <= static_cast<unsigned>(Suit::MAX_VALUE); ++suit)
    {
        for (unsigned card = static_cast<unsigned>(Card::MIN_VALUE);
             card <= static_cast<unsigned>(Card::MAX_VALUE); ++card)
        {
            _cards.push_back(new Model::CardItem(Suit(suit), Card(card), id++));
        }
    }
}

void ModelController::createPlayers()
{
    unsigned id{ 0 };
    while (id < 2)
        _players.push_back(new Model::Player(id++));
}
