#include "LandAttack.h"
#include "Defending.h"

LandAttack::LandAttack()
{

}

/*void Land_Attack::LandAttack()
{
     
} */

LandAttack* LandAttack::playerHandle(vector<Army*> AIVector, vector<Army*> OurArmyVector)
{
     //Defending* AIDefenseType;
     WarStrategy* AIDefense;
     Defending* def = new LandDefense();

     //random number between 0 & 2
     srand(time(NULL));
     int randNum = rand()%(2-0 + 1) + 0;

     switch(randNum){
          case 0:
               Defending* AirDefenseType1 = new LandDefense();

          case 1:
               Defending* AIDefenseType2 = new AirDefense();
     }

     LandAttack* GermanLand_Attack;

}

LandAttack::~LandAttack()
{

}