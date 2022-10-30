#include <iostream>
#include "Army.h"

Army :: Army(string type, double probabiltiy) {
    this->type = type;
    this->probability = probability;
}

Army :: ~Army() {

}

string Army :: getType() {
    return this->type;
}

double Army :: getProbability() {
    return this->probability;
}


//1213