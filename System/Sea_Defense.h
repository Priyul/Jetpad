#ifndef SEA_DEFENSE_H
#define Sea_DEFENSE_H

#include "Defending.h"

class Sea_Defense: public Defending
{
    public:
        void SeaDefense();
        Sea_Defense();
        virtual Sea_Defense* handle();
        ~Sea_Defense();
};

#endif