#include "gameproperties.hh"

GameProperties::GameProperties() {
}

void GameProperties::setProperties() {
    try {
    std::shared_ptr<Student::EventHandler> handler = std::make_shared<Student::EventHandler>();
    std::shared_ptr<Student::Galaxy> galaxy = std::make_shared<Student::Galaxy>();
    std::shared_ptr<Common::IGameRunner> gameRunner = Common::getGameRunner(galaxy, handler);

    Student::EventHandler* rawHandler = handler.get();
    handler_ = rawHandler;
    galaxy_ = galaxy;
    gameRunner_ = gameRunner;

    } catch (Common::GameException e) {
        std::cout << e.msg() << std::endl <<
                     "The program will now exit." << std::endl;
        exit(1);
    }

}

Student::EventHandler* GameProperties::getHandler() {
    return handler_;
}

std::shared_ptr<Student::Galaxy> GameProperties::getGalaxy() {
    return galaxy_;
}

std::shared_ptr<Common::IGameRunner> GameProperties::getRunner() {
    return gameRunner_;
}

void GameProperties::tick() {
    gameRunner_->createActions();
    gameRunner_->doActions();
}
