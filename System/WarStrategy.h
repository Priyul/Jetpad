#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

#include <iostream>
using namespace std;

class WarStrategy
{
    public:
    // Getters
    WarStrategy();
    ~WarStrategy();
        string getBattleState();
    // Virtual Functions
        // Types of Attacks
    protected:
        string BattleState;
};
#endif
