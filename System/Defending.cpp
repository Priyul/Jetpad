#include "Defending.h"

using namespace std;

Defending::~Defending() //Defending Destructor
{

}

//Land Defense Functions
LandDefense::LandDefense()
{

}

LandDefense LandDefense::handle()
{
    LandDefense landDefense;
    return landDefense;
}

LandDefense::~LandDefense()
{

}

//Air Defense Funcitons
void AirDefense::airDefense()
{

}

AirDefense AirDefense::handle()
{
    AirDefense airDefense;
    return airDefense;
}

AirDefense::~AirDefense()
{
    
}

//Sea Defense Functions
SeaDefense::SeaDefense()
{

}

SeaDefense SeaDefense::handle()
{
    SeaDefense seaDefense;
    return seaDefense;
}

SeaDefense::~SeaDefense()
{

}