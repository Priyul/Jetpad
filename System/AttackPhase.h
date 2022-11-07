#ifndef ATTACKPHASE_H
#define ATTACKPHASE_H
#include "State.h"
#include "Country.h"
#include "Engine.h"
#include "ChoosePlayerPhase.h"
#include "EndOfWar.h"

#include<iostream>
#include<string>
using namespace std;

class AttackPhase:public State{
    public:
        /**
         * @brief Construct a new Attack Phase object
         * 
         * @param engine 
        */
        AttackPhase(Engine* engine);

        /**
         * @brief Implement strategy pattern
         * 
         * @param c
         * 
        */
        virtual void handleAction(Context* c);

        /**
         * @brief get the current state
         * 
        */
        virtual string getState();

        Engine* engine;
};
#endif