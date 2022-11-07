#ifndef TRANSPORTPHASE_H
#define TRANSPORTPHASE_H
#include "State.h"
#include "Engine.h"
#include "Action.h"
#include<iostream>
#include<string>
using namespace std;

class TransportPhase:public State{
    public:
        /**
         * @brief Constructor and set Engine object
         * 
         * @param engine
         */
        TransportPhase(Engine* engine);
        /**
         * @brief Implement transport action to get more money
         * 
         * @param c 
         * @return ** void 
         */
        virtual void handleAction(Context* c);
        /**
         * @brief Get the State object
         * 
         * @return ** string 
         */
        virtual string getState();

        Engine* engine;
};
#endif