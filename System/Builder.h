#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include "Country.h"

using namespace std;

class Builder {
public:
    /**
     * @brief Construct a new Builder object
     * 
     */
    virtual void buildName(string name) = 0;

    /**
     * @brief Construct a new Builder object for army
     * 
    */
    virtual void buildArmy() = 0;

    /**
     * @brief Construct a new Builder object for money
     * 
    */
    virtual void buildMoney(double money) = 0;

    /**
     * @brief get the current country
     * 
     * @return Country*
     * 
    */
    virtual Country* getCountry() = 0;
}; 

#endif