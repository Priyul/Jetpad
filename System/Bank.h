#ifndef BANK_H
#define BANK_H

using namespace std;

#include "Country.h"

class Bank {
public:

    void sendMoney(Country* c, double moneyToSend);
};

#endif