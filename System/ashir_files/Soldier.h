//
// Created by Ashir on 2022/10/29.
//

#ifndef ASHIR_CODE_FILES_SOLDIER_H
#define ASHIR_CODE_FILES_SOLDIER_H

#include <iostream>

class Soldier {
public:
    Soldier(std::string rank);
    std::string getRank();
    double getProbability();
    void setProbability(double prob);
private:
    std::string rank;
    double probability{};
};


#endif //ASHIR_CODE_FILES_SOLDIER_H
