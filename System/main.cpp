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

int playerTurnOutput(){
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
    Context* currContext = new Context();
    StartOfWar* currentState = new StartOfWar();
    currentState->handleAction(currContext);

    // Country* myCountry = currentState->getmyCountry();
    // Country* allyCountry = currentState->getAllyCountry();
    

    
    return 0;
}
