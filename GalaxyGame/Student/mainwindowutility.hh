#ifndef MAINWINDOWUTILITY_HH
#define MAINWINDOWUTILITY_HH

#include <QGraphicsScene>
#include "galaxy.hh"
#include "player_ship.hh"
#include "starsystemobject.hh"


class MainWindowUtility
{
public:
    MainWindowUtility();

    QGraphicsScene *createGalaxies(std::shared_ptr<Student::Galaxy> galaxy);
    void setupShip(player_ship &ship);
};

#endif // MAINWINDOWUTILITY_HH
