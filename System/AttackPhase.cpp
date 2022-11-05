#include "AttackPhase.h"
#include "Context.h"
#include "Action.h"
#include "DefendPhase.h"
#include "EndOfWar.h"
#include <iostream>
#include <string>
using namespace std;

AttackPhase :: AttackPhase(Engine *engine) {
    this->engine = engine;
}

void AttackPhase::handleAction(Context* c)
{
    int num;
    cout<<"-----------------------------------------------"<<endl;
    cout<<c->getState()<<endl;
    cout<<"State: Attack Phase"<<endl;
    cout<<endl;
    //cout<< "Country "<< this->myCountry->getName() << "is declaring war on "<< << endl;
    cout<<endl; 

    cin>>num;
    if(num == 1)
    {
        c->setState(new Action(this->engine));
    }
    else if(num == 2)
    {
        c->setState(new DefendPhase(this->engine));
    }
    else if(num == 3)
    {
        c->setState(new EndOfWar());
    }
    
}

string AttackPhase::getState(){
    return "Attack state";
}