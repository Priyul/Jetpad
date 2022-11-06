#ifndef STATE_H
#define STATE_H
// #include "Context.h"
#include <iostream>
#include <string>
using namespace std;
#include "Bank.h"
class Context;


class State{
    public:
        virtual void handleAction(Context* c) = 0;
        virtual string getState()=0;
        virtual ~State();
};
#endif