#include <iostream>
#include "Vehicle.h"

Vehicle :: Vehicle(string type, double probability) {
    this->type = type;
    this->probability = probability;
}

Vehicle :: ~Vehicle() {

}

void Vehicle::setProbability(double p) {
    this->probability = p;
}

string Vehicle :: getType() {
    return this->type;
}

double Vehicle :: getProbability() {
    return this->probability;
}

//SlAPPER
//dONT ADD THAT TO THE GITHUB