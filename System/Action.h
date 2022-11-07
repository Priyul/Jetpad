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

        /**
         * @brief handle action
         * 
         * @param c 
         */
        virtual void handleAction(Context* c);

        /**
         * @brief Get the State object
         * 
         * @return string 
         */
        virtual string getState();
        Engine* engine;
        //Engine* getEngine();
    
    private:
        //Engine* engine;
};
#endif