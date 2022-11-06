#include "Engine.h"

Engine :: Engine(vector<Country*> P1CountryVector, vector<Country*> P2CountryVector) {
    this->P1CountryVector = P1CountryVector;
    this->P2CountryVector = P2CountryVector;

    this->isP1Turn = true;
    this->isP2Turn = false;
}

vector<Country*> Engine::whichPlayerTurn(){
    if(this->isP1Turn){
        return this->P1CountryVector;
    }else{
        return this->P2CountryVector;
    }
}

