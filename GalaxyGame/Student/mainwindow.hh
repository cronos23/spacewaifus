#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QObject>
#include <QPixmap>
#include <QTimer>
#include <QTransform>
#include <vector>
#include "eventhandler.hh"
#include "galaxy.hh"
#include "gamerunner.hh"
#include "graphicsviewcontrols.hh"
#include "igamerunner.hh"
#include "initialize.hh"
#include "mainwindowutility.hh"
#include "player_ship.hh"
#include "starsystemobject.hh"
#include "utility.hh"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    player_ship *ship_;
    QTimer *frameTimer_;
    std::shared_ptr<Common::IEventHandler> handler;
    std::shared_ptr<Student::Galaxy> galaxy;
    std::shared_ptr<Common::IGameRunner> gameRunner;

private slots:
    void followShip();
    void checkCollision();
    void renderFrame();
};

#endif // MAINWINDOW_HH
