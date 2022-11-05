#include "CountryBuilder.h"

CountryBuilder :: CountryBuilder() {
    this->country = new Country();
    this->country->setCostOfCountry(0); //change according to values
}
    
void CountryBuilder :: buildName(string name) {
    this->country->setName(name);
}

void CountryBuilder :: buildArmy() {
    cout << this->country->getMoney() << endl;
  
    if (this->country->getCountryName() == "United States of America") {
        this->country->setArmy(20,20,35,10,50,20); 
        cout << "Country has a name " << this->country->getCountryName() << endl;
        //plane tank ship, major private sergeant
    } else if (this->country->getCountryName() == "Russia") {
        this->country->setArmy(10,40,10,20,40,15);
        //plane tank ship, major private sergeant
    } else if (this->country->getCountryName() == "China") {
        this->country->setArmy(35,20,10,25,20,0);
        //plane tank ship, major private sergeant
    } else if (this->country->getCountryName() == "United Kingdom") {
        this->country->setArmy(15,15,15,15,15,15);
        //plane tank ship, major private sergeant
    } else if (this->country->getCountryName() == "Japan") {
        this->country->setArmy(0,0,1,20,40,30);
        //plane tank ship, major private sergeant
    } else if (this->country->getCountryName() == "Canada") {
        this->country->setArmy(5,5,5,10,30,30);
        //plane tank ship, major private sergeant
    } else if (this->country->getCountryName() == "Australia") {
        this->country->setArmy(3,3,3,5,10,10);
        //plane tank ship, major private sergeant
    } else if (this->country->getCountryName() == "Egypt") {
        this->country->setArmy(0,5,2,5,5,5);
        //plane tank ship, major private sergeant
    } else if (this->country->getCountryName() == "Iraq") {
        this->country->setArmy(3,2,0,10,20,15);
        //plane tank ship, major private sergeant
    } else if (this->country->getCountryName() == "South Africa") {
        this->country->setArmy(2,3,0,10,25,20);
        //plane tank ship, major private sergeant
    } else if (this->country->getCountryName() == "Zimbabwe") {
        this->country->setArmy(1,1,1,5,20,10);
        //plane tank ship, major private sergeant
    } else if (this->country->getCountryName() == "Nepal") {
        this->country->setArmy(0,0,0,3,3,3);
        //plane tank ship, major private sergeant
    }

    //cout << endl << endl << "ARMY MADE" << endl << endl;
}

void CountryBuilder :: buildMoney(double money) {
    this->country->setMoney(money);
}

Country* CountryBuilder :: getCountry() {
    return this->country;
}

