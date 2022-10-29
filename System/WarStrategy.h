#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

#include <iostream>
using namespace std;

class WarStrategy
{
    public:
    // Getters
        string getBattleState(){return BattleState;};
    // Virtual Functions
        // Types of Attacks
         virtual void LandAttack()=0;
         virtual void AirAttack()=0;
         virtual void SeaAttack()=0;
        // Types of Defense
         virtual void LandDefense()=0;
         virtual void AirDefense()=0;
         virtual void seaDefense()=0;
    protected:
        string BattleState;
};
#endif
