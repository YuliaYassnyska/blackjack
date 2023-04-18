#pragma once

#include <vector>

namespace Model
{
class ICard;
class IPlayer;
} // namespace Model

class ModelController
{
public:
    ModelController();

    std::vector<Model::ICard *> cards();
    std::vector<Model::IPlayer *> players();

private:
    void createCards();
    void createPlayers();
    void addCardForPlayer(unsigned playerId, unsigned cardId);
    Model::IPlayer *playerById(unsigned playerId) const;
    Model::ICard *cardById(unsigned cardId) const;

    std::vector<Model::ICard *> _cards;
    std::vector<Model::IPlayer *> _players;
};
