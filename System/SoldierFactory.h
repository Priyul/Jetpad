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
     * @brief Create Army and set its rank and probability
     * 
     * @param rank 
     * @param probability 
     * @return ** Army* 
     */
    Army* create(string rank, double probability);
};

#endif