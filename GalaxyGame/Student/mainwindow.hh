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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public std::enable_shared_from_this<MainWindow>
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    player_ship *ship_;
    QTimer *frameTimer_;
    GameProperties *props_;
    Student::Statistics *stats_;

private slots:
    void followShip();
    void checkCollision();
    void tick();
};

#endif // MAINWINDOW_HH
