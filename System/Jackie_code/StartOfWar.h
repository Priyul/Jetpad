#ifndef STARTOFWAR_H
#define STARTOFWAR_H
#include "State.h"
// #include "Context.h"
#include<iostream>
#include<string>
using namespace std;
// class State{};
// class Context;

class StartOfWar : public State {
    public:
        virtual void handleAction(Context* c);
        virtual string getState();
};
#endif