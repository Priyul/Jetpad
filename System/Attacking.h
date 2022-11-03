#ifndef ATTACKING_H
#define ATTACKING_H

#include "WarStrategy.h"

class Attacking : public WarStrategy{
public:
    virtual void landAttackHandle() = 0;
private:
    virtual void landDefenseHandle(){};
};

#endif

//priyul 