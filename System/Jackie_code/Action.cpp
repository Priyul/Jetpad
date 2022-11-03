#include "Action.h"
#include "Context.h"
#include "AttackPhase.h"
#include "BuildPhase.h"
#include "TransportPhase.h"
#include<iostream>
#include<string>
using namespace std;

void Action::handleAction(Context* c){
    int num;
    cout<<"-----------------------------------------------"<<endl;
    cout<<c->getState()<<endl;
    cout<<"State: Action state"<<endl;
    cout<<"1. Build my troops."<<endl;
    cout<<"2. Attack a country"<<endl;
    cout<<"3. Transport"<<endl;
    cout<<"(Hints: Start with building troops.)"<<endl;
    cout<<"Select your next action by entering a number: ";
    cin>>num;

    if(num == 1)
    {
        c->setState(new BuildPhase());
    }
    else if(num == 2)
    {
        c->setState(new AttackPhase());
    }
    else if(num == 3)
    {
        c->setState(new TransportPhase());
    }
}

string Action::getState(){
    return "(Choose next action.)";
}