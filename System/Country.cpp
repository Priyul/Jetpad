#include <iostream>
#include "Country.h"

#include "Soldier.h"

#include "VehicleFactory.h"

#include <ctime> //for random number generation
#include <cstdlib> //for random number generation


//include strategy
#include "WarStrategy.h"
#include "Attacking.h"


using namespace std;


// Country :: Country(string name, double money) {
//     this->countryName = name;
//     this->money = money;
// }

Country :: Country() {
    this->isMainCountry = false;

    this->baseTransportRoute = new Route();
}

Country :: ~Country() {

}

string Country :: getCountryName() {
    return this->countryName;
}

double Country :: getMoney() {
    return this->money;
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

void Country :: setArmy(int numPlanes, int numTanks, int numShips, int numMajors, int numPrivates, int numSergeants) {

    this->soldierFactory = new SoldierFactory();
    this->vehicleFactory = new VehicleFactory();

    Army* templateMajor = this->soldierFactory->create("Major", 0.5);
    Army* templatePrivate = this->soldierFactory->create("Private", 0.5);
    Army* templateSergeant = this->soldierFactory->create("Sergeant", 0.5);

    for (int i = 0; i < numMajors; i++) {
        this->army.push_back(templateMajor->clone());
    }
    for (int i = 0; i < numPrivates; i++) {
        army.push_back(templatePrivate->clone());
    }
    for (int i = 0; i < numSergeants; i++) {
        army.push_back(templateSergeant->clone());
    }

    Army* templatePlane = this->vehicleFactory->create("Plane", 0.5);
    Army* templateTank = this->vehicleFactory->create("Tank", 0.5);
    Army* templateShip = this->vehicleFactory->create("Ship", 0.5);

    for (int i = 0; i < numPlanes; i++) {
        army.push_back(templatePlane->clone());
    }
    for (int i = 0; i < numTanks; i++) {
        army.push_back(templateTank->clone());
    }
    for (int i = 0; i < numShips; i++) {
        army.push_back(templateShip->clone());
    }

    if ((numPlanes == 0) && (numTanks == 0) && (numShips == 0) && (numMajors == 0) && (numPrivates == 0) && (numSergeants == 0)) {
        army.clear();
    }

}

void Country :: setCostOfCountry(double cost) {
    this->costOfCountry = cost;
}

double Country :: getCostOfCountry() {
    return this->costOfCountry;
}
