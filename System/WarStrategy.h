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
        virtual void LandAttack();
        virtual void AirAttack();
        virtual void SeaAttack();
        // Types of Defense
        virtual void LandDefense();
        virtual void AirDefense();
        virtual void SeaDefense();
    protected:
        string BattleState;
};
#endif
