#include <iostream>
#include "tempCountry.h"

using namespace std;

tempCountry :: tempCountry() {

}

/*tempCountry :: tempCountry(string name, double money) {
    this->countryName = name;
    this->money = money;
} */


string tempCountry :: getCountryName() {
    return this->countryName;
}

double tempCountry :: getMoney() {
    return this->money;
}

void tempCountry :: setName(string name) {
    this->countryName = name;
}

void tempCountry :: setMoney(double money) {
    this->money = money;
}

void tempCountry :: setArmy() {
    //implement
}





