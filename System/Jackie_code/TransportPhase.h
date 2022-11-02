#ifndef TRANSPORTPHASE_H
#define TRANSPORTPAHSE_H
#include "State.h"
#include<iostream>
#include<string>
using namespace std;

class TransportPhase:public State{
    public:
        virtual void handleAction(Context* c);
        virtual string getState();
};
#endif