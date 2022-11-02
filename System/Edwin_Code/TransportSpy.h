#ifndef TRANSPORTSPY_H
#define TRANSPORTSPY_H
#include "TransportObserver.h"
#include "Bank.h"
#include "Transport.h"
using namespace std;

class TransportSpy : public TransportObserver {
    private:
        Bank* BankList;
    
    public:
        TransportSpy();
        TransportSpy(Bank* bank); // constructer that initialises variables on creation
        ~TransportSpy();
        void notify();
        virtual void notifyBank(Country* country) = 0;
        Bank* getBankList();
        void setBankList(Bank* bank);
}