#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

#include <iostream>
using namespace std;

class WarStrategy
{
    public:
    // Getters
        string getBattleState();
    // Virtual Functions
        // Types of Attacks
        virtual void landAttack();
        virtual void airAttack();
        virtual void seaAttack();
        // Types of Defense
        virtual void landDefense();
        virtual void airDefense();
        virtual void seaDefense();
    protected:
        string BattleState;
};
#endif
