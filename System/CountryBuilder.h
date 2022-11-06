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

    /**
     * @brief Construct a new Country Builder object
     * 
    */
    CountryBuilder();

    /**
     * @brief Destroy the Country Builder object
     * 
    */
    ~CountryBuilder();

    /**
     * @brief Set the Name object
     * 
     * @param name 
    */
    void buildName(string name);

    /**
     * @brief set country armies
     * 
     * 
    */
    void buildArmy();

    /**
     * @brief Set the Money object
     * 
     * @param money 
    */
    void buildMoney(double money);

    /**
     * @brief select the type of army
     * 
     * 
    */
    int chooseArmyType();

    /**
     * @brief select the type of soldier
     * 
     * @return int
    */
    int chooseSoldierRank();

    /**
     * @brief select type of vehicle
     * 
     *  @return int
    */
    int chooseVehicleType();

    /**
     * @brief purchase more soldiers
     * @param secondInput
     * @param type
     * @return int 
    */
    int buyMoreSoldiers(int secondInput, string type);

    /**
     * @brief army creation
     * @param type
     * @return int
    */
    int chooseArmySize(string type);
    /* army creation*/

    Country* getCountry();
};


#endif
