#ifndef AIRDEFENSE_H
#define AIRDEFENSE_H

#include "Defending.h"

class AirDefense: public Defending
{
    public:
        AirDefense();
        AirDefense* handle();
        ~AirDefense();
};

#endif