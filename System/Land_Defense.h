#ifndef LAND_DEFENSE_H
#define LAND_DEFENSE_H

#include "Defending.h"

class Land_Defense: public Defending
{
    public:
        void LandAttack();
        Land_Defense();
        virtual Land_Defense* handle();
        ~Land_Defense();
};

#endif