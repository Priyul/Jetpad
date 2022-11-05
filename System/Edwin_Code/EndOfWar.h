#ifndef ENDOFWAR_H
#define ENDOFWAR_H
#include "State.h"
#include<iostream>
#include<string>
using namespace std;

class EndOfWar : public State {
    public:
        virtual void handleAction(Context* c);
        virtual string getState();
};
#endif