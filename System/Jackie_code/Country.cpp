#include <iostream>
#include "Country.h"

#include "Soldier.h"

#include "VehicleFactory.h"

#include <ctime> //for random number generation
#include <cstdlib> //for random number generation

using namespace std;


Country :: Country() {
    
}

Country :: ~Country() {

}

string Country :: getCountryName() {
    return this->countryName;
}

double Country :: getMoney() {
    return this->money;
}

int chooseArmyType(){
    int input;
    cout << "\033[1;31m" << "Choose an army type:" << "\033[0m" << endl;
    cout << "1. Build soldiers" << endl;
    cout << "2. Build vehicles" << endl;
    cout << "select option: > ";
    cin >> input;
    return input;
}

int chooseSoldierRank(){
    int input;
    cout << "\033[1;31m" << "Choose soldier rank" << "\033[0m" << endl;
    cout << "1. Major [R 500]" << endl;
    cout << "2. Sergeant [R 100]" << endl;
    cout << "3. Private [R 50]" << endl;
    cout << "select option: > ";
    cin >> input;
    return input;
}

int chooseVehicleType(){
    int input;
    cout << "\033[1;31m" << "Choose vehicle type" << "\033[0m" << endl;
    cout << "1. Planes [R 10 000]" << endl;
    cout << "2. Tanks [R 10 000]" << endl;
    cout << "3. Ships [R 10 000]" << endl;
    cout << "select option: > ";
    cin >> input;
    return input;
}

int chooseArmySize(string type){
    int input;
    if(type == "soldier"){
        cout << "\033[1;31m" << "How many soldiers of this type would you like to make?" << "\033[0m" << endl;
    }else{
        cout << "\033[1;31m" << "How many vehicles of this type would you like to make?" << "\033[0m" << endl;
    }
    cout << "select option: > ";
    cin >> input;
    return input;
}

int buyMoreSoldiers(int secondInput, string type){

    int thirdInput;
    bool secondPass = false;

    if(type == "soldier"){
        while(!secondPass){
            switch (secondInput) {
                case 1:
                    cout << "Major selected" << endl;
                    thirdInput = chooseArmySize("soldier");
                    secondPass = true;
                    break;
                case 2:
                    cout << "Sergeant selected" << endl;
                    thirdInput = chooseArmySize("soldier");
                    secondPass = true;
                    break;
                case 3:
                    cout << "Private selected" << endl;
                    thirdInput = chooseArmySize("soldier");
                    secondPass = true;
                    break;
                default:
                    cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                    secondInput = chooseSoldierRank();
            }
        }
    }else if(type == "vehicle"){
        while(!secondPass){
            switch (secondInput) {
                case 1:
                    cout << "Plane selected" << endl;
                    thirdInput = chooseArmySize("vehicle");
                    secondPass = true;
                    break;
                case 2:
                    cout << "Tank selected" << endl;
                    thirdInput = chooseArmySize("vehicle");
                    secondPass = true;
                    break;
                case 3:
                    cout << "Ship selected" << endl;
                    thirdInput = chooseArmySize("vehicle");
                    secondPass = true;
                    break;
                default:
                    cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                    secondInput = chooseSoldierRank();
            }
        }
    }

    return thirdInput;
}

void Country::buildArmy() {

    char buyMore;

    ArmyFactory* soldierFactory = new SoldierFactory();
    ArmyFactory* vehicleFactory = new VehicleFactory();

    do{

        if(this->getMoney() > 50){
            int firstInput = chooseArmyType();
            bool firstPass = false;

            int secondInput;
            bool secondPass = false;

            while(!firstPass) {
                switch (firstInput) {
                    case 1:
                        cout << "Soldier selected" << endl;
                        secondInput = chooseSoldierRank();
                        firstPass = true;
                        break;
                    case 2:
                        cout << "Vehicle selected" << endl;
                        secondInput = chooseVehicleType();
                        firstPass = true;
                        break;
                    default:
                        cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                        firstInput = chooseArmyType();
                }
            }

            bool thirdPass = false;
            int thirdInput;

            string vehicleOrSoldier;

            if(firstInput == 1){
                thirdInput = buyMoreSoldiers(secondInput, "soldier");
                vehicleOrSoldier = "soldier";
            }else{
                thirdInput = buyMoreSoldiers(secondInput, "vehicle");
                vehicleOrSoldier = "vehicle";
            }

            while(!thirdPass){
                if(thirdInput < 0){ //chose a negative number for soldier or vehicle size
                    cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                    thirdInput = chooseArmySize(vehicleOrSoldier);
                }else if(thirdInput == 0){ //chose zero for soldier or vehicle size
                    if(vehicleOrSoldier == "soldier"){
                        cout << "\033[7;31m" << "No soldiers were bought" << "\033[0m" << endl;
                    }else{
                        cout << "\033[7;31m" << "No vehicles were bought" << "\033[0m" << endl;
                    }
                    thirdPass = true;
                }else{ //chose a positive value for soldier or vehicle size

                    if(vehicleOrSoldier == "soldier"){
                        if(secondInput == 1) { //rank is major
                            double cost = thirdInput * 500;
                            if(cost > this->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add soldiers to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->army.push_back(new Soldier("Major", 0.5));
                                }
                                this->money = this->money - cost;
                                cout << endl;
                                cout << "\033[1;32m" << "Soldiers have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        } else if(secondInput == 2)  { //rank is sergeant
                            double cost = thirdInput * 100;
                            if(cost > this->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add soldiers to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->army.push_back(new Soldier("Sergeant", 0.5));
                                }
                                this->money = this->money - cost;
                                cout << endl;
                                cout << "\033[1;32m" << "Soldiers have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        } else if(secondInput == 3) { //rank is private
                            double cost = thirdInput * 50;
                            if(cost > this->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add soldiers to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->army.push_back(new Soldier("Private", 0.5));
                                }
                                this->money = this->money - cost;
                                cout << endl;
                                cout << "\033[1;32m" << "Soldiers have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        }
                    }else if(vehicleOrSoldier == "vehicle"){
                        if(secondInput == 1) { //type is plane
                            double cost = thirdInput * 10000;
                            if(cost > this->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add vehicles to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->army.push_back(new Vehicle("Plane", 0));
                                }
                                this->money = this->money - cost;
                                cout << endl;
                                cout << "\033[1;32m" << "Planes have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        } else if(secondInput == 2)  { //type is tank
                            double cost = thirdInput * 10000;
                            if(cost > this->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add vehicles to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->army.push_back(new Vehicle("Tank", 0));
                                }
                                this->money = this->money - cost;
                                cout << endl;
                                cout << "\033[1;32m" << "Tanks have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        } else if(secondInput == 3) { //type is ship
                            double cost = thirdInput * 10000;
                            if(cost > this->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add soldiers to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->army.push_back(new Vehicle("Ship", 0));
                                }
                                this->money = this->money - cost;
                                cout << endl;
                                cout << "\033[1;32m" << "Ships have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        }
                    }
                    
                }
            }

            cout << "\033[1;33m" << "Would you like to purchase more troops? [Y/N]" << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> buyMore;
        }else{
            cout << "\033[7;31m" << "You do not have enough money to make more purchases of any kind" << "\033[0m" << endl;
            buyMore = 'N';
        }

    }while(toupper(buyMore) == 'Y');

}

void Country::countNumberOfIndividualTroops(vector<Army*> ourArmy){

    int tempMajorCount = 0;
    int tempSergeantCount = 0;
    int tempPrivateCount = 0;

    int tempPlaneCount = 0;
    int tempTankCount = 0;
    int tempShipCount = 0;

    for(int i=0; i < ourArmy.size(); i++){
        if(ourArmy[i]->getType() == "soldier"){
            if (ourArmy[i]->getRank() == "Major") {
                tempMajorCount++;
            } else if (ourArmy[i]->getRank() == "Sergeant") {
                tempSergeantCount++;
            } else if (ourArmy[i]->getRank() == "Private") {
                tempPrivateCount++;
            }
        }else if(ourArmy[i]->getType() == "vehicle"){
            if (ourArmy[i]->getRank() == "Plane") {
                tempPlaneCount++;
            } else if (ourArmy[i]->getRank() == "Tank") {
                tempTankCount++;
            } else if (ourArmy[i]->getRank() == "Ship") {
                tempShipCount++;
            }
        }
    }

    this->numberOfMajors = tempMajorCount;
    this->numberOfSergeants = tempSergeantCount;
    this->numberOfPrivates = tempPrivateCount;
    this->numberOfPlanes = tempPlaneCount;
    this->numberOfTanks = tempTankCount;
    this->numberOfShips = tempShipCount;
}

vector<Army*> Country::attack(){
    string CPUDefenseType;
    int CPUDefenseChoice;
    int AttackStrategyInput = -1;
    int ChooseNumberOfVehiclesToSend = -1;
    int ChooseNumberOfMajorsToSend;
    int ChooseNumberOfSergeantsToSend;
    int ChooseNumberOfPrivatesToSend;
    string vehicleChosenForAttack;

    //MAKE AI CHOOSE A DEFENSE:
    srand(time(0));  // Initialize random number generator.
    CPUDefenseChoice = (rand() % 3) + 0;

    if(CPUDefenseChoice == 0){
        CPUDefenseType = "LandDefense";
    }else if(CPUDefenseChoice == 1){
        CPUDefenseType = "AirDefense";
    }else if(CPUDefenseChoice == 2){
        CPUDefenseType = "SeaDefense";
    }else{
        cout << "Error in CPUDefenceChoice" << endl;
    }

    while(AttackStrategyInput != 1 && AttackStrategyInput != 2 && AttackStrategyInput != 3){
        cout << "\033[1;31m" << "Choose Attack strategy" << "\033[0m" << endl;
        cout << "1. Land Attack (You must own 1 or more Tanks)" << endl;
        cout << "2. Air Attack (You must own 1 or more Planes)" << endl;
        cout << "3. Sea Attack (You must own 1 or more Ships)" << endl;
        cout << "select option: > ";
        cin >> AttackStrategyInput;

        if(AttackStrategyInput != 1 && AttackStrategyInput != 2 && AttackStrategyInput != 3){
            cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
        }
    }

    switch (AttackStrategyInput)
    {
        case 1:
            vehicleChosenForAttack = "Tank";
            break;
        case 2:
            vehicleChosenForAttack = "Plane";
            break;
        case 3:
            vehicleChosenForAttack = "Ship";
            break;
    }
    
    if(vehicleChosenForAttack == "Tank"){
        if(this->numberOfTanks > 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack?" << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any tanks to make this kind of attack. Select a new attack strategy or build more tanks" << "\033[0m" << endl;
            return vector<Army*>();
        }
    }else if(vehicleChosenForAttack == "Plane"){
        if(this->numberOfPlanes > 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack?" << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any planes to make this kind of attack. Select a new attack strategy or build more planes" << "\033[0m" << endl;
            return vector<Army*>();
        }
    }else if(vehicleChosenForAttack == "Ship"){
        if(this->numberOfPlanes > 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack?" << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any ships to make this kind of attack. Select a new attack strategy or build more ships" << "\033[0m" << endl;
            return vector<Army*>();
        }
    }

    if(vehicleChosenForAttack == "Tank"){
        if(ChooseNumberOfVehiclesToSend > this->numberOfTanks){
            cout << "\033[7;31m" << "You do not have enough tanks to make this kind of attack. Select a new attack strategy or build more tanks" << "\033[0m" << endl;
            return vector<Army*>();
        }
    }else if(vehicleChosenForAttack == "Plane")

    cout << "\033[1;31m" << "How many Majors would you like to send for this attack?" << "\033[0m" << endl;
    cout << "select option: > ";
    cin >> ChooseNumberOfMajorsToSend;

    cout << "\033[1;31m" << "How many Sergeants would you like to send for this attack?" << "\033[0m" << endl;
    cout << "select option: > ";
    cin >> ChooseNumberOfSergeantsToSend;

    cout << "\033[1;31m" << "How many Privates would you like to send for this attack?" << "\033[0m" << endl;
    cout << "select option: > ";
    cin >> ChooseNumberOfPrivatesToSend;

}


void Country::showArmy() {

    int majorCount = 0;
    int sergeantCount = 0;
    int privateCount = 0;

    int planeCount = 0;
    int tankCount = 0;
    int shipCount = 0;

    for(int i=0; i<this->army.size(); i++){
        if(this->army[i]->getType() == "soldier"){
            if (this->army[i]->getRank() == "Major") {
                majorCount++;
            } else if (this->army[i]->getRank() == "Sergeant") {
                sergeantCount++;
            } else if (this->army[i]->getRank() == "Private") {
                privateCount++;
            }
        }else if(this->army[i]->getType() == "vehicle"){
            if (this->army[i]->getRank() == "Plane") {
                planeCount++;
            } else if (this->army[i]->getRank() == "Tank") {
                tankCount++;
            } else if (this->army[i]->getRank() == "Ship") {
                shipCount++;
            }
        }
    }

    cout << endl << "\033[1;33m" << "Your army has: " << "\033[0m" << endl;
    cout << "\033[1;33m" << majorCount << " Majors" << "\033[0m" << endl;
    cout << "\033[1;33m" << sergeantCount << " Sergeants" << "\033[0m" << endl;
    cout << "\033[1;33m" << privateCount << " Privates" << "\033[0m" << endl << endl;

    cout << "\033[1;33m" << planeCount << " Planes" << "\033[0m" << endl;
    cout << "\033[1;33m" << tankCount << " Tanks" << "\033[0m" << endl;
    cout << "\033[1;33m" << shipCount << " Ships" << "\033[0m" << endl;
}

void Country :: setName(string name) {
    this->countryName = name;
}
void Country :: setMoney(double money) {
    this->money = money;
}