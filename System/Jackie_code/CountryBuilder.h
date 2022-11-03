#ifndef COUNTRYBUILDER_H
#define COUNTRYBUILDER_H

#include <string>

#include "Builder.h"
#include "Country.h" 
#include "Army.h"

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

    int chooseArmyType();
    int chooseSoldierRank();
    int chooseVehicleType();
    int buyMoreSoldiers(int secondInput, string type);
    int chooseArmySize(string type);
    /* army creation*/

    Country* getCountry();
};


#endif
