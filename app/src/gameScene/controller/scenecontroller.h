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
class Dealer;
class CashLabel;
class Media;
} // namespace Scene
class ModelController;

class QGraphicsScene;
class QGraphicsItem;
class QWidget;
class QTimeLine;

class SceneController : public QObject
{
    Q_OBJECT
public:
    SceneController(QGraphicsScene *scene, ModelController *modelController, Theme theme);
    ~SceneController();

signals:
    void cardAdded(unsigned playerId);
    void addForDealer(Scene::Dealer *dealer);

private:
    void createCards();
    void initDeckPlace();
    void addCardsToScene();
    void makeDeck();
    void shuffleDeck();
    void createButtons();
    void createDib();
    void createPlayers();
    void addCashLabelToScene();
    void createNewGamePopup();
    void createThemeButtons();
    void stand();
    void addCardAfterHit();
    void addCardForPlayer(Scene::IPlayer *player);
    void addPlayersToScene();
    void moveCardAnimation(QGraphicsItem *card, Scene::IPlayer *player);
    void updatePlayerCards(QGraphicsItem *item, Scene::IPlayer *player);
    void connectSignals();
    void summaryResults();
    void startGame();
    void setupPopup();
    void clearPlayersCards();
    void takeCardsOnStart();
    void newGame();

    void onCardAdded();
    void addCardsForDealer(Scene::Dealer *dealer);
    void onAddForDealer(Scene::Dealer *dealer);

    void setupMediaForPopup();

    void setLightTheme();
    void setDarkTheme();

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
    std::vector<Scene::IPlayer *> _players;
    Scene::CardAnimator *_cardAnimator;
    Scene::Popup *_restartPopup;
    Scene::CashLabel *_cashLabel{ nullptr };
    Scene::Popup *_newGamePopup;
    Scene::Media *_media;
    QGraphicsItem *_lightThemeButton;
    QGraphicsItem *_darkThemeButton;

    QTimeLine *_addCardTimer{ nullptr };
};
