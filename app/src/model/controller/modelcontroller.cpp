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
        _players.push_back(new Model::Player(id++, 100));
}

void ModelController::addCardForPlayer(unsigned playerId, unsigned cardId, bool isOpen)
{
    auto *player{ playerById(playerId) };
    auto *card{ cardById(cardId) };
    card->setOpen(isOpen);

    player->addCard(card);

    checkLoser(player);
}

void ModelController::checkLoser(Model::IPlayer *player)
{
    if (player->score() > 21)
    {
        player->lose();

        for (auto *el : _players)
        {
            if (el->id() != player->id())
            {
                el->win();
            }
        }

        emit roundEnd();
    }
}

void ModelController::clearPlayerCards()
{
    for (auto *player : _players)
    {
        player->clearCards();
    }
}

void ModelController::setCardOpen(unsigned cardId, bool isOpen)
{
    auto *card{ cardById(cardId) };
    card->setOpen(isOpen);
}

void ModelController::summaryResults(unsigned playerId)
{

    auto dealer{ playerById(playerId) };

    for (auto *player : _players)
    {
        if (player != dealer)
        {
            int playerScore{ player->score() };
            int dealerScore{ dealer->score() };
            if (playerScore < dealerScore)
                player->lose();
            else
                player->win();
        }
    }

    emit roundEnd();
}

Model::IPlayer *ModelController::playerById(unsigned playerId) const
{
    auto playerIt
        = std::find_if(_players.cbegin(), _players.cend(),
                       [playerId](Model::IPlayer *player) { return player->id() == playerId; });

    if (playerIt != _players.cend())
        return *playerIt;

    return nullptr;
}

Model::ICard *ModelController::cardById(unsigned cardId) const
{
    auto cardIt = std::find_if(_cards.cbegin(), _cards.cend(),
                               [cardId](Model::ICard *card) { return card->id() == cardId; });

    if (cardIt != _cards.cend())
        return *cardIt;

    return nullptr;
}
