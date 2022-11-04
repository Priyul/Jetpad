#ifndef LAND_DEFENSE_H
#define LAND_DEFENSE_H

#include "Defending.h"

class LandDefense: public Defending
{
    public:
        LandDefense();
        LandDefense* handle();
        ~LandDefense();
};

#endif