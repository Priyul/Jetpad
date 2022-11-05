#ifndef STARTOFWAR_H
#define STARTOFWAR_H
#include "State.h"
//#include "Country.h"
// #include "Context.h"
#include<iostream>
#include<string>


/* BUILDER INTEGRATON */
#include "Director.h"
#include "CountryBuilder.h"
#include "Country.h"
/* END OF BUILDER INTEGRATON */


using namespace std;
// class State{};
// class Context;

class StartOfWar : public State {
public:

    virtual void handleAction(Context* c);
    virtual string getState();

    /* BUILDER INTEGRATION */
    CountryBuilder* countryBuilder;
    //void buildCountry(string countryName, double money);
    Country* buildCountry(string countryName, double money);

    Country* getmyCountry();
    Country* getAllyCountry();

    void showAvailableAllies(vector<Country*> allyCountries);

private:
    Country* myCountry;
    Country* allyCountry;

};

#endif