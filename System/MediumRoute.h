#ifndef MEDIUMROUTE_H
#define MEDIUMROUTE_H

#include "TransportDecorator.h"

class MediumRoute : public TransportDecorator{
public:
    /**
     * @brief Constructor and set Transport object
     * 
     * @param transport
     */
    MediumRoute(Transport* transport);
    /**
     * @brief Get the Description object
     * 
     * @return ** std::string 
     */
    std::string getDescription();
    /**
     * @brief Set the Description object
     * 
     * @param description 
     * @return ** void 
     */
    void setDescription(std::string description);
    /**
     * @brief Get the Money Gained object
     * 
     * @return ** double 
     */
    double getMoneyGained();
    /**
     * @brief Set the Money Gained object
     * 
     * @param money 
     * @return ** void 
     */
    void setMoneyGained(double money);
    /**
     * @brief Set the Turns To Skip object
     * 
     * @param turns 
     * @return ** void 
     */
    void setTurnsToSkip(int turns);
    /**
     * @brief Get the Turns To Skip object
     * 
     * @return ** int 
     */
    int getTurnsToSkip();
};


#endif