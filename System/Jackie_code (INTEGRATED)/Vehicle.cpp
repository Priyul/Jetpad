#include <iostream>
#include "Vehicle.h"

Vehicle :: Vehicle(string type, double probability) {
    this->probability = probability;
    this->type = type;
}

Vehicle :: ~Vehicle() {

}

string Vehicle :: getRank() {
    return this->type;
}

string Vehicle :: getType(){
    return "vehicle";
}

double Vehicle :: getProbability() {
    return this->probability;
}

void Vehicle::setProbability(double p) {
    this->probability = p;
}