#ifndef TRANSPORTDECORATOR_H
#define TRANSPORTDECORATOR_H

#include "Transport.h"

class TransportDecorator : public Transport{
private:
    Transport* transport;
public:
    /**
     * @brief Constructor and set Transport object
     * 
     * @param transport
     */
    TransportDecorator(Transport* transport);
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