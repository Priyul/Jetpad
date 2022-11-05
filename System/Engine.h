#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <vector>

#include "Country.h"

class Engine {

public:
    Engine(vector<Country*> P1CountryVector, vector<Country*> P2CountryVector);
    ~Engine();

    vector<Country*> P1CountryVector;
    vector<Country*> P2CountryVector;

    Country* P1SelectedCountry;
    Country* P2SelectedCountry;
};

#endif