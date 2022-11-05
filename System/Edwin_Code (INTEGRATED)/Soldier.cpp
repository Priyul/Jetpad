#include <iostream>
#include <string>
#include "Soldier.h"
using namespace std;

Soldier :: Soldier(string rank, double probability) {
    this->rank = rank;
    this->probability = probability;
}

Soldier::Soldier(const Soldier& soldier) {
    this->rank = soldier.rank;
    this->probability = soldier.probability;
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

ArmyPrototype* Soldier::clone() {
    return new Soldier(*this)
}