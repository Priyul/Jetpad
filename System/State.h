#ifndef STATE_H
#define STATE_H
// #include "Context.h"
#include <iostream>
#include <string>
using namespace std;
#include "Bank.h"
class Context;


class State{
    public:
        /**
         * @brief Handle different Actions in different States
         * 
         * @param c 
         * @return ** void 
         */
        virtual void handleAction(Context* c) = 0;
        /**
         * @brief Get the State object
         * 
         * @return ** string 
         */
        virtual string getState()=0;
        /**
         * @brief Destructor
         * 
         */
        virtual ~State();
};
#endif