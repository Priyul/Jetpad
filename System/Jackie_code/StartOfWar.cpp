#include "StartOfWar.h"
#include "Context.h"
#include "Action.h"
#include<iostream>
#include<string>
using namespace std;

void StartOfWar::handleAction(Context* c){
    string myCountry="";
    int num;
    cout<<c->getState()<<endl;
    cout<<"State: Start of war"<<endl;

    
    string array[] = {"United State of America", "China", "Russia", "United Kingdom", "Japan", "Canada", "Australia", "Egypt", "Iraq", "South Africa", "Zimbabwe", "Nepal"};
    for(int i = 0; i < 12; i++)
    {
        cout<<i<<". "<<array[i]<<endl;   
    }
    cout<<"Please choose your country by enter the number: ";
    cin>>num;
    cout<<"The country you choose: "<<array[num]<<endl;
    
    c->setState(new Action());

}

string StartOfWar::getState(){
    return "(Start of the War)";
}