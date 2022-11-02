#include "Context.h"
#include "StartOfWar.h"
#include <iostream>
#include <string>
using namespace std;

Context::Context(){
    state = new StartOfWar();
}

Context::~Context(){
    delete this->state;
    state = 0;
}

void Context::change(){
    state->handleAction(this);
}

string Context::getState(){
    return state->getState();
}

void Context::setState(State* s){
    delete state;
    state = s;
    this->change();
}