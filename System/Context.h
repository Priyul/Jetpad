#ifndef CONTEXT_H
#define CONTEXT_H
// #include "State.h"
// #include "StartOfWar.h"
#include <iostream>
#include<string>
using namespace std;

class State;

class Context{
    private:
        State* state;
    public:
        /**
         * @brief Construct a new Context object
         * 
         */
        Context();

        /**
         * @brief Destroy context object
         * 
         * 
         */
        ~Context();

        /**
         * @brief change state
         * 
         * 
         */
        void change();

        /**
         * @brief get state
         * 
         * @return string
         */
        string getState();

        /**
         * @brief set state
         * 
         * @param s
         */
        void setState(State* s);
};
#endif