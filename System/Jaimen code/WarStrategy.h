#ifndef WARSTRATEGY_H
#define WARSTRATEGY_H

#include "Soldier.h"
#include "Vehicle.h"

using namespace std;

class WarStrategy
{
    public:
        WarStrategy();
        ~WarStrategy();

        virtual void setStrategy(int); // 1 = Offensive, 2 = Defensive
        virtual int getStrategy();

        virtual void setTotalTroops(int);
        virtual int getTotalTroops();

        // virtual void setVehicle(int); // 1 = Tank, 2 = Plane, 3 = Ship
        // virtual int getVehicle();

    private:
        int strategy;
        int totalTroops;

};
#endif
