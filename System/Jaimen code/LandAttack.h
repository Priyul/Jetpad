#ifndef LANDATTACK_H
#define LANDATTACK_H

#include "Attacking.h"
#include "WarStrategy.h"

class LandAttack: public Attacking
{
    public:
        LandAttack();
        LandAttack* playerHandle(vector<Army*> DefendingVector, vector<Army*> AttackingVector);
        //vector AIHandle()
        ~LandAttack();

    private:
        //vector<Army*> defendingArmy;
        //vector<Army*> attackingArmy;
};

#endif