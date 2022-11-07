#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include "ArmyFactory.h"

class SoldierFactory : public ArmyFactory {
public:
    /**
     * @brief Constructor
     * 
     */
    SoldierFactory();
    //~SoldierFactory();
    /**
     * @brief Create object of type soldier
     * 
     * @param rank 
     * @param probability 
     * @return ** Army* 
     */
    Army* create(string rank, double probability);
};

#endif