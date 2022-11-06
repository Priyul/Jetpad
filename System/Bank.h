#ifndef BANK_H
#define BANK_H


#include "Country.h"

class Bank {
public:

    void sendMoney(Country* c, double moneyToSend);
};

#endif