#include "CountryObserver.h"
#include "Country.h"
using namespace std;

CountryObserver::CountryObserver() {
    
}

CountryObserver::CountryObserver(Country* country) {
    countryToObs = country;
}

CountryObserver::~CountryObserver() {

}

Country* CountryObserver::getCountry() {
    return countryToObs;
}

void CountryObserver::setCountry(Country* country) {
    countryToObs = country
}