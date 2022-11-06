#ifndef BUILDPHASE_H
#define BUILDPHASE_H
#include "State.h"
#include "Engine.h"
#include<iostream>
#include<string>
using namespace std;

#include "Country.h"

class BuildPhase:public State{
    public:
        /**
         * @brief Construct a new Build Phase object
         * 
         * @param engine
         * 
         */
        BuildPhase(Engine* engine);

        /**
         * @brief build army and vehicles
         * 
         * 
         * @param c
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