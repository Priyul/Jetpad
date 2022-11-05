#include <iostream>
#include "Country.h"

#include "Soldier.h"

#include "VehicleFactory.h"

#include <ctime> //for random number generation
#include <cstdlib> //for random number generation


//include strategy
#include "WarStrategy.h"
#include "Attacking.h"

//including decorator transportation
#include "ShortRoute.h"
#include "MediumRoute.h"
#include "LongRoute.h"

using namespace std;


// Country :: Country(string name, double money) {
//     this->countryName = name;
//     this->money = money;
// }

Country :: Country() {
    this->baseTransportRoute = new Route;
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
    cout << "1. Major [R 5000]" << endl;
    cout << "2. Sergeant [R 3500]" << endl;
    cout << "3. Private [R 1500]" << endl;
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
                    secondInput = chooseVehicleType();
            }
        }
    }

    return thirdInput;
}

// done
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
                        cout << "test: " << secondInput << endl;
                        cout << "test: " << thirdInput << endl;
                        if(secondInput == 1) { //rank is major
                            double cost = thirdInput * 5000;
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
                            double cost = thirdInput * 3500;
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
                            double cost = thirdInput * 1500;
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

string Country::attack(){

    countNumberOfIndividualTroops(this->army);
    
    string CPUDefenseType;
    int CPUDefenseChoice;
    int AttackStrategyInput = -1;
    int ChooseNumberOfVehiclesToSend = -1;
    int ChooseNumberOfMajorsToSend = 0;
    int ChooseNumberOfSergeantsToSend = 0;
    int ChooseNumberOfPrivatesToSend = 0;

    string vehicleChosenForAttack;
    string PlayerAttackType;

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
            PlayerAttackType = "LandAttack";
            break;
        case 2:
            vehicleChosenForAttack = "Plane";
            PlayerAttackType = "AirAttack";
            break;
        case 3:
            vehicleChosenForAttack = "Ship";
            PlayerAttackType = "SeaAttack";
            break;
    }
    
    if(vehicleChosenForAttack == "Tank"){
        if(this->numberOfTanks >= 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->numberOfTanks << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any tanks to make this kind of attack. Select a new attack strategy or build more tanks " << "\033[7;32m" << "Available: "  << this->numberOfTanks << "\033[0m" << endl;
            return "notanks";
        }
    }else if(vehicleChosenForAttack == "Plane"){
        if(this->numberOfPlanes >= 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->numberOfPlanes << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any planes to make this kind of attack. Select a new attack strategy or build more planes " << "\033[7;32m" << "Available: "  << this->numberOfPlanes << "\033[0m" << endl;
            return "noplanes";
        }
    }else if(vehicleChosenForAttack == "Ship"){
        if(this->numberOfShips >= 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->numberOfShips << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any ships to make this kind of attack. Select a new attack strategy or build more ships " << "\033[7;32m" << "Available: "  << this->numberOfShips << "\033[0m" << endl;
            return "noships";
        }
    }

    if(vehicleChosenForAttack == "Tank"){
        if(ChooseNumberOfVehiclesToSend > this->numberOfTanks){
            cout << "\033[7;31m" << "You do not have enough tanks to make this kind of attack. Select a new attack strategy or build more tanks " << "\033[7;32m" << "Available: "  << this->numberOfTanks << "\033[0m" << endl;
            return "insuffecientTanks";
        }
    }else if(vehicleChosenForAttack == "Plane"){
        if(ChooseNumberOfVehiclesToSend > this->numberOfPlanes){
            cout << "\033[7;31m" << "You do not have enough planes to make this kind of attack. Select a new attack strategy or build more planes " << "\033[7;32m" << "Available: "  << this->numberOfPlanes << "\033[0m" << endl;
            return "insuffecientPlanes";
        }
    }else if(vehicleChosenForAttack == "Ship"){
        if(ChooseNumberOfVehiclesToSend > this->numberOfShips){
            cout << "\033[7;31m" << "You do not have enough ships to make this kind of attack. Select a new attack strategy or build more ships " << "\033[7;32m" << "Available: "  << this->numberOfShips << "\033[0m" << endl;
            return "insuffecientShips";
        }
    }

    if(this->numberOfMajors > 0){
        cout << "\033[1;31m" << "How many Majors would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->numberOfMajors << "\033[0m" << endl;
        cout << "select option: > ";
        cin >> ChooseNumberOfMajorsToSend;

        if(ChooseNumberOfMajorsToSend > this->numberOfMajors){
            cout << "\033[7;31m" << "You do not have enough majors to make this kind of attack. Pick fewer mages to send to war or make more majors instead " << "\033[7;32m" << "Available: "  << this->numberOfMajors << "\033[0m" << endl;
            return "insuffecientMajors";
        }
    }

    if(this->numberOfSergeants > 0){
        cout << "\033[1;31m" << "How many Sergeants would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->numberOfSergeants << "\033[0m" << endl;
        cout << "select option: > ";
        cin >> ChooseNumberOfSergeantsToSend;

        if(ChooseNumberOfSergeantsToSend > this->numberOfSergeants){
            cout << "\033[7;31m" << "You do not have enough sergeants to make this kind of attack. Pick fewer sergeants to send to war or make more sergeants instead " << "\033[7;32m" << "Available: "  << this->numberOfSergeants << "\033[0m" << endl;
            return "insuffecientSergeants";
        }
    }

    if(this->numberOfPrivates > 0){
        cout << "\033[1;31m" << "How many Privates would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->numberOfPrivates << "\033[0m" << endl;
        cout << "select option: > ";
        cin >> ChooseNumberOfPrivatesToSend;

        if(ChooseNumberOfPrivatesToSend > this->numberOfPrivates){
            cout << "\033[7;31m" << "You do not have enough privates to make this kind of attack. Pick fewer privates to send to war or make more privates instead " << "\033[7;32m" << "Available: "  << this->numberOfPrivates << "\033[0m" << endl;
            return "insuffecientPrivates";
        }
    }


    vector<Army*> aiArmy;    //testing begin

    for(int i=0; i<20; i++){
        aiArmy.push_back(new Soldier("Private", 0.5));
    }

    for(int i=0; i<10; i++){
        aiArmy.push_back(new Soldier("Major", 0.5));
    }

    for(int i=0; i<40; i++){
        aiArmy.push_back(new Soldier("Sergeant", 0.5));
    }

    for(int i=0; i<3; i++){
        aiArmy.push_back(new Vehicle("Ship", 0));
    }

    for(int i=0; i<5; i++){
        aiArmy.push_back(new Vehicle("Tank", 0));
    }

    for(int i=0; i<aiArmy.size(); i++){
        cout << "aiArmy at: " << i << " " << aiArmy[i]->getRank() << endl;
    }

    WarStrategy* attackStrategy = new Attacking();
    
    cout << CPUDefenseType << endl;

    attackStrategy->handle(this->army, aiArmy, PlayerAttackType, CPUDefenseType, ChooseNumberOfVehiclesToSend, ChooseNumberOfMajorsToSend, ChooseNumberOfSergeantsToSend, ChooseNumberOfPrivatesToSend);

    cout << "after attack" << endl;
    for(int i=0; i<this->army.size(); i++){
        cout << "Our army after attack: " << this->army[i]->getRank() << endl;
    }

    for(int i=0; i<aiArmy.size(); i++){
        cout << "Ai army after attack: " << aiArmy[i]->getRank() << endl;  //testing end
    }

    return "attackSuccess";
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

vector<Army*> Country :: getArmy() {
    return this->army;
}

void Country::addRoute(){
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

    //remember to set the money for after the transportation succeeds
    std::cout << endl << "Active transport operations:" << std::endl;
    if(input == 1){
        Transport* shortRoute = new ShortRoute(this->baseTransportRoute);
        cout << shortRoute->getDescription() << endl;
        cout << "Amount: " << shortRoute->getMoneyGained() << endl;
        cout << "Number of turns to skip: " << shortRoute->getTurnsToSkip() << endl; //so to use the skip turn feature, we iterate through the array of 6 countries and call this method for each country. If the method returns a value greater than 0, the next player will play their turn
    }else if(input == 2){
        Transport* mediumRoute = new MediumRoute(this->baseTransportRoute);
        cout << mediumRoute->getDescription() << endl;
        cout << "Amount: " << mediumRoute->getMoneyGained() << endl;
        cout << "Number of turns to skip: " << mediumRoute->getTurnsToSkip() << endl;
    }else if(input == 3){
        Transport* longRoute = new LongRoute(this->baseTransportRoute);
        cout << longRoute->getDescription() << endl;
        cout << "Amount: " << longRoute->getMoneyGained() << endl;
        cout << "Number of turns to skip: " << longRoute->getTurnsToSkip() << endl;
    }
}