#include "statistics.hh"


Student::Statistics::Statistics() {
}

void Student::Statistics::addSavedShip() {
    saved_ += 1;
}

unsigned Student::Statistics::getSavedShips() const {
    return saved_;
}

void Student::Statistics::addLostShip() {
    graveyard_ += 1;
}

unsigned Student::Statistics::getLostShips() const {
    return graveyard_;
}

void Student::Statistics::addPoints(unsigned amount) {
    points_ += amount;
}

void Student::Statistics::reducePoints(unsigned amount) {
    if (points_ < amount) {
        throw Common::StateException("Points would be lowered below 0");
    }
    points_ -= amount;
}

unsigned Student::Statistics::getPoints() const {
    return points_;
}

void Student::Statistics::addCredits(unsigned amount) {
    credits_ += amount;
}

void Student::Statistics::reduceCredits(unsigned amount) {
    int signed_amount = (int) amount;
    if ( credits_ < signed_amount) {
        if ( amount - credits_ > MAX_LOAN_ALLOWANCE ) {
            throw Common::StateException( "Maximum loan allowance exceeded");
        }
    }
    credits_ -= amount;
}

int Student::Statistics::getCreditBalance() const {
    return credits_;
}
