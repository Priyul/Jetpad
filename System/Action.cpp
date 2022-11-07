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

    Country* currentCountry = engine->whichPlayerTurnCountry();

    vector<Country*> currentCountryVector = engine->whichPlayerTurnVector();
    
    cout << "curr army size: " << currentCountry->army.size() << endl;
    cout << "\033[1;32m" << engine->printCurrentPlayer() << " army: (" << currentCountry->getCountryName() << ")" << "\033[0m";
    currentCountry->showArmy();
    cout << fixed;
    cout << setprecision(2) << endl;
    cout << "\033[1;32m" << "Money: " << currentCountry->getMoney() << "\033[0m" << endl << endl;

    int firstInput;
    cout << "\033[1;31m" << engine->printCurrentPlayer() << " What would you like to do?" << "\033[0m" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Build army" << endl;
    cout << "3. Transport goods" << endl;
    cout << "4. Exit" << endl; //testing
    cout << "select option: > ";
    cin >> firstInput;
    return firstInput;
}

void Action::handleAction(Context* c){

    // cout << "Went into action" << endl;
    bool doCheck = true;

    Country* currentCountry = engine->whichPlayerTurnCountry();

    vector<Country*> currentCountryVector = engine->whichPlayerTurnVector();


    ///IMPORTANT NOTE - To make the while loop of the action state terminate, set firstpass = true AND doCheck = false

    for (int i = 0; i < currentCountryVector.size(); i++) {
        
        if (currentCountryVector[i]->getTurnsToSkip() > 0) {
            cout << "Skipping turn for player " << endl;
            currentCountryVector[i]->setTurnsToSkip(currentCountryVector[i]->getTurnsToSkip()-1);
            engine->switchTurns();
            // cout << "Inside if statement, turns to skip: " << currentCountryVector[i]->getTurnsToSkip() << endl;
            c->setState(new ChoosePlayerPhase(this->engine));
            // return;
        }
    }

    while(doCheck) {
        // s
        int firstInput = playerTurn(this->engine);
        bool firstPass = false;

        while (!firstPass) { 
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

    currentCountry->showArmy();

}

string Action::getState(){
    return "(Choose next action.)";
}