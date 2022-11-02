#ifndef COUNTRYSPY_H
#define COUNTRYSPY_H
#include "CountryObserver.h"
#include "Bank.h"
#include "Country.h"
using namespace std;

class CountrySpy : public CountryObserver {
    private:
        Bank* BankList;
    
    public:
        CountrySpy();
        CountrySpy(Bank* bank); // constructer that initialises variables on creation
        ~CountrySpy();
        void notify();
        virtual void notifyBank(Country* country) = 0;
        Bank* getBankList();
        void setBankList(Bank* bank);
}