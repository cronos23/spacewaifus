#include "galaxy.hh"
namespace Student {
    virtual void addShip(std::shared_ptr<Common::Ship> ship) {
        if ( std::find(ships_in_the_galaxy_.begin(),
                       ships_in_the_galaxy_.end(), ship) != ships_in_the_galaxy_.end() ) {
            throw Common::StateException("Ship already exists in the galaxy");
        }
        else {
            ships_in_the_galaxy_.push_back(ship);
        }
}

    virtual void removeShip(std::shared_ptr<Common::Ship> ship){

}

    virtual void addStarSystem(std::shared_ptr<Common::StarSystem> starSystem){

}

    virtual std::shared_ptr<ShipVector> getShips(){

}

    virtual Common::StarSystem::StarSystemVector getSystemsInRange
    (std::shared_ptr<Common::StarSystem> origin, int range) {

}

    virtual std::shared_ptr<Common::StarSystem> getRandomSystem() {

}

    ShipVector getShipsInStarSystem(std::string name) {

}

    std::vector<std::string> getSystemNames() {

}

    std::shared_ptr<Common::StarSystem> getStarSystemByName(std::string name) {

}

    std::shared_ptr<Common::StarSystem> getStarSystemById(unsigned id) {

}

}
