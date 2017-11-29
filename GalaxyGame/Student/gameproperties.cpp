#include "gameproperties.hh"

GameProperties::GameProperties() {

}

void GameProperties::setProperties() {
    std::shared_ptr<Common::IEventHandler> handler = std::make_shared<Student::EventHandler>();
    std::shared_ptr<Student::Galaxy> galaxy = std::make_shared<Student::Galaxy>();
    std::shared_ptr<Common::IGameRunner> gameRunner = Common::getGameRunner(galaxy, handler);
    handler_ = handler;
    galaxy_ = galaxy;
    gameRunner_ = gameRunner;
}

std::shared_ptr<Common::IEventHandler> GameProperties::getHandler() {
    return handler_;
}

std::shared_ptr<Student::Galaxy> GameProperties::getGalaxy() {
    return galaxy_;
}

std::shared_ptr<Common::IGameRunner> GameProperties::getRunner() {
    return gameRunner_;
}
