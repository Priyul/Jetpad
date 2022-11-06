#include "Action.h"
#include "Context.h"
#include "AttackPhase.h"
#include "BuildPhase.h"
#include "TransportPhase.h"
#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

Action :: Action (Engine* engine) {
    this->engine = engine;
}

int playerTurn(Engine* engine){
    cout << "\033[1;32m" << "Player 1 army: (" << engine->P1SelectedCountry->getCountryName() << ")" << "\033[0m";
    engine->P1SelectedCountry->showArmy();
    cout << fixed;
    cout << setprecision(2) << endl;
    cout << "\033[1;32m" << "Money: " << engine->P1SelectedCountry->getMoney() << "\033[0m" << endl << endl;

    int firstInput;
    cout << "\033[1;31m" << "What would you like to do?" << "\033[0m" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Build army" << endl;
    cout << "3. Transport goods" << endl;
    cout << "4. Exit" << endl; //testing
    cout << "select option: > ";
    cin >> firstInput;
    return firstInput;
}

void Action::handleAction(Context* c){

    bool doCheck = true;

     ///IMPORTANT NOTE - To make the while loop of the action state terminate, set firstpass = true AND doCheck = false

    while(doCheck) {
        int firstInput = playerTurn(this->engine);
        bool firstPass = false;

        while (!firstPass) { //priyul
            switch (firstInput) {
                case 1:
                    cout << "Attack selected" << endl;
                    firstPass = true;
                    c->setState(new AttackPhase(engine));
                    //engine->P1SelectedCountry->attack(); //myCountry used instead of america
                    // doCheck = false; //to go to action again after fighting, I commented out this line
                    break;
                case 2:
                    cout << "Build selected" << endl;
                    firstPass = true;
                    c->setState(new BuildPhase(engine));
                    // engine->P1SelectedCountry->buildArmy();
                    break;
                case 3:
                    cout << "Transport selected" << endl;
                    firstPass = true;
                    c->setState(new TransportPhase(engine));
                    // engine->P1SelectedCountry->addRoute();
                    doCheck = true;
                    break;
                case 4:
                    firstPass = true;
                    doCheck = false;
                    break;
                default:
                    cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                    firstInput = playerTurn(this->engine);
            }
        }
    }

    // for(int i=0; i<engine->P1SelectedCountry->army.size(); i++){
    //     cout << "army at: " << i << engine->P1SelectedCountry->army[i]->getRank() << endl;
    // }
    engine->P1SelectedCountry->showArmy();

    //jackie code:
    // int num;
    // cout<<"-----------------------------------------------"<<endl;
    // cout<<c->getState()<<endl;

    // cout << "testing: " << engine->P1SelectedCountry->getCountryName() << endl;
    // cout<<"State: Action state"<<endl;
    // cout<<"1. Build my troops."<<endl;
    // cout<<"2. Attack a country"<<endl;
    // cout<<"3. Transport"<<endl;
    // cout<<"(Hints: Start with building troops.)"<<endl;
    // cout<<"Select your next action by entering a number: ";
    // cin>>num;

    // if(num == 1)
    // {
    //     c->setState(new BuildPhase(this->engine));
    // }
    // else if(num == 2)
    // {
    //     c->setState(new AttackPhase(this->engine));
    // }
    // else if(num == 3)
    // {
    //     c->setState(new TransportPhase(this->engine));
    // }
}

string Action::getState(){
    return "(Choose next action.)";
}