#ifndef SOLDIER_H
#define SOLDIER_H
#include <iostream>

#include "Army.h"

using namespace std;

class Soldier : public Army {
public:
    /**
     * @brief Constructor
     * 
     */
    Soldier();
    /**
     * @brief Constructor and set Soilder's type and probability
     * 
     * @param type
     * @param praobability
     */
    Soldier(string type, double probability);
    /**
     * @brief Destructor
     * 
     */
    ~Soldier();

    /**
     * @brief Get the Rank object
     * 
     * @return ** string 
     */
    string getRank();
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
     * @brief Get the Type object
     * 
     * @return ** string 
     */
    string getType();

    /**
     * @brief Clone the Army object
     * 
     * @return ** Army* 
     */
    virtual Army* clone();

private:
    string rank;

};

#endif