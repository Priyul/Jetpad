#ifndef TRANSPORTOBSERVER_H
#define TRANSPORTOBSERVER_H
#include "Transport.h"
using namespace std;

class TransportObserver {
    private:
        Transport* transportToObs;

    public: 
        TransportObserver();
        TransportObserver(Transport* transport); // constructer that initialises variables on creation
        ~TransportObserver();
        virtual void notify(double num) = 0;
        Transport* getTransport();
        void setTransport(Transport* transport);
};

#endif