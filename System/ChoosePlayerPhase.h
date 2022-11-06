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

    /**
     * @brief Construct a new Choose Player Phase object
     * 
     * @param engine 
    */
    ChoosePlayerPhase(Engine* engine); 

    /**
     * @brief Implements choose player phase
     * 
     * @param c
     * 
    */
    virtual void handleAction(Context* c);

    /**
     * @brief Get the state object
     * 
     * @return string
    */
    virtual string getState();
    Engine* engine;
};

#endif
