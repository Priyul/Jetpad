#ifndef BUILDPHASE_H
#define BUILDPHASE_H
#include "State.h"
#include<iostream>
#include<string>
using namespace std;

#include "Country.h"

class BuildPhase:public State{
    public:
        virtual void handleAction(Context* c);
        virtual string getState();

};
#endif