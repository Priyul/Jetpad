#ifndef AIR_DEFENSE_H
#define AIR_DEFENSE_H

#include "Defending.h"

class Air_Defense: public Defending
{
    public:
        void AirDefense();
        Air_Defense();
        virtual Air_Defense* handle();
        ~Air_Defense();
};

#endif