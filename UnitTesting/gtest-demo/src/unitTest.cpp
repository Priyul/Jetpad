#include "unitTest.h"
#include <cstdlib>
#include <random>

using namespace std;

double randomNumber(double prob)  
{
    double number = rand() % 100 + 1;  //Generate random number 1 to 100

    if (number <= prob*100) 
        return 1;
    else
        return 0;     
}

std::string getState(std::string) {
    return "(Choose Player phase.)";
}

std::string chooseArmyType(int input){

    if(input == 1){
        return "Build soldiers";
    }else if(input == 2){
        return "Build vehicles";
    } else {
        return "invalid selection";
    }
}

string chooseSoldierRank(int input){

    if(input == 1){
        return "Major [R 50 000]";
    }else if(input == 2){
        return "Sergeant [R 30 000]";
    } else if (input == 3) {
        return "Private [R 20 000]";
    }
     
    return "invalid selection";
    
}

string chooseVehicleType(int input){

    if(input == 1){
        return "Planes [R 200 000]";
    }else if(input == 2){
        return "Tanks [R 200 000]";
    } else if (input == 3) {
        return "Ships [R 200 000]";
    }
    return "invalid selection";
}
