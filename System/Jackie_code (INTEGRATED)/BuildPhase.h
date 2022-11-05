#ifndef BUILDPHASE_H
#define BUILDPHASE_H
#include "State.h"
#include "Country.h" 
#include<iostream>
#include<string>
using namespace std;

#include "Country.h"

class BuildPhase:public State{
    public:
    virtual void handleAction(Context* c);
        virtual string getState();
        
        Country* country;
        BuildPhase();
        // ~BuildPhase();
        int chooseArmyType();
        int chooseSoldierRank();
        int chooseVehicleType();
        int buyMoreSoldiers(int secondInput, string type);
        int chooseArmySize(string type);
        Country* getCountry();
};
#endif