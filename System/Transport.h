#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>

class Transport {
public:
    virtual ~Transport() {}
    virtual std::string getDescription() = 0;
    virtual void setDescription(std::string description) = 0;
    virtual double getMoneyGained() = 0;
    virtual void setMoneyGained(double money) = 0;
    virtual void setTurnsToSkip(int turns) = 0;
    virtual int getTurnsToSkip() = 0;

    int turnsToSkip;
protected:
    double moneyGained;
    std::string routeDescription;
};


#endif 