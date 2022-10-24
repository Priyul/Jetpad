#include <iostream>
#include "Soldier.h"

Soldier :: Soldier(string rank) {
    this->rank = rank;


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