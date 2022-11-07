#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <vector>

#include "Country.h"

#include "Bank.h"

class Engine {

public:
    /**
     * @brief Construct a new Engine object
     * @param P1CountryVector
     * @param P2CountryVector
     */
    Engine(vector<Country*> P1CountryVector, vector<Country*> P2CountryVector);

    /**
     * @brief Destroy the Engine object
     */
    ~Engine();

    vector<Country*> P1CountryVector;
    vector<Country*> P2CountryVector;

    Country* P1SelectedCountry;
    Country* P2SelectedCountry;

    /**
     * @brief get which players turn it is
     * @return Country*
     */
    Country* whichPlayerTurnCountry();
    vector<Country*> whichPlayerTurnVector();

    /**
     * @brief get the player who turn it is not
     * @return Country*
     */
    Country* whichNotPlayerTurnCountry();
    vector<Country*> whichNotPlayerTurnVector();

    Bank* bank;

    /**
     * @brief switch turns between players
     * 
     */
    void switchTurns();

    /**
     * @brief print the player whos turn it is
     * @return string
     */
    string printCurrentPlayer();

    /**
     * @brief print the player whos turn it is not
     * @return string
     */
    string printNotCurrentPlayer();

    bool isP1Turn;
    bool isP2Turn;

    // int P1TurnsToSkip;
    // int P2TurnsToSkip;

private:
    // bool isP1Turn;
    // bool isP2Turn;


};

#endif