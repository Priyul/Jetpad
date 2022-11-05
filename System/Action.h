#ifndef ACTION_H
#define ACTION_H
#include "State.h"
//#include "Country.h"
#include "Engine.h"
#include<iostream>
#include<string>
using namespace std;

class Action: public State{
    public:
        Action(Engine* engine);
        virtual void handleAction(Context* c);
        virtual string getState();

        Engine* engine;
        //Engine* getEngine();
    
    private:
        //Engine* engine;
};
#endif