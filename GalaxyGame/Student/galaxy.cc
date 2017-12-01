#include "galaxy.hh"

namespace Student {


Galaxy::Galaxy() {
}

Galaxy::~Galaxy(){
}

void Galaxy::addShip(std::shared_ptr<Common::Ship> ship) {

    if (ships_in_the_galaxy_.size() != 0) {
        if ( std::find(ships_in_the_galaxy_.begin(),
                       ships_in_the_galaxy_.end(), ship) != ships_in_the_galaxy_.end() ) {
            throw Common::StateException("Ship already exists in the galaxy");
        }
    }
    ships_in_the_galaxy_.push_back(ship);
}

void Galaxy::removeShip(std::shared_ptr<Common::Ship> ship){

    if (ships_in_the_galaxy_.size() == 0) {
        throw Common::ObjectNotFoundException("Ship doesn't exist");
    }
    if ( std::find(ships_in_the_galaxy_.begin(),
                   ships_in_the_galaxy_.end(), ship) == ships_in_the_galaxy_.end() ) {
        throw Common::ObjectNotFoundException("Ship doesn't exist");
    }
    ships_in_the_galaxy_.erase( std::find(ships_in_the_galaxy_.begin(),
                                          ships_in_the_galaxy_.end(), ship));
}

void Galaxy::addStarSystem(std::shared_ptr<Common::StarSystem> starSystem){

    for ( auto vectorstarSystem:starsystems_in_the_galaxy_ ) {

        if ( vectorstarSystem->getName() == starSystem->getName() || vectorstarSystem->getId() == starSystem->getId()
             || vectorstarSystem->getCoordinates() == starSystem->getCoordinates() ) {
            throw Common::StateException("There's already a Star System with the same ID, location or name");
        }
    }
    starsystems_in_the_galaxy_.push_back(starSystem);
}

std::shared_ptr<Galaxy::ShipVector> Galaxy::getShips(){
    std::shared_ptr<Galaxy::ShipVector> ships_in_the_galaxy_shared = std::make_shared<Galaxy::ShipVector>(ships_in_the_galaxy_);
    return ships_in_the_galaxy_shared;
}

Common::StarSystem::StarSystemVector Galaxy::getSystemsInRange
(std::shared_ptr<Common::StarSystem> origin, int range) {

    if ( std::find(starsystems_in_the_galaxy_.begin(),
                   starsystems_in_the_galaxy_.end(), origin) == starsystems_in_the_galaxy_.end() ) {
        throw Common::ObjectNotFoundException("Star System does not exist");
    }
    Common::StarSystem::StarSystemVector systems_in_range;

    for ( auto vectorstarSystem:starsystems_in_the_galaxy_ ) {

        if ( origin->getCoordinates().distanceTo( vectorstarSystem->getCoordinates() ) <= range
             && origin != vectorstarSystem ) {
            systems_in_range.push_back( vectorstarSystem );
        }
    }
    return systems_in_range;
}

std::shared_ptr<Common::StarSystem> Galaxy::getRandomSystem() {
    int max_index = starsystems_in_the_galaxy_.size();

    if ( max_index == 0 ) {
        throw Common::ObjectNotFoundException("There are no Star Systems in the galaxy");
    }
    int random_index = rand() % max_index;
    return starsystems_in_the_galaxy_[random_index];
}

Galaxy::ShipVector Galaxy::getShipsInStarSystem(std::string name) {

    bool star_system_exists = false;

    for ( auto vectorName:this->getSystemNames() ) { // Elegantimpi toteutus mahdollinen?

        if ( vectorName == name ) {
            star_system_exists = true;
            break;
        }
    }
    if ( not star_system_exists ) {
        throw Common::ObjectNotFoundException("A Star System with this name does not exist");
    }
    ShipVector ships_in_star_system;

    for ( auto vectorShip:ships_in_the_galaxy_ ) {

        if ( vectorShip->getLocation()->getName() == name ) {
            ships_in_star_system.push_back(vectorShip);
        }
    }
    return ships_in_star_system;
}

std::vector<std::string> Galaxy::getSystemNames() {
    std::vector<std::string> star_system_names;

    for ( auto vectorstarSystem:starsystems_in_the_galaxy_ ) {

        star_system_names.push_back( vectorstarSystem->getName() );

    }

    return star_system_names;
}

std::shared_ptr<Common::StarSystem> Galaxy::getStarSystemByName(std::string name) {

    for ( auto vectorstarSystem:starsystems_in_the_galaxy_ ) {

        if ( vectorstarSystem->getName() == name ) {
            return vectorstarSystem;
        }
    }
    throw Common::ObjectNotFoundException("A Star System with this name does not exist");
}

std::shared_ptr<Common::StarSystem> Galaxy::getStarSystemById(unsigned id) {

    for ( auto vectorstarSystem:starsystems_in_the_galaxy_ ) {

        if ( vectorstarSystem->getId() == id ) {
            return vectorstarSystem;
        }
    }
    throw Common::ObjectNotFoundException("A Star System with this ID does not exist");
}

}

