#include <iostream>
#include <vector>

#include "Country.h"
#include "Soldier.h"
#include "SoldierFactory.h"
#include "VehicleFactory.h"
#include "ArmyFactory.h"

#include "State.h"
#include "Context.h"
#include "StartOfWar.h"

using namespace std;
class State;

int playerTurn(){
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

int main() {
    //Country* america = new Country("America", 100000);
    //start of war state:
    // Context* currContext = new Context();
    // StartOfWar* currentState = new StartOfWar();
    // currentState->handleAction(currContext);

    // Country* myCountry = currentState->getmyCountry();
    // Country* allyCountry = currentState->getAllyCountry();

    Country* myCountry = new Country();
    myCountry->setMoney(100000);
    myCountry->setName("America");

    //Action state below
    bool doCheck = true;

    while(doCheck) {
        int firstInput = playerTurn();
        bool firstPass = false;

        vector<Army*> returningArmy;

        while (!firstPass) { //priyul
            switch (firstInput) {
                case 1:
                    cout << "Attack selected" << endl;
                    returningArmy = myCountry->attack(); //myCountry used instead of america
                    // if(!returningArmy.empty()){ //failed to attack due to insuffecient number of tr
                    //     firstPass = true;
                    // }
                    firstPass = true;
                    // doCheck = true; //idk if this is supposed to be here anymore, check again
                    break;
                case 2:
                    cout << "Build selected" << endl;
                    firstPass = true;
                    myCountry->buildArmy();
                    break;
                case 3:
                    cout << "Transport selected" << endl;
                    firstPass = true;
                    doCheck = true;
                    break;
                case 4:
                    firstPass = true;
                    doCheck = false;
                    break;
                default:
                    cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                    firstInput = playerTurn();
            }
        }
    }

    myCountry->showArmy();

    return 0;
}
