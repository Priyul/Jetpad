#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "Army.h"

using namespace std;

class Vehicle : public Army {
public:
    /**
     * @brief Constructor
     * 
     */
    Vehicle();
    /**
     * @brief Constructor and set vehicle's type and probability
     * 
     */
    Vehicle(string type, double probability);
    /**
     * @brief Destructor
     * 
     */
    ~Vehicle();

    /**
     * @brief Get the Rank object
     * 
     * @return ** string 
     */
    string getRank();
    /**
     * @brief Get the Type object
     * 
     * @return ** string 
     */
    string getType();

    /**
     * @brief Get the Probability object
     * 
     * @return ** double 
     */
    double getProbability();
    /**
     * @brief Set the Probability object
     * 
     * @param p 
     * @return ** void 
     */
    void setProbability(double p);

    /**
     * @brief Clone the Army object
     * 
     * @return ** Army* 
     */
    virtual Army* clone();
private:
    string type;
 
};


#endif