#ifndef ATTACKPHASE_H
#define ATTACKPHASE_H
#include "State.h"
#include "Country.h"
#include<iostream>
#include<string>
using namespace std;

class AttackPhase:public State{
    public:
        virtual void handleAction(Context* c);
        virtual string getState();
};
#endif