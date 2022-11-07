#ifndef LONGROUTE_H
#define LONGROUTE_H

#include "TransportDecorator.h"

class LongRoute : public TransportDecorator{
public:
    LongRoute(Transport* transport);
    std::string getDescription();
    void setDescription(std::string description);
    double getMoneyGained();
    void setMoneyGained(double money);
    void setTurnsToSkip(int turns);
    int getTurnsToSkip();

    int turnsToSkip;
};


#endif