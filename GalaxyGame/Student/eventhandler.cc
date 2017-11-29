#include "eventhandler.hh"

namespace Student {

EventHandler::EventHandler() {
}

EventHandler::~EventHandler() {
}

void EventHandler::shipSpawned(std::shared_ptr<Common::Ship> ship) {
    emit shipSpawn(ship);
}

void EventHandler::shipRemoved(std::shared_ptr<Common::Ship> ship) {
    emit shipRemove(ship);
}

void EventHandler::shipRelocated(std::shared_ptr<Common::Ship> ship, std::shared_ptr<Common::StarSystem> starSystem) {
    emit shipRelocate(ship, starSystem);
}

void EventHandler::shipMoved(std::shared_ptr<Common::Ship> ship, Common::Point origin, Common::Point target) {
    emit shipMove(ship, origin, target);
}

void EventHandler::exceptionInExecution(std::shared_ptr<Common::Ship> ship, const std::__cxx11::string &msg) {
    emit ExecutionException(ship, msg);
}

void EventHandler::distressOn(std::shared_ptr<Common::Ship> ship) {
    emit distressToggleOn(ship);
}

void EventHandler::distressOff(std::shared_ptr<Common::Ship> ship) {
    emit distressToggleOff(ship);
}

void EventHandler::shipAbandoned(std::shared_ptr<Common::Ship> ship) {
    emit shipAbandon(ship);
}



}
