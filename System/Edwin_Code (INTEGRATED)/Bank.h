#ifndef BANK_H
#define BANK_H
#include "Country.h"
using namespace std;

class Bank {
    public:
        Bank();
        ~Bank();
        double get();
        void set(double num);
        void notifyBank(double num);
};

#endif