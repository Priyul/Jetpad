#include <iostream>

#include "Country.h"
#include "Soldier.h"

using namespace std;

int playerTurn(){
    int firstInput;
    cout << "\033[1;31m" << "What would you like to do?" << "\033[0m" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Build army" << endl;
    cout << "3. Transport goods" << endl;
    cout << "4. Exit" << endl; //testing
    cin >> firstInput;
    return firstInput;
}

int main() {
    Country* america = new Country("America", 100000);

    bool doCheck = true;

    while(doCheck) {
        int firstInput = playerTurn();
        bool firstPass = false;

        while (!firstPass) {
            switch (firstInput) {
                case 1:
                    cout << "Attack selected" << endl;
                    firstPass = true;
                    doCheck = true;
                    break;
                case 2:
                    cout << "Build selected" << endl;
                    firstPass = true;
                    america->buildArmy();
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

    america->showArmy();

    return 0;
}
