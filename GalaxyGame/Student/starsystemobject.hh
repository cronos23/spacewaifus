#ifndef STARSYSTEMOBJECT_HH
#define STARSYSTEMOBJECT_HH

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QPainter>
#include <vector>
#include "starsystem.hh"

/**
 * @brief Adds functions to QGraphicsEllipseItem that help it connect with the data
 * in Galaxy.
 */
class starsystemobject: public QObject, public QGraphicsEllipseItem {

public:
    /**
     * @brief Sets a value for starsystemsize_ that depends on the starsystems population
     * data from Galaxy.
     * @pre starsystemptr_ has been set by setStarSystem.
     * @post starsystemsize_ is set to a value.
     */
    void setSizeByPop();
    /**
     * @brief getter for starsystemsize_
     * @return Returns an int that can be used when calling setRect for this starsystemobject.
     */
    int getSize();
    /**
     * @brief Used to set a pointer to starsystemptr_
     * @param Takes a shared pointer to a StarSystem as a parameter.
     */
    void setStarSystem(std::shared_ptr<Common::StarSystem> starSystem);
    /**
     * @brief getter for starsystemptr_
     * @return Returns a shared pointer to a StarSystem.
     * @post starsystemptr_ is set to a value.
     */
    std::shared_ptr<Common::StarSystem> getStarSystem();
private:
    /**
     * @brief Used to set the size of the graphicsItem with setRect.
     */
    int starsystemsize_;
    /**
     * @brief Saves a pointer to the starsystem which the object is a graphical representation
     * of.
     */
    std::shared_ptr<Common::StarSystem> starsystemptr_;
};

#endif // STARSYSTEMOBJECT_HH
