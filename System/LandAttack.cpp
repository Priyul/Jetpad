#include "LandAttack.h"

LandAttack::LandAttack(){
     std::cout << "Land attack constructor called";
}

double randomNumber(double prob)  
{
    srand(time(NULL));
    double number = rand() % 100 + 1;  //Generate random number 1 to 100

    if (number <= prob*100) 
        return 1;
    else
        return 0;
                
}


void LandAttack::handle(vector<Army*> ourArmy, vector<Army*> AIArmy){

    int numberOfAttackers = 0;
    int numberOfDefenders = 0;

    int numberOfAttackingVehicles = 0;
    int numberOfDefendingVehicles = 0;

    for (int i = 0; i < ourArmy.size(); i++) {
        if(ourArmy[i]->getType() == "soldier") {
        numberOfAttackers++;
        } else {
            numberOfAttackingVehicles++;
        }
    }

    for(int i=0; i<AIArmy.size(); i++){
        if(AIArmy[i]->getType() == "soldier"){
        numberOfDefenders++;
        }else{
        numberOfDefendingVehicles++;
        }
    }

    int attCounter = 0;
    int defendCounter = 0;


    //for the soldiers fighting
    while (numberOfAttackers >= 0 && numberOfDefenders >= 0) {


        while(ourArmy[attCounter]->getType() != "soldier"){
           attCounter++;
        }

        while(AIArmy[defendCounter]->getType() != "soldier"){
            defendCounter++;
        }


        string attRank = ourArmy[attCounter]->getRank();

        string defRank = AIArmy[defendCounter]->getRank();

        if (attRank == "Major")  {

            switch(defRank[0]) {
                case 'M':
                    ourArmy[attCounter]->setProbability(0.5);
                    AIArmy[defendCounter]->setProbability(0.5);
                    break;
                case 'P':
                    ourArmy[attCounter]->setProbability(0.85);
                    AIArmy[defendCounter]->setProbability(0.15);
                    break;
                case 'S':
                    ourArmy[attCounter]->setProbability(0.6);
                    AIArmy[defendCounter]->setProbability(0.4);
                    break;
                default:
                    ourArmy[attCounter]->setProbability(0);
                    AIArmy[defendCounter]->setProbability(0);
                    break;
            }

        } else if (attRank == "Private") {
            switch(defRank[0]) {
                case 'M':
                    ourArmy[attCounter]->setProbability(0.15);
                    AIArmy[defendCounter]->setProbability(0.85);
                    break;
                case 'P':
                    ourArmy[attCounter]->setProbability(0.5);
                    AIArmy[defendCounter]->setProbability(0.5);
                    break;
                case 'S':
                    ourArmy[attCounter]->setProbability(0.4);
                    AIArmy[defendCounter]->setProbability(0.6);
                    break;
                default:
                    ourArmy[attCounter]->setProbability(0);
                    AIArmy[defendCounter]->setProbability(0);
                    break;
            }

        } else if (attRank == "Sergeant") {
            switch(defRank[0]) {
                case 'M':
                    ourArmy[attCounter]->setProbability(0.4);
                    //cout << "attack prob at: " << numberOfAttackers << " : " << ourArmy[attCounter]->getProbability();
                    AIArmy[defendCounter]->setProbability(0.6);
                    break;
                case 'P':
                    ourArmy[attCounter]->setProbability(0.6);
                    AIArmy[defendCounter]->setProbability(0.4);
                    break;
                case 'S':
                    ourArmy[attCounter]->setProbability(0.5);
                    AIArmy[defendCounter]->setProbability(0.5);
                    break;
                default:
                    ourArmy[attCounter]->setProbability(0);
                    AIArmy[defendCounter]->setProbability(0);
                    break;
            }
        }
    }


    //for the vehicles fighting
    int attVehicleCounter = 0;
    int defendVehicleCounter = 0;

    while(numberOfAttackingVehicles >= 0 && numberOfDefendingVehicles >= 0){
        
    }
}    