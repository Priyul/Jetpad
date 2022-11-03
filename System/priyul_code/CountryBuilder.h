#ifndef COUNTRYBUILDER_H
#define COUNTRYBUILDER_H

#include <string>

#include "Builder.h"
#include "tempCountry.h" //change

using namespace std;

class CountryBuilder: public Builder {
private:
    //tempCountry* country;

public:
    tempCountry* country;

    CountryBuilder();
    ~CountryBuilder();

    void buildName(string name);
    void buildArmy();
    void buildMoney(double money);

    tempCountry* getCountry();
};


#endif



    // for (int i = 0; i < 12; i++) {
    //     countryBuilder = new CountryBuilder();
    //     Director* cDirector = new Director(countryBuilder);
    //     cDirector->countryBuilder->buildName(countryNames[i]));
    //     cDirector->countryBuilder->buildMoney(countryMoney[i]);
    //     //cDirector->buildArmy(); // ->>implement

    //     tempCountry* newCountry = cDirector->countryBuilder->getCountry();
    //     countriesArray.push_back(newCountry);
    //     cout << newCountry->getCountryName() << endl; //testing
    // }