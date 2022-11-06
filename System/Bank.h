#ifndef BANK_H
#define BANK_H


#include "Country.h"

class Bank {
public:
    /**
     * @brief Transfers money from one country to another
     * 
     */
    void sendMoney(Country* c, double moneyToSend);
};

#endif