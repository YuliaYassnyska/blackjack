#pragma once

#include "enums/cardEnums/cardenums.h"
#include "items/players/iplayer.h"

#include <QObject>

#include <vector>

namespace Scene
{
class ICard;
class CardAnimator;
class Popup;
} // namespace Scene
class ModelController;

class QGraphicsScene;
class QGraphicsItem;
class QWidget;

class SceneController : public QObject
{
    Q_OBJECT
public:
    SceneController(QGraphicsScene *scene, ModelController *modelController, Theme theme);
    ~SceneController();

    std::vector<Scene::ICard *> cards();

private:
    void createCards();
    void initDeckPlace();
    void addCardsToScene();
    void makeDeck();
    void createButtons();
    void createDib();
    void createPlayers();
    void playersResults();
    void addCardForPlayer();
    void addPlayersToScene();
    void changeTurn();
    void moveCardAnimation(QGraphicsItem *card, Scene::IPlayer *player);
    void updateCurrentPlayerCards(QGraphicsItem *item);
    void connectSignals();
    void summaryResults();
    void startGame();
    void setupPopup();
    void clearPlayersCards();
    void getInitialPlayersMoves();

    QGraphicsScene *_scene;
    std::vector<Scene::ICard *> _cards;
    ModelController *_modelController;
    QGraphicsItem *_deckPlace;
    Theme _theme;
    QGraphicsItem *_hitButton;
    QGraphicsItem *_standButton;
    QGraphicsItem *_dib;
    QGraphicsItem *_dibLabel;
    int _lastCardInDeck{ 0 };
    int _currentPlayerTurn{ 0 };
    std::vector<Scene::IPlayer *> _players;
    Scene::CardAnimator *_cardAnimator;
    Scene::Popup *_restartPopup;
};
