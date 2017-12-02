#ifndef GAMEPROPERTIES_HH
#define GAMEPROPERTIES_HH

#include "eventhandler.hh"
#include "galaxy.hh"
#include "gamerunner.hh"
#include "igamerunner.hh"
#include "initialize.hh"



class GameProperties: public QObject
{
    Q_OBJECT
public:
    GameProperties();
    void setProperties();
    Student::EventHandler *getHandler();
    std::shared_ptr<Student::Galaxy> getGalaxy();
    std::shared_ptr<Common::IGameRunner> getRunner();
public slots:
    void tick();
    void reactToDistress(std::shared_ptr<Common::Ship> ship);
private:
    Student::EventHandler* handler_;
    std::shared_ptr<Student::Galaxy> galaxy_;
    std::shared_ptr<Common::IGameRunner> gameRunner_;
};

#endif // GAMEPROPERTIES_HH
