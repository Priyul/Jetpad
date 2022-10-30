#include <iostream>
#include "Soldier.h"

using namespace std;

Soldier::Soldier()
{
    this->rank = "Private";
    this->probability = 0.0;
}

Soldier :: Soldier(string type, double probability, string rank) :
    Army(type, probability)
{this->rank = rank;}


Soldier :: ~Soldier() {

}

string Soldier :: getRank() {
    return this->rank;
}
