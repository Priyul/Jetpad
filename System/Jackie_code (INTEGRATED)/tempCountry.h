#ifndef TEMPCOUNTRY_H
#define TEMPCOUNTRY_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class tempCountry {
public:

    tempCountry();
    //tempCountry(string name, double money); 
    ~tempCountry();

    string getCountryName();
    double getMoney();

    void setName(string name);
    void setMoney(double money);
    void setArmy(); //implement

private:
    double money;
    string countryName;

    //void setName(string name);
    //void setMoney(double money);
    //void setArmy(); //implement

};

#endif