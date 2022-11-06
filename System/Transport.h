#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <iostream>

class Transport {
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Transport() {}
    /**
     * @brief Get the Description object
     * 
     * @return ** std::string 
     */
    virtual std::string getDescription() = 0;
    /**
     * @brief Set the Description object
     * 
     * @param description 
     * @return ** void 
     */
    virtual void setDescription(std::string description) = 0;
    /**
     * @brief Get the Money Gained object
     * 
     * @return ** double 
     */
    virtual double getMoneyGained() = 0;
    /**
     * @brief Set the Money Gained object
     * 
     * @param money 
     * @return ** void 
     */
    virtual void setMoneyGained(double money) = 0;
    /**
     * @brief Set the Turns To Skip object
     * 
     * @param turns 
     * @return ** void 
     */
    virtual void setTurnsToSkip(int turns) = 0;
    /**
     * @brief Get the Turns To Skip object
     * 
     * @return ** int 
     */
    virtual int getTurnsToSkip() = 0;
protected:
    double moneyGained;
    std::string routeDescription;
    int turnsToSkip;
};


#endif 