#include "TransportPhase.h"
#include "Context.h"
#include "DefendPhase.h"
#include <iostream>
#include <string>

//include transport decorator
#include "ShortRoute.h"
#include "MediumRoute.h"
#include "LongRoute.h"

using namespace std;

TransportPhase :: TransportPhase(Engine* engine) {
    this->engine = engine;
}

void TransportPhase::handleAction(Context* c)
{

    int input;
    bool firstPass = false;

    while(!firstPass){
        cout << "\033[1;31m" << "Which transport route would you like to take?:" << "\033[0m" << endl;
        cout << "1. Short route [" << "\033[1;31m" << "Skip 1 turn" << "\033[0m" << " | " << "\033[1;32m" << "Get R 100 000" << "\033[0m" << "]" << endl;
        cout << "2. Medium route [" << "\033[1;31m" << "Skip 2 turns" << "\033[0m" << " | " << "\033[1;32m" << "Get R 500 000" << "\033[0m" << "]" << endl;
        cout << "3. Long route [" << "\033[1;31m" << "Skip 3 turns" << "\033[0m" << " | " << "\033[1;32m" << "Get R 1 500 000" << "\033[0m" << "]" << endl;
        cin >> input;

        if(input != 1 && input != 2 && input != 3){
            cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
        } else{
            firstPass = true;
        }
    }

    std::cout << endl << "Active transport operations:" << std::endl;
    if(input == 1){
        Transport* shortRoute = new ShortRoute(this->engine->P1SelectedCountry->baseTransportRoute);
        cout << shortRoute->getDescription() << endl;
        cout << "Amount: " << shortRoute->getMoneyGained() << endl;
        cout << "Number of turns to skip: " << shortRoute->getTurnsToSkip() << endl; //so to use the skip turn feature, we iterate through the array of 6 countries and call this method for each country. If the method returns a value greater than 0, the next player will play their turn
    }else if(input == 2){
        Transport* mediumRoute = new MediumRoute(this->engine->P1SelectedCountry->baseTransportRoute);
        cout << mediumRoute->getDescription() << endl;
        cout << "Amount: " << mediumRoute->getMoneyGained() << endl;
        cout << "Number of turns to skip: " << mediumRoute->getTurnsToSkip() << endl;
    }else if(input == 3){
        Transport* longRoute = new LongRoute(this->engine->P1SelectedCountry->baseTransportRoute);
        cout << longRoute->getDescription() << endl;
        cout << "Amount: " << longRoute->getMoneyGained() << endl;
        cout << "Number of turns to skip: " << longRoute->getTurnsToSkip() << endl;
    }

    // this->engine->P1SelectedCountry->addRoute();

    //Jackie code:
    // string ans;
    // cout<<"-----------------------------------------------"<<endl;
    // cout<<c->getState()<<endl;
    // cout<<"State: Transport Phase"<<endl;
    // cout<<endl;
    // cout<<"Doing some Transportation here"<<endl;
    // cout<<endl;
    // cout<<"For Testing:"<<endl;
    // cout<<"Go to Defend after Transportation"<<endl;
    // cout<<"Did you finish transportation?(y/n)";
    // cin>>ans;

    // if(ans=="y")
    // {
    //      c->setState(new DefendPhase(this->engine));
    // }

}

string TransportPhase::getState(){
    return "(Transport action.)";
}