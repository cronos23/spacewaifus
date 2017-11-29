#ifndef EVENTHANDLER_HH
#define EVENTHANDLER_HH
#include <QObject>
#include "point.hh"
#include "ieventhandler.hh"
#include "galaxy.hh"

namespace Student {
class EventHandler: public QObject, public Common::IEventHandler
{
Q_OBJECT
public:
    EventHandler();
    ~EventHandler();
    void shipSpawned(std::shared_ptr<Common::Ship> ship);
    void shipRemoved(std::shared_ptr<Common::Ship> ship);
    void shipRelocated(std::shared_ptr<Common::Ship> ship,
                       std::shared_ptr<Common::StarSystem> starSystem);
    void shipMoved(std::shared_ptr<Common::Ship> ship,
                   Common::Point origin,
                   Common::Point target);
    void exceptionInExecution(std::shared_ptr<Common::Ship> ship, std::string const& msg);
    void distressOn(std::shared_ptr<Common::Ship> ship);
    void distressOff(std::shared_ptr<Common::Ship> ship);
    void shipAbandoned(std::shared_ptr<Common::Ship> ship);
signals:
    void shipSpawn(std::shared_ptr<Common::Ship> ship);
    void shipRemove(std::shared_ptr<Common::Ship> ship);
    void shipRelocate(std::shared_ptr<Common::Ship> ship,
                       std::shared_ptr<Common::StarSystem> starSystem);
    void shipMove(std::shared_ptr<Common::Ship> ship,
                   Common::Point origin,
                   Common::Point target);
    void ExecutionException(std::shared_ptr<Common::Ship> ship, std::string const& msg);
    void distressToggleOn(std::shared_ptr<Common::Ship> ship);
    void distressToggleOff(std::shared_ptr<Common::Ship> ship);
    void shipAbandon(std::shared_ptr<Common::Ship> ship);
};
}

#endif // EVENTHANDLER_HH
