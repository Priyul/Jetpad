#include "Engine.h"

Engine :: Engine(vector<Country*> P1CountryVector, vector<Country*> P2CountryVector) {
    this->P1CountryVector = P1CountryVector;
    this->P2CountryVector = P2CountryVector;

    this->isP1Turn = true;
    this->isP2Turn = false;
}

Country* Engine::whichPlayerTurnCountry(){
    if(this->isP1Turn){
        return this->P1SelectedCountry; 
    }else{
        return this->P2SelectedCountry;
    }
}

vector<Country*> Engine :: whichPlayerTurnVector() {
    if(this->isP1Turn){
        return this->P1CountryVector; 
    }else{
        return this->P2CountryVector;
    }
}

void Engine :: switchTurns() {
    if (this->isP1Turn == true) {
        this->isP1Turn = false;
        this->isP2Turn = true;
    } else {
        this->isP2Turn = false;
        this->isP1Turn = true;
    }
}

Country* Engine :: whichNotPlayerTurnCountry() {
    if(this->isP1Turn){
        return this->P2SelectedCountry; 
    }else{
        return this->P1SelectedCountry;
    }
}

vector<Country*> Engine :: whichNotPlayerTurnVector() {
    if(this->isP1Turn){
        return this->P2CountryVector; 
    }else{
        return this->P1CountryVector;
    }
}

string Engine :: printCurrentPlayer() {
    if (this->isP1Turn) {
        return "P1";
    } else {
        return "P2";
    }
}

string Engine :: printNotCurrentPlayer() {
    if (this->isP1Turn) {
        return "P2";
    } else {
        return "P1";
    }
}



Memento* Engine :: backup() {
    Originator* originator = new Originator(this->P1SelectedCountry, this->P2SelectedCountry, this->P1CountryVector, this->P2CountryVector);
    return new Memento(originator);
}

void Engine :: restore(Memento* m) {
    Originator* originator = m->getOriginator();

    this->P1SelectedCountry = originator->getP1Country();
    this->P2SelectedCountry = originator->getP2Country();

    this->P1CountryVector = originator->getP1CountryVector();
    this->P2CountryVector = originator->getP2CountryVector();
}