#include "SoldierFactory.h"
#include "Army.h"
#include "Soldier.h"

SoldierFactory :: ~SoldierFactory() {}

Army* SoldierFactory :: createSoldier(string type, double probability, string rank) {

    Army* obj = new Soldier(type, probability, rank);
    return obj;
}