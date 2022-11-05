#ifndef DEFENDPHASE_H
#define DEFENDPHASE_H
#include "State.h"
#include "Engine.h"
#include<iostream>
#include<string>
using namespace std;

class DefendPhase:public State{
    public:

        DefendPhase(Engine* engine);
        virtual void handleAction(Context* c);
        virtual string getState();

        Engine* engine;
};
#endif