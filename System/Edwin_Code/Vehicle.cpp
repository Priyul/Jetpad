#include <iostream>
#include <string>
#include "Vehicle.h"
using namespace std;

Vehicle :: Vehicle(string type, double probability) {
    this->probability = probability;
    this->type = type;
}

Vehicle::Vehicle(const Vehicle& vehicle) {
    this->type = vehicle.type;
    this->probability = vehicle.probability;
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

ArmyPrototype* Vehicle::clone() {
    return new Vehicle(*this);
}