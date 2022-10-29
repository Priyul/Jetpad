#ifndef SEADEFENSE_H
#define SEADEFENSE_H

#include "Defending.h"

class SeaDefense: public Defending
{
    public:
        void seaDefense();
        SeaDefense handle();
        ~SeaDefense();
};

#endif