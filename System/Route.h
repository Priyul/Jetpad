#ifndef ROUTE_H
#define ROUTE_H

#include "Transport.h"

class Route : public Transport{
public:
    std::string getDescription();
    void setDescription(std::string description);
    double getMoneyGained();
    void setMoneyGained(double money);
    void setTurnsToSkip(int turns);
    int getTurnsToSkip();
};


#endif