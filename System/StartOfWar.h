#ifndef STARTOFWAR_H
#define STARTOFWAR_H
#include "State.h"
//#include "Country.h"
// #include "Context.h"
#include "Engine.h"

#include<iostream>
#include<string>


/* BUILDER INTEGRATON */
#include "Director.h"
#include "CountryBuilder.h"
#include "Country.h"
/* END OF BUILDER INTEGRATON */
#include "Bank.h"   
#include "ChoosePlayerPhase.h"

using namespace std;
// class State{};
// class Context;

class StartOfWar : public State {
public:
    /**
     * @brief Implement the start of war, which choose the country and choose the ally countries
     * 
     * @param c 
     * @return ** void 
     */
    virtual void handleAction(Context* c);
    /**
     * @brief Get the State object
     * 
     * @return ** string 
     */
    virtual string getState();

    /* BUILDER INTEGRATION */
    CountryBuilder* countryBuilder;
    //void buildCountry(string countryName, double money);
    /**
     * @brief Build country and set its name and money
     * 
     * @param countryName 
     * @param money 
     * @return ** Country* 
     */
    Country* buildCountry(string countryName, double money);

    /**
     * @brief Get the Country object
     * 
     * @return ** Country* 
     */
    Country* getmyCountry();
    /**
     * @brief Get the Ally Country object
     * 
     * @return ** Country* 
     */
    Country* getAllyCountry();

    /**
     * @brief Show all available allies
     * 
     * @param allyCountries 
     * @return ** void 
     */
    void showAvailableAllies(vector<Country*> allyCountries);

private:
    Country* myCountry;
    Country* allyCountry;

};

#endif