#ifndef MEMENTO_H   
#define MEMENTO_H

#include "State.h"
#include <string>

using namespace std;

class Memento{
    public:
        Memento(string, double, State*);
        string getName(){return name;};
        double getBalance(){return balance;};
        State* getState(){return state;};

    private:
        string name;
        double balance;
        State* state;

};
#endif