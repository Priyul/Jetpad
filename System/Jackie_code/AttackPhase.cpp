#include "AttackPhase.h"
#include "Context.h"
#include "Action.h"
#include "DefendPhase.h"
#include "EndOfWar.h"
#include <iostream>
#include <string>
using namespace std;

void AttackPhase::handleAction(Context* c)
{
    int num;
    cout<<"-----------------------------------------------"<<endl;
    cout<<c->getState()<<endl;
    cout<<"State: Attack Phase"<<endl;
    cout<<endl;
    cout<<"Doing some attack here"<<endl;
    cout<<endl;
    cout<<"For Testing"<<endl;
    cout<<"1. Attack next country"<<endl;
    cout<<"2. Defend"<<endl;
    cout<<"3. Win the war"<<endl;
    cout<<"Select your next action by enter the number: ";
    cin>>num;
    if(num == 1)
    {
        c->setState(new Action());
    }
    else if(num == 2)
    {
        c->setState(new DefendPhase());
    }
    else if(num == 3)
    {
        c->setState(new EndOfWar());
    }
    
}

string AttackPhase::getState(){
    return "(Attack action.)";
}