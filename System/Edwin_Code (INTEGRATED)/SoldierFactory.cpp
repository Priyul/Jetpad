#include "SoldierFactory.h"
#include "Army.h"
#include "Soldier.h"

SoldierFactory :: SoldierFactory() {

}



Army* SoldierFactory :: create(string rank, double probability) {

    Army* obj = new Soldier(rank, probability);
    return obj;
}