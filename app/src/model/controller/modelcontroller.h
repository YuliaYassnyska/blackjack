#pragma once

#include <QObject>

#include <vector>

namespace Model
{
class ICard;
class IPlayer;
} // namespace Model

class ModelController : public QObject
{
    Q_OBJECT
public:
    ModelController();

    std::vector<Model::ICard *> cards();
    std::vector<Model::IPlayer *> players();
    void addCardForPlayer(unsigned playerId, unsigned cardId, bool isOpen);
    void checkLoser(Model::IPlayer *player);
    void clearPlayerCards();
    void setCardOpen(unsigned cardId, bool isOpen);

signals:
    void roundEnd();

private:
    void createCards();
    void createPlayers();
    Model::IPlayer *playerById(unsigned playerId) const;
    Model::ICard *cardById(unsigned cardId) const;

    std::vector<Model::ICard *> _cards;
    std::vector<Model::IPlayer *> _players;
};
