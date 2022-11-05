#ifndef TRANSPORTDECORATOR_H
#define TRANSPORTDECORATOR_H

#include "Transport.h"

class TransportDecorator : public Transport{
private:
    Transport* transport;
public:
    TransportDecorator(Transport* transport);
    std::string getDescription();
    void setDescription(std::string description);
    double getMoneyGained();
    void setMoneyGained(double money);
    void setTurnsToSkip(int turns);
    int getTurnsToSkip();
};


#endif