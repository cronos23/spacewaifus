#include "eventhandler.hh"

namespace Student {

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::shipSpawned(std::shared_ptr<Common::Ship> ship) {

}

void EventHandler::shipRemoved(std::shared_ptr<Common::Ship> ship)
{

}

void EventHandler::shipRelocated(std::shared_ptr<Common::Ship> ship, std::shared_ptr<Common::StarSystem> starSystem)
{

}

void EventHandler::shipMoved(std::shared_ptr<Common::Ship> ship, Common::Point origin, Common::Point target)
{

}

void EventHandler::exceptionInExecution(std::shared_ptr<Common::Ship> ship, const std::__cxx11::string &msg)
{

}

void EventHandler::distressOn(std::shared_ptr<Common::Ship> ship)
{

}

void EventHandler::distressOff(std::shared_ptr<Common::Ship> ship)
{

}

void EventHandler::shipAbandoned(std::shared_ptr<Common::Ship> ship)
{

}



}
