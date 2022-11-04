#include "VehicleFactory.h"
#include "Army.h"
#include "Vehicle.h"

VehicleFactory :: VehicleFactory() {

}



Army* VehicleFactory :: create(string rank, double probability) {

    Army* obj = new Vehicle(rank, probability);
    return obj;
}