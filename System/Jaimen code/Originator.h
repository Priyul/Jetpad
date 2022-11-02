#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#include "State.h"
#include "Memento.h"

class Originator{
    public:
        Originator(string, double);

        string getCountryName();
        void setCountryName(string);

        double getCountryMoney();
        void setCountryMoney(double);

        vector <Army> getCountryArmy();
        void setCountryArmy(vector <Army>);

    private:
        string countryName;
        double countryMoney;
        vector <Army> countryArmy;

};
#endif