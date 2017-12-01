#ifndef GAMEPROPERTIES_HH
#define GAMEPROPERTIES_HH

#include "eventhandler.hh"
#include "galaxy.hh"
#include "gamerunner.hh"
#include "igamerunner.hh"
#include "initialize.hh"



class GameProperties
{
public:
    GameProperties();
    void setProperties();
    std::shared_ptr<Common::IEventHandler> getHandler();
    std::shared_ptr<Student::Galaxy> getGalaxy();
    std::shared_ptr<Common::IGameRunner> getRunner();
    void tick();
private:
    std::shared_ptr<Common::IEventHandler> handler_;
    std::shared_ptr<Student::Galaxy> galaxy_;
    std::shared_ptr<Common::IGameRunner> gameRunner_;
};

#endif // GAMEPROPERTIES_HH
