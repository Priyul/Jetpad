#ifndef ENDOFWAR_H
#define ENDOFWAR_H
#include "State.h"
#include "Engine.h"
#include<iostream>
#include<string>
using namespace std;

class EndOfWar : public State {
    public:

        /**
         * @brief implements the end of war
         * @param c
         */
        EndOfWar(Engine* engine);

        virtual void handleAction(Context* c);

        /**
         * @brief gets the state
         * @return string
         */
        virtual string getState();
    
    private:
        Engine* engine;
};
#endif