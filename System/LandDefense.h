#ifndef LANDDEFENSE_H
#define LANDDEFENSE_H

#include "Defending.h"

class LandDefense: public Defending
{
    public:
        void landDefense();
        LandDefense handle();
        ~LandDefense();
};

#endif