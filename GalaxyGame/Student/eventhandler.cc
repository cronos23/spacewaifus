#include "eventhandler.hh"

namespace Student {

EventHandler::EventHandler() {
}

EventHandler::~EventHandler() {
}

void EventHandler::shipSpawned(std::shared_ptr<Common::Ship> ship) {
    emit shipSpawned(ship);
}

void EventHandler::shipRemoved(std::shared_ptr<Common::Ship> ship) {
    emit shipRemoved(ship);
}

void EventHandler::shipRelocated(std::shared_ptr<Common::Ship> ship, std::shared_ptr<Common::StarSystem> starSystem) {
    emit shipRelocated(ship, starSystem);
}

void EventHandler::shipMoved(std::shared_ptr<Common::Ship> ship, Common::Point origin, Common::Point target) {
    emit shipMoved(ship, origin, target);
}

void EventHandler::exceptionInExecution(std::shared_ptr<Common::Ship> ship, const std::__cxx11::string &msg) {
    emit exceptionInExecution(ship, msg);
}

void EventHandler::distressOn(std::shared_ptr<Common::Ship> ship) {
    emit distressOn(ship);
}

void EventHandler::distressOff(std::shared_ptr<Common::Ship> ship) {
    emit distressOff(ship);
}

void EventHandler::shipAbandoned(std::shared_ptr<Common::Ship> ship) {
    emit shipAbandoned(ship);
}



}
