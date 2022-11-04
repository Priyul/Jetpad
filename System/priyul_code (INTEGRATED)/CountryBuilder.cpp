#include "CountryBuilder.h"

CountryBuilder :: CountryBuilder() {
    this->country = new tempCountry();
}
    
void CountryBuilder :: buildName(string name) {
    this->country->setName(name);
}

void CountryBuilder :: buildArmy() {
    //interrate build army here
}

void CountryBuilder :: buildMoney(double money) {
    this->country->setMoney(money);
}

tempCountry* CountryBuilder :: getCountry() {
    return this->country;
}

