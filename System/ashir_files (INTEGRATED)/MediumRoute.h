#ifndef MEDIUMROUTE_H
#define MEDIUMROUTE_H

#include "TransportDecorator.h"

class MediumRoute : public TransportDecorator{
public:
    MediumRoute(Transport* transport);
    std::string getDescription();
    void setDescription(std::string description);
    double getMoneyGained();
    void setMoneyGained(double money);
    void setTurnsToSkip(int turns);
    int getTurnsToSkip();
};


#endif