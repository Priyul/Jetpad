#include "TransportPhase.h"
#include "Context.h"
#include "DefendPhase.h"
#include <iostream>
#include <string>
using namespace std;

void TransportPhase::handleAction(Context* c)
{
    string ans;
    cout<<"-----------------------------------------------"<<endl;
    cout<<c->getState()<<endl;
    cout<<"State: Transport Phase"<<endl;
    cout<<endl;
    cout<<"Doing some Transportation here"<<endl;
    cout<<endl;
    cout<<"For Testing:"<<endl;
    cout<<"Go to Defend after Transportation"<<endl;
    cout<<"Did you finish transportation?(y/n)";
    cin>>ans;

    if(ans=="y")
    {
         c->setState(new DefendPhase());
    }
   
   
    
    
}

string TransportPhase::getState(){
    return "(Transport action.)";
}