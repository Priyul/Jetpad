#include "EndOfWar.h"
#include "Context.h"
#include<iostream>
#include<string>
using namespace std;

void EndOfWar::handleAction(Context* c){
   
    cout<<"-----------------------------------------------"<<endl;
    cout<<"State: Start of war"<<endl;
    cout<<endl;
    cout<<"You Win/Lose the war!"<<endl;
    cout<<endl;
    cout<<c->getState()<<endl;

}

string EndOfWar::getState(){
    return "(End of the War)";
}