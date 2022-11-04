#ifndef DEFENDPHASE_H
#define DEFENDPHASE_H
#include "State.h"
#include<iostream>
#include<string>
using namespace std;

class DefendPhase:public State{
    public:
        virtual void handleAction(Context* c);
        virtual string getState();
};
#endif