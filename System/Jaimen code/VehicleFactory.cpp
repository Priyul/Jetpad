#include "VehicleFactory.h"
#include "Army.h"
#include "Vehicle.h"

VehicleFactory :: ~VehicleFactory() {}

Army* VehicleFactory :: createVehicle(string type, double probability) {

    Army* obj = new Vehicle(type, probability);
    return obj;
}

//SlAPPER
//dONT ADD THAT TO THE GITHUB