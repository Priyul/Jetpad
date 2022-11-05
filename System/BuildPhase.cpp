#include "BuildPhase.h"
#include "Context.h"
#include "Action.h"
#include <iostream>
#include <string>
using namespace std;

BuildPhase::BuildPhase(){
    this->country = new Country();
}

void BuildPhase::handleAction(Context* c)
{
    string ans;
    cout<<"-----------------------------------------------"<<endl;
    cout<<c->getState()<<endl;
    cout<<"State: Building Phase"<<endl << endl;
    
    bool finished = false;
    
    
    cout<<"Did you finish building your Troops?(y/n)";
    cin>>ans;
    if(ans == "y")
    {
        c->setState(new Action());
    } else {

    }
    
}

string BuildPhase::getState(){
    return "(Build action.)";
}