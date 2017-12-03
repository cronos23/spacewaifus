#ifndef MAINWINDOWUTILITY_HH
#define MAINWINDOWUTILITY_HH

#include <sstream>
#include <QGraphicsScene>
#include <QTimer>
#include "galaxy.hh"
#include "player_ship.hh"
#include "starsystemobject.hh"


class MainWindowUtility
{
public:
    MainWindowUtility();

    QGraphicsScene *createGalaxies(std::shared_ptr<Student::Galaxy> galaxy);
    void setupShip(player_ship &ship);
    std::string getWaifuType(Common::StarSystem::ECONOMY_TYPE econ_type);
    void setupTimers(QTimer &frametimer, QTimer &actiontimer, QTimer &gametimer);
private:
};

#endif // MAINWINDOWUTILITY_HH
