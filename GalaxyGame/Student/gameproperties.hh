#ifndef GAMEPROPERTIES_HH
#define GAMEPROPERTIES_HH

#include "eventhandler.hh"
#include "galaxy.hh"
#include "gamerunner.hh"
#include "igamerunner.hh"
#include "initialize.hh"

/**
 * @brief The GameProperties class is responsible for creating, storing and updating
 * the EventHandler, Galaxy and GameRunner used to run the game.
 */

class GameProperties: public QObject
{
    Q_OBJECT
public:
    GameProperties();
    /**
     * @brief Creates an eventHandler, a Galaxy and a gameRunner and stores them in
     * the object as private attributes. Handles exceptions thrown by Galaxy by exiting
     * the application with code 1.
     * @post handler_, galaxy_ and gameRunner_ are created and ready to use.
     */
    void setProperties();
    /**
     * @brief getter for handler_
     * @return returns the eventHandler created by setProperties
     * @pre setProperties has set the private attributes of the object.
     */
    Student::EventHandler *getHandler();
    /**
     * @brief getter for galaxy_
     * @return returns the Galaxy created by setProperties
     * @pre setProperties has set the private attributes of the object.
     */
    std::shared_ptr<Student::Galaxy> getGalaxy();
    /**
     * @brief getter for gameRunner_
     * @return returns the GameRunner created by setProperties
     * @pre setProperties has set the private attributes of the object.
     */
    std::shared_ptr<Common::IGameRunner> getRunner();
public slots:
    /**
     * @brief Responsible for updating NPC ships' actions when called. Meant to be called
     * at set intervals.
     * @pre setProperties has set the private attributes of the object.
     */
    void tick();
private:
    Student::EventHandler* handler_;
    std::shared_ptr<Student::Galaxy> galaxy_;
    std::shared_ptr<Common::IGameRunner> gameRunner_;
};

#endif // GAMEPROPERTIES_HH
