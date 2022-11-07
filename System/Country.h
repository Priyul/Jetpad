#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <vector>

using namespace std;

#include "Army.h"
#include "SoldierFactory.h"
#include "VehicleFactory.h"
//#include "ArmyFactory.h"

#include "Soldier.h"
#include "Vehicle.h"

#include "Route.h"

using namespace std;

class Country {
public:
    /**
     * @brief Construct a new Country object
    */
    Country();
    //Country(string name, double money); we dont need this anymore because the builder sorts everything out

    /**
     * @brief destroy a Country object
    */
    ~Country();

    /**
     * @brief Get the Name of the country object
     * 
     * @return string 
    */
    string getCountryName();

    /**
     * @brief Get the Money of the country object
     * 
     * @return double 
    */
    double getMoney();

    vector<Army*> army; //move to private eventually
    // void buildArmy();
    void showArmy();

    /**
     * @brief Get the Army object
     * 
     * @return vector<Army*> 
     */
    vector<Army*> getArmy();

    /**
     * @brief Set the Army object
     * 
     * @param numPlanes 
     * @param numTanks 
     * @param numShips 
     * @param numMajors 
     * @param numPrivates 
     * @param numSergeants 
     */
    void setArmy(int numPlanes, int numTanks, int numShips, int numMajors, int numPrivates, int numSergeants);

    /**
     * @brief set number of troops foreach country
     * 
     * @param ourArmy 
     */
    void countNumberOfIndividualTroops(vector<Army*> ourArmy);
    // void soldierInput(int input);

    /**
     * @brief set the name of the country
     * 
     * @param name 
     */
    void setName(string name);
    /**
     * @brief Set the Money variable
     * 
     * @param money 
     */
    void setMoney(double money);

    /**
     * @brief Set the Cost Of Country object
     * 
     * @param cost 
     */
    void setCostOfCountry(double cost);

    /**
     * @brief Get the Cost Of Country object
     * 
     * @return double 
     */
    double getCostOfCountry();

    /**
     * @brief Set the Soldier Factory object
     * 
     * @param soldierFactory 
     */
    void setSoldierFactory(ArmyFactory* soldierFactory);

    /**
     * @brief Set the Vehicle Factory object
     * 
     * @param vehicleFactory 
     */
    void setVehicleFactory(ArmyFactory* vehicleFactory);

    void resetArmy(vector<Army*> a);

    int numberOfMajors;
    int numberOfSergeants;
    int numberOfPrivates;

    int numberOfTanks;
    int numberOfPlanes;
    int numberOfShips;

    bool isMainCountry; 


    Transport* baseTransportRoute;

    string whichPlayer;

    bool hasLost;

    int getTurnsToSkip();
    void setTurnsToSkip(int i);

protected:



private:
    double money;
    string countryName;

    ArmyFactory* soldierFactory;
    ArmyFactory* vehicleFactory;

    double costOfCountry;

    int turnsToSkip;
};

#endif