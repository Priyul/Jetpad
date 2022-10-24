#include <iostream>
#include "Country.h"

Country :: Country(string name, double money) {
    this->countryName = name;
    this->money = money;
}

Country :: ~Country() {

}

string Country :: getCountryName() {
    return this->countryName;
}

double Country :: getMoney() {
    return this->money;
}

int chooseSize(string rank){
    cout << "How many soldiers of rank " << rank << " do you want to make?" << endl;
    int inputSize;

    cin >> inputSize;

    return inputSize;
}

void Country :: soldierInput(int input){

    int size = 0;
    switch (input)
    {
        case 1:
            size = chooseSize("major");
            break;
        default:
            break;
    }
}

void Country :: buildArmy(){
    cout << "Choose army type: " << endl;
    cout << "1. Build soldiers" << endl;
    cout << "2. Build vehicles" << endl;
    int input = 0;

    cin >> input;

    int sInput;

    switch (input) {
        case 1:
            cout << "Choose soldier rank: " << endl;
            cout << "1.  Major [R 500] " << endl;
            cout << "2.  Sergeant [R 100]" << endl;
            cout << "3.  Private [R 50]" << endl; //check

            sInput = 0;

            cin >> sInput;

            soldierInput(sInput);    
            break;
        default:
            break;
    }
}