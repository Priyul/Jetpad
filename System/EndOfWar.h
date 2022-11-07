#ifndef ENDOFWAR_H
#define ENDOFWAR_H
#include "State.h"
#include "Engine.h"
#include<iostream>
#include<string>
using namespace std;

class EndOfWar : public State {
    public:
        EndOfWar(Engine* engine);
        virtual void handleAction(Context* c);
        virtual string getState();
    
    private:
        Engine* engine;
};
#endif