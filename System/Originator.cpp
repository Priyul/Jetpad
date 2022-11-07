#include "Originator.h"
using namespace std;

Originator :: Originator(Country* c1, Country* c2, vector<Country*> v1, vector<Country*> v2) {
    this->P1Country = c1;
    this->P2Country = c2;
    
    this->P1CountryVector = v1;
    this->P2CountryVector = v2;
}

Country* Originator :: getP1Country() {
    return this->P1Country;
}

Country* Originator :: getP2Country() {
    return this->P2Country;
}

vector<Country*> Originator :: getP1CountryVector() {
    return this->P1CountryVector;
}

vector<Country*> Originator :: getP2CountryVector() {
    return this->P2CountryVector;
}