#ifndef MEMENTO_H   
#define MEMENTO_H

#include "Originator.h"

using namespace std;

class Memento{
private:
    Originator* originator;

public:
    Memento(Originator* o);
    void setOriginator(Originator* o);
    Originator* getOriginator();
};
#endif