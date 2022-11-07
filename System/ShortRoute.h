#ifndef SHORTROUTE_H
#define SHORTROUTE_H

#include "TransportDecorator.h"

class ShortRoute : public TransportDecorator{
public:
    ShortRoute(Transport* transport);
    std::string getDescription();
    void setDescription(std::string description);
    double getMoneyGained();
    void setMoneyGained(double money);
    void setTurnsToSkip(int turns);
    int getTurnsToSkip();

    int turnsToSkip;
};


#endif