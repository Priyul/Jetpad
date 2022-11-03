#ifndef COUNTRYBUILDER_H
#define COUNTRYBUILDER_H

#include <string>

#include "Builder.h"
#include "Country.h" 

using namespace std;

class CountryBuilder: public Builder {
private:
    //Country* country;

public:
    Country* country;

    CountryBuilder();
    ~CountryBuilder();

    void buildName(string name);
    void buildArmy();
    void buildMoney(double money);

    Country* getCountry();
};


#endif
