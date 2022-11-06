#ifndef CHOOSEPLAYERPHASE_H
#define CHOOSEPLAYERPHASE_H

#include "State.h"
#include "Engine.h"
#include "Context.h"

#include "Action.h"

#include <string>
#include <iostream>
#include <iomanip>


class ChoosePlayerPhase : public State{
public:
    ChoosePlayerPhase(Engine* engine); 
    virtual void handleAction(Context* c);
    virtual string getState();
    Engine* engine;
};

#endif
