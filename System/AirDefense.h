#ifndef AIRDEFENSE_H
#define AIRDEFENSE_H

#include "Defending.h"

class AirDefense: public Defending
{
    public:
        void airDefense();
        AirDefense handle();
        ~AirDefense();
};

#endif