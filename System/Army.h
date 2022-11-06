#ifndef ARMY_H
#define ARMY_H

#include <iostream>

using namespace std;

class Army {
protected:
    double probability;
public:

    /**
     * @brief get the rank
     * 
    */
    virtual string getRank() = 0; //return rank of soldier || type of plane

    /**
     * @brief get the type
     * 
    */
    virtual string getType() = 0;

    /**
     * @brief get the probability
     * 
    */
    virtual double getProbability() = 0;

    /**
     * @brief set the probability of soliders and vehicles
     * 
    */
    virtual void setProbability(double p) = 0;

    /**
     * @brief clone soldiers and vehicles
     * 
    */
    virtual Army* clone() = 0;
};

#endif