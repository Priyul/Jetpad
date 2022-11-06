#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <vector>

#include "Country.h"

#include "Bank.h"

class Engine {

public:
    Engine(vector<Country*> P1CountryVector, vector<Country*> P2CountryVector);
    ~Engine();

    vector<Country*> P1CountryVector;
    vector<Country*> P2CountryVector;

    Country* P1SelectedCountry;
    Country* P2SelectedCountry;

    Country* whichPlayerTurnCountry();
    vector<Country*> whichPlayerTurnVector();

    Country* whichNotPlayerTurnCountry();
    vector<Country*> whichNotPlayerTurnVector();

    Bank* bank;

    void switchTurns();

    string printCurrentPlayer();
    string printNotCurrentPlayer();

    bool isP1Turn;
    bool isP2Turn;

private:
    // bool isP1Turn;
    // bool isP2Turn;


};

#endif