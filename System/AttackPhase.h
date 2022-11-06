#ifndef ATTACKPHASE_H
#define ATTACKPHASE_H
#include "State.h"
#include "Country.h"
#include "Engine.h"
#include "ChoosePlayerPhase.h"

#include<iostream>
#include<string>
using namespace std;

class AttackPhase:public State{
    public:
        AttackPhase(Engine* engine);
        virtual void handleAction(Context* c);
        virtual string getState();

        Engine* engine;
};
#endif