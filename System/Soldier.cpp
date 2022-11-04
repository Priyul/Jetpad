#include <iostream>
#include "Soldier.h"

Soldier :: Soldier(string type, double probability) {
    this->rank = type;
    this->probability = probability;
}

Soldier :: ~Soldier() {

}

void Soldier::setProbability(double p) {
    this->probability = p;
}

string Soldier :: getRank() {
    return this->rank;
}

double Soldier :: getProbability() {
    return this->probability;
}

string Soldier :: getType(){
    return "soldier";
}


Army* Soldier :: clone() {
    return this;
}