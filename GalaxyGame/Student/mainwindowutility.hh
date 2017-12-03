#ifndef MAINWINDOWUTILITY_HH
#define MAINWINDOWUTILITY_HH

#include <assert.h>
#include <QGraphicsScene>
#include <QTimer>
#include <sstream>
#include "galaxy.hh"
#include "player_ship.hh"
#include "starsystemobject.hh"

/**
 * @brief Provides utility functions to mainWindow and encounter. Setups the player_ship
 * graphical object and mainWindows timers. Also creates a graphicsScene and populates it
 * with starsystemobjects using data from Galaxy.
 */
class MainWindowUtility
{
public:
    MainWindowUtility();
    /**
     * @brief Creates a graphicsScene and populates it with starsystemobjects. The objects
     * are constructed using data from Galaxy. Their size is set according to their population
     * and their position in the scene is calculated from their coordinates in galaxy.
     * @param Galaxy is used to get data on all star systems read from config files.
     * @return Returns the created QGraphicsScene to MainWindow.
     * @post Exception guarantee: nothrow
     */
    QGraphicsScene *createGalaxies(std::shared_ptr<Student::Galaxy> galaxy);
    /**
     * @brief Takes a reference to ship_ from mainWindow and sets all it's parameters.
     * @param Reference to ship_ from mainWindow.
     * @post ship has all parameters set correctly and is ready to be used by mainWindow.
     */
    void setupShip(player_ship &ship);
    /**
     * @brief Utility function that derives a star systems waifu type from its ECONOMY_TYPE.
     * @param Takes a Common::StarSystem::ECONOMY_TYPE enum as a parameter.
     * @return Returns a string naming the correct waifu type for the econ_type parameter.
     */
    std::string getWaifuType(Common::StarSystem::ECONOMY_TYPE econ_type);
    /**
     * @brief Uses references to mainWindows timers to set their intervals correctly.
     * @param frametimer is set to an interval that locks the framerate to 62,5 fps.
     * @param actiontimer
     * @param gametimer
     */
    void setupTimers(QTimer &frametimer, QTimer &actiontimer, QTimer &gametimer);
private:
    /**
     * @invariant FRAME_INTERVAL is set to 16 milliseconds to achieve a smooth 62,5 fps.
     */
    static int const FRAME_INTERVAL = 16;
};

#endif // MAINWINDOWUTILITY_HH
