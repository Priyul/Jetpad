//
// Created by Ashir on 2022/10/29.
//

#ifndef ASHIR_CODE_FILES_COUNTRY_H
#define ASHIR_CODE_FILES_COUNTRY_H

#include <iostream>
#include <vector>

#include "Soldier.h"

class Country{
public:
    Country(std::string name, double money);

    std::string getCountryName();
    double getMoney();
    void buildArmy();
    void showArmy();
private:
    std::string name;
    std::vector<Soldier*> army;
    double money;
};

#endif //ASHIR_CODE_FILES_COUNTRY_H
