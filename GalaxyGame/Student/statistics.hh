#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "assert.h"
#include "istatistics.hh"
#include "stateexception.hh"

namespace Student {

class Statistics : public Common::IStatistics
{
public:
    Statistics();

     void addSavedShip();
     unsigned getSavedShips() const;

     void addLostShip();
     unsigned getLostShips() const;

     void addPoints(unsigned amount);
     void reducePoints(unsigned amount);
     unsigned getPoints() const;

     void addCredits(unsigned amount);
     void reduceCredits(unsigned amount);
     int getCreditBalance() const;

private:
    int credits_ = 1000;
    unsigned graveyard_ = 0;
    unsigned saved_ = 0;
    unsigned int points_ = 0;
    unsigned const MAX_LOAN_ALLOWANCE = 1000;


};
}//Student

#endif // STATISTICS_HH
