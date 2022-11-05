#ifndef COUNTRY_H
#define COUNTRY_H
#include "Country.h"
using namespace std;

class Engine {
    public:
        Country* p1;
        Country* p2;

        Engine();
        ~Engine();

        void assignP1(Country* country);
        void assignP2(Country* country);
};

#endif