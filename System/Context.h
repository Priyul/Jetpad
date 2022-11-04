#ifndef CONTEXT_H
#define CONTEXT_H
// #include "State.h"
// #include "StartOfWar.h"
#include <iostream>
#include<string>
using namespace std;

class State;

class Context{
    private:
        State* state;
    public:
        Context();
        ~Context();
        void change();
        string getState();
        void setState(State* s);
};
#endif