#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include "Country.h"

#include <vector>
#include <string>
#include <iostream>

class Originator{
private:
    Country* P1Country;
    Country* P2Country;
    
    vector<Country*> P1CountryVector;
    vector<Country*> P2CountryVector;

public:
    Originator(Country* c1, Country* c2, vector<Country*> v1, vector<Country*> v2);
    Country* getP1Country();
    Country* getP2Country();

    vector<Country*> getP1CountryVector();
    vector<Country*> getP2CountryVector();

};

#endif