#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QTransform>
#include <vector>
#include "encounter.hh"
#include "eventhandler.hh"
#include "galaxy.hh"
#include "game_over.hh"
#include "gameproperties.hh"
#include "gamerunner.hh"
#include "graphicsviewcontrols.hh"
#include "igamerunner.hh"
#include "initialize.hh"
#include "mainwindowutility.hh"
#include "player_ship.hh"
#include "starsystemobject.hh"
#include "statistics.hh"
#include "utility.hh"

namespace Ui {
class MainWindow;
}
/**
 * @brief MainWindow is responsible for most of the games functionality. It uses MainWindowUtility to create
 * a graphicsScene and runs the game in it while showing the contents to the player via a graphicsView. The
 * graphicsView is surrounded by a HUD with updating relevant information. This information includes received
 * distress signals, score and credits balances, amount of dated ships and rejections and the players coordinates.
 *
 * MainWindow calls gameProperties to create the galaxy and control NPC ships in it and updates the UI
 * accordingly. After the galaxy has been created, MainWindowUtility is called to draw it's contents on to a scene.
 *
 * MainWindow also connects signals from player_ship and GameProperties to the proper slots,
 * which are used to update different parts of the game. In addition to these connects, MainWindow connects 3
 * QTimers to different slots in itself and GameProperties.
 */
class MainWindow : public QMainWindow, public std::enable_shared_from_this<MainWindow>
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * @brief Starts actiontimer_, frameTimer_ and gameTimer_. Called when mainmenu shows mainwindow and closes.
     */
    void startTimers();
private:
    Ui::MainWindow *ui;
    /**
     * @brief Used to store and update a graphical object that the player can control. Interacts with
     * starsystemobjects via connects.
     */
    player_ship *ship_;
    /**
     * @brief Times NPC actions by connecting to GameProperties::tick
     */
    QTimer *actionTimer_;
    /**
     * @brief Used to achieve a locked frame rate. Connects to updating the graphicsViews viewport, which is
     * the area of graphicsScene a player can currently see on the screen.
     */
    QTimer *frameTimer_;
    /**
     * @brief Used to set a time limit to the game. When gameTimer_ sends it's timeOut signal, the game ends.
     * Also used for updating a countdown timer in the HUD.
     */
    QTimer *gameTimer_;
    /**
     * @brief Used to store the remaining time of gameTimer_ when an encounter is triggered. This time is used
     * when resuming the gameTimer_, as otherwise it would always start from full after an encounter.
     */
    int remaining_time_on_pause_;
    /**
     * @brief Used to create, store and update information about the game.
     */
    GameProperties *props_;
    /**
     * @brief Used to store and update score, credits, dated waifus and rejections.
     */
    Student::Statistics *stats_;
    /**
     * @brief Stops all the 3 timers of the object. Called when encounter is triggered.
     * @pre All 3 timers are running.
     * @post All 3 timers have stopped.
     */
    void stopTimers();

private slots:
    /**
     * @brief Reacts to the distressToggleOn signal from the eventHandler stored in props_.
     * Updates the HUD with details on the distress signals origin.
     * @param The ship parameter is used to get information about the distress signals origin.
     * @post Exception guarantee: nothrow
     */
    void reactToDistress(std::shared_ptr<Common::Ship> ship);
    /**
     * @brief Makes sure the players ship is visible. Also updates the players coordinates in the HUD.
     * Triggers when ship_ receives a keyEvent that moves it.
     * @post Exception guarantee: nothrow
     */
    void followShip();
    /**
     * @brief Triggers when ship_ collides with a starsystemobject. Responsible for checking if there is a
     * ship in the system and reacting accordingly. If a ship is found, the correct preparations are made,
     * after which an encounter is launched. If the star system has no ships, shows a messagebox informing
     * the player of that instead.
     * @post Exception guarantee: nothrow
     */
    void checkCollision();
    /**
     * @brief Updates the viewports contents in set intervals. Also responsible for updating the countdown
     * timer in the HUD.
     * @post Exception guarantee: nothrow
     */
    void tick();
    /**
     * @brief Triggers when gameTimer_ sends a timeOut -signal. Shows a window with relevant information about
     * the past game and if applicable, asks the player to input a name for a high score. Closes the MainWindow.
     * @post Exception guarantee: nothrow
     */
    void GameOver();
};

#endif // MAINWINDOW_HH
