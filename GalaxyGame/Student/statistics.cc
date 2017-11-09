#include "statistics.hh"


Student::Statistics::Statistics()
{

}

void Student::Statistics::addSavedShip()
{

}

unsigned Student::Statistics::getSavedShips() const
{

}

void Student::Statistics::addLostShip()
{

}

unsigned Student::Statistics::getLostShips() const
{

}

void Student::Statistics::addPoints(unsigned amount)
{
    points_ += amount;
}

void Student::Statistics::reducePoints(unsigned amount)
{
    if (points_ - amount < 0) {
        throw Common::StateException("Points would be lowered below 0");
    }
    points_ -= amount;
}

unsigned Student::Statistics::getPoints() const
{

}

void Student::Statistics::addCredits(unsigned amount)
{

}

void Student::Statistics::reduceCredits(unsigned amount)
{

}

int Student::Statistics::getCreditBalance() const
{
    return credits_;
}
