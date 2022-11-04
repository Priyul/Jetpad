#include "Director.h"
#include "CountryBuilder.h"
#include "tempCountry.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
    CountryBuilder* cBuilder = new CountryBuilder(); //incorporated

    Director* cDirector = new Director(cBuilder);

    cDirector->countryBuilder->buildName("South Africa");
    cDirector->countryBuilder->buildMoney(10000);
    //cDirector->buildArmy(); // ->>implement

    tempCountry* ourCountry = cDirector->countryBuilder->getCountry();

    cout << ourCountry->getCountryName() << endl;
    cout << ourCountry->getMoney() << endl;

    return 0;
}