#include "starsystemobject.hh"


void starsystemobject::setSizeByPop() {
    int population = starsystemptr_->getPopulation();
    if (population <= 200000) {
        starsystemsize_ = 30;

    } else if (population <= 2000000){
        starsystemsize_ = 40;

    } else {
        starsystemsize_ = 60;
    }
}

int starsystemobject::getSize() {
    return starsystemsize_;
}

void starsystemobject::setStarSystem(std::shared_ptr<Common::StarSystem> starSystem) {
    starsystemptr_ = starSystem;
}

std::shared_ptr<Common::StarSystem> starsystemobject::getStarSystem() {
    return starsystemptr_;
}

// Add mouseclick/hoverevent tooltip (or info in hud)
