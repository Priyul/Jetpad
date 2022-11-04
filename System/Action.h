#ifndef ACTION_H
#define ACTION_H
#include "State.h"
#include<iostream>
#include<string>
using namespace std;

class Action: public State{
    public:
        virtual void handleAction(Context* c);
        virtual string getState();
};
#endif