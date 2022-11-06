#ifndef TRANSPORTPHASE_H
#define TRANSPORTPHASE_H
#include "State.h"
#include "Engine.h"
#include "Action.h"
#include<iostream>
#include<string>
using namespace std;

class TransportPhase:public State{
    public:
        TransportPhase(Engine* engine);
        virtual void handleAction(Context* c);
        virtual string getState();

        Engine* engine;
};
#endif