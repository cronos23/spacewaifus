#include "galaxy.hh"

namespace Student {

    void Galaxy::addShip(std::shared_ptr<Common::Ship> ship) {

        if ( std::find(ships_in_the_galaxy_.begin(),
                       ships_in_the_galaxy_.end(), ship) != ships_in_the_galaxy_.end() ) {
            throw Common::StateException("Ship already exists in the galaxy");

        } else {
            ships_in_the_galaxy_.push_back(ship);
        }
}

    virtual void Galaxy::removeShip(std::shared_ptr<Common::Ship> ship){

        if ( std::find(ships_in_the_galaxy_.begin(),
                       ships_in_the_galaxy_.end(), ship) != ships_in_the_galaxy_.end() ) {
            ships_in_the_galaxy_.erase( std::find(ships_in_the_galaxy_.begin(),
                                                  ships_in_the_galaxy_.end(), ship));
        }
}

    virtual void Galaxy::addStarSystem(std::shared_ptr<Common::StarSystem> starSystem){

}

    virtual std::shared_ptr<ShipVector> getShips(){

}

    virtual Common::StarSystem::StarSystemVector Galaxy::getSystemsInRange
    (std::shared_ptr<Common::StarSystem> origin, int range) {

}

    virtual std::shared_ptr<Common::StarSystem> Galaxy::getRandomSystem() {

}

    ShipVector Galaxy::getShipsInStarSystem(std::string name) {

}

    std::vector<std::string> Galaxy::getSystemNames() {

}

    std::shared_ptr<Common::StarSystem> Galaxy::getStarSystemByName(std::string name) {

}

    std::shared_ptr<Common::StarSystem> Galaxy::getStarSystemById(unsigned id) {

}

}
