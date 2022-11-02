#include "BuildPhase.h"
#include "Context.h"
#include "Action.h"
#include <iostream>
#include <string>
using namespace std;

void BuildPhase::handleAction(Context* c)
{
    string ans;
    cout<<"-----------------------------------------------"<<endl;
    cout<<c->getState()<<endl;
    cout<<"State: Building Phase"<<endl;
    cout<<endl;
    cout<<"Building troops here"<<endl;
    cout<<endl;
    cout<<"For Testing:"<<endl;
    cout<<"Back to Action after building troops"<<endl;
    cout<<"Do you finish building your Troops?(y/n)";
    cin>>ans;
    if(ans == "y")
    {
        c->setState(new Action());
    }
    
}

string BuildPhase::getState(){
    return "(Build action.)";
}