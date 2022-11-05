#ifndef COUNTRYOBSERVER_H
#define COUNTRYOBSERVER_H
#include "Country.h"
using namespace std;

class CountryObserver {
    private:
        Country* countryToObs;

    public: 
        CountryObserver();
        CountryObserver(Country* country); // constructer that initialises variables on creation
        ~CountryObserver();
        virtual void notify() = 0;
        Country* getCountry();
        void setCountry(Country* country);
}