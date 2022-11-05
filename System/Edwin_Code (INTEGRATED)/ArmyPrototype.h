#ifndef ARMYPROTOTYPE_H
#define ARMYPROTOTYPE_H
using namespace std;

class ArmyPrototype {
    public:
        ArmyPrototype();
        ~ArmyPrototype();
        virtual ArmyPrototype* clone() = 0;
};

#endif