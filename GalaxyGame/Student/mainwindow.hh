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
#include "gameproperties.hh"
#include "gamerunner.hh"
#include "graphicsviewcontrols.hh"
#include "igamerunner.hh"
#include "initialize.hh"
#include "mainwindowutility.hh"
#include "player_ship.hh"
#include "starsystemobject.hh"
#include "utility.hh"
#include "statistics.hh"
#include "game_over.hh"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public std::enable_shared_from_this<MainWindow>
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void startTimers();
private:
    Ui::MainWindow *ui;
    player_ship *ship_;
    QTimer *actionTimer_;
    QTimer *frameTimer_;
    QTimer *gameTimer_;
    GameProperties *props_;
    Student::Statistics *stats_;

private slots:
    void reactToDistress(std::shared_ptr<Common::Ship> ship);
    void followShip();
    void checkCollision();
    void tick();
    void GameOver();
};

#endif // MAINWINDOW_HH
