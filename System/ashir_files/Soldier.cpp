//
// Created by Ashir on 2022/10/29.
//

#include "Soldier.h"

Soldier::Soldier(std::string rank) {
    this->rank = rank;
}

std::string Soldier::getRank() {
    return this->rank;
}

double Soldier::getProbability() {
    return this->probability;
}

void Soldier::setProbability(double prob) {
    this->probability = prob;
}