#ifndef SEA_DEFENSE_H
#define Sea_DEFENSE_H

#include "Defending.h"

class SeaDefense: public Defending
{
    public:
        SeaDefense();
        SeaDefense* handle();
        ~SeaDefense();
};

#endif