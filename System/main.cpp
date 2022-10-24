#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>

#include "Country.h"
//#include "WarUtilities.h"
#include "Soldier.h"

using namespace std;


double randomNumber(double prob)  
{
    srand(time(NULL));
    double number = rand() % 100 + 1;  //Generate random number 1 to 100

    if (number <= prob*100) 
        return 1;
    else
        return 0;
                
}

int main() {

    int ourMoney = 5000;
    string choice;
    int attCounter = 2;
    int defCounter = 2;

    double totProbability = 0;
    int totSoldiers = 0;
    int result;

    Soldier** AttackArr = new Soldier*[3];
    Soldier** DefendArr = new Soldier*[3];
    AttackArr[0] = new Soldier("Sergeant");
    AttackArr[1] = new Soldier("Private");
    AttackArr[2] = new Soldier("Private");

    DefendArr[0] = new Soldier("Major");
    DefendArr[1] = new Soldier("Major");
    DefendArr[2] = new Soldier("Major");


    while (attCounter >= 0 && defCounter >= 0) {
        string attRank = AttackArr[attCounter]->getRank();
        string defRank = DefendArr[defCounter]->getRank();

        if (attRank == "Major")  {

            switch(defRank[0]) {
                case 'M':
                    AttackArr[attCounter]->setProbability(0.5);
                    DefendArr[defCounter]->setProbability(0.5);
                    break;
                case 'P':
                    AttackArr[attCounter]->setProbability(0.85);
                    DefendArr[defCounter]->setProbability(0.15);
                    break;
                case 'S':
                    AttackArr[attCounter]->setProbability(0.6);
                    DefendArr[defCounter]->setProbability(0.4);
                    break;
                default:
                    AttackArr[attCounter]->setProbability(0);
                    DefendArr[defCounter]->setProbability(0);
                    break;
            }

        } else if (attRank == "Private") {
            switch(defRank[0]) {
                case 'M':
                    AttackArr[attCounter]->setProbability(0.15);
                    DefendArr[defCounter]->setProbability(0.85);
                    break;
                case 'P':
                    AttackArr[attCounter]->setProbability(0.5);
                    DefendArr[defCounter]->setProbability(0.5);
                    break;
                case 'S':
                    AttackArr[attCounter]->setProbability(0.4);
                    DefendArr[defCounter]->setProbability(0.6);
                    break;
                default:
                    AttackArr[attCounter]->setProbability(0);
                    DefendArr[defCounter]->setProbability(0);
                    break;
            }

        } else if (attRank == "Sergeant") {
            switch(defRank[0]) {
                case 'M':
                    AttackArr[attCounter]->setProbability(0.4);
                    cout << "attack prob at: " << attCounter << " : " << AttackArr[attCounter]->getProbability();
                    DefendArr[defCounter]->setProbability(0.6);
                    break;
                case 'P':
                    AttackArr[attCounter]->setProbability(0.6);
                    DefendArr[defCounter]->setProbability(0.4);
                    break;
                case 'S':
                    AttackArr[attCounter]->setProbability(0.5);
                    DefendArr[defCounter]->setProbability(0.5);
                    break;
                default:
                    AttackArr[attCounter]->setProbability(0);
                    DefendArr[defCounter]->setProbability(0);
                    break;
            }
        }

        result = randomNumber(AttackArr[attCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

        if(result == 1){
            defCounter--;
        }else{
            attCounter--;
        }
    }

    cout << "Attacker troops remaining: " << attCounter << endl;
    cout << "Defender troops remaining: " << defCounter << endl;

    Country* America = new Country("America", ourMoney);

    America->buildArmy();

    

    return 0;

    
}