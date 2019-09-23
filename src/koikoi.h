#ifndef KOIKOI_H
#define KOIKOI_H

#include "deck.h"
#include "hand.h"
#include "yaku.h"
#include "player.h"
#include <vector>
#include <QMainWindow>
#include <QPushButton>

// The game consists of these yaku
const static std::vector<Yaku> acceptableYaku
{
    Yaku(1, "Kasu (Plains)", "10 Plain cards. 1 point. Each Additional 1P after."),
            Yaku(1, "Bake-Fuda (Wild Card)", "The animal card of Chrysanthemum can be regarded as a plain card as well. If you have this, 9 plain cards and this card will be the Yaku of Kasu."),
            Yaku(4, "Tsuki-fuda (Monthly Cards)", "All four cards in one group shown right on screen. 4 points."),
            Yaku(6, "Oya-Ken (Dealer's Privilege)", "If neither gets any Yaku, Dealer wins 6 points."),
            Yaku(1, "Tane (Animals)", "5 Animals. 1 point. Each Additional 1P after."),
            Yaku(5, "Ino-Shika-Cho (Boar-Deer-Butterflies)", "Animal cards of Clover, Maple, Peony. 5 points."),
            Yaku(1, "Tanzaku (Ribbons)", "5 Ribbons. 1 point. Each Additional 1P after."),
            Yaku(5, "Akatan (Red Poetry Ribbons)", "All 3 red poetry ribbons. 5 points."),
            Yaku(5, "Aotan (Blue Ribbons)", "All 3 blue ribbons. 5 points."),
            Yaku(10, "Akatan Aotan No Chofuku (3 Red Poetry Ribbons and 3 Blue Ribbons)", "3 Red Poetry Ribbons and 3 Blue Ribbons. 10 points."),
            Yaku(5, "Tsukimi De Ippai (Moon and Sake Cup)", "Moon and Sake Cup cards. 5 points."),
            Yaku(5, "Hanami De Ippai (Curtain and Sake Cup)", "Curtain and Sake Cup cards. 5 points."),
            Yaku(5, "Sanko (3 Brights)", "3 Bright cards not containing Rain man card. 5 points."),
            Yaku(7, "Ame-Shiko (4 Brights, Rain man)", "4Brights containing Rain man card. 7 points."),
            Yaku(8, "Shiko (4 Brights)", "4 Bright cards not containing Rain man card. 8 points."),
            Yaku(10, "Goko (5 Brights)", "All 5 Bright cards. 10 points.")
};

namespace Ui {

/*
* Class Definition, also functions as forward declaration
*/
class KoiKoi;

//Create deck
//Shuffle deck
//Create players
//Deal deck and create gameboard/hand and players' hands
//Set scores to 30 each
//Set rounds to 12
//Set current round to 0
//Set game over to false
//Loop while switching turns
//Implement each turn
//Tally points
//Wait for quit or game over to be true

}

/*
* Class Definition, also functions as forward declaration
*/
class KoiKoi : public QMainWindow
{
    Q_OBJECT

private:
    /*
    * Member Initialization List
    */
    Ui::KoiKoi *ui;
    Deck m_gameDeck {Deck()};
    Player m_player1 {Player()};
    Player m_player2 {Player()};
    Hand m_gameHand {Hand()};
    Hand m_oyaHand {Hand()};
    int m_rounds {12};
    int m_currentRound {0};
    bool m_gameStatus {false};

    QVector<QPushButton*> guiPlayerCards {};
    QVector<QPushButton*> guiCPUCards {};
    QVector<QPushButton*> guiGameHandCards {};

    QVector<QLabel*> guiPlayerLightYaku {};
    QVector<QLabel*> guiPlayerAnimalYaku {};
    QVector<QLabel*> guiPlayerRibbonYaku {};
    QVector<QLabel*> guiPlayerPlainYaku {};

    QVector<QLabel*> guiCPULightYaku {};
    QVector<QLabel*> guiCPUAnimalYaku {};
    QVector<QLabel*> guiCPURibbonYaku {};
    QVector<QLabel*> guiCPUPlainYaku {};

public:
    /*
    * Constructors / Destructors
    */
    explicit KoiKoi(QWidget *parent = nullptr);
    ~KoiKoi();

    /*
    * Get Functions
    */
    Deck* getDeck();
    Player* getPlayer(int playerNum);
    Hand* getGameHand();
    int getNumRounds();
    int getCurrentRound();
    bool getGameStatus();

    /*
    * Set Functions
    */
    void startGame();
    void generateOyaCard();
    void deal();
    void startRound();
    void tallyPoints(); //??  Player currentPlayer, Player nextPlayer

    /*
    * Print Functions
    */
    void printNumRounds();
    void printCurrentRound();
    void printGameStatus();

    /*
    * GUI Functions
    */
    void showTitleScreen();
    void showGameScreen();
    void showOyaScreen();
    void updateCards();
    void updateYaku();
    void checkGameHand();
    void connectDeck();
    void connectGameHand(QPushButton *button);
    void connectGameHand();
    void connectPlayerHand(QPushButton *button);
    void connectPlayerHand();
    void disconnectDeck();
    void disconnectGameHand(QPushButton *button);
    void disconnectGameHand();
    void disconnectPlayerHand(QPushButton *button);
    void disconnectPlayerHand();

public slots:
    void onNewGameClicked();
    void onQuitGameClicked();
    void onPreferencesClicked();
    void onAboutClicked();
    void determineOyaPlayer();
    void selectFromHand();
    void selectFromGameHand();
    //void drawCard(Player &currentPlayer, int &currentTurn);
    void drawCard();
};

#endif // KOIKOI_H
