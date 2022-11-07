#include "Attacking.h"

#include <string>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;

Attacking::Attacking(){
    //  std::cout << "Attacking constructor called" << endl;
}

double randomNumber(double prob)  
{
    double number = rand() % 100 + 1;  //Generate random number 1 to 100

    if (number <= prob*100) 
        return 1;
    else
        return 0;     
}

string Attacking::handle(vector<Army*> &ourArmy, vector<Army*> &AIArmy, std::string playerAttackStrategy, std::string CPUDefenseStrategy, int noOfAttackingVehiclesToSend, int noOfAttackingMajorsToSend, int noOfAttackingSergeantsToSend, int noOfAttackingPrivatesToSend, Engine* engine){
    srand(time(NULL));

    Country* currentCountry = engine->whichPlayerTurnCountry();
    vector<Country*> currentCountryVector = engine->whichPlayerTurnVector();

    Country* notCurrentCountry = engine->whichNotPlayerTurnCountry();
    vector<Country*> notCurrentCountryVector = engine->whichNotPlayerTurnVector();

    if (currentCountry->whichPlayer == "P1") {
        notCurrentCountry->whichPlayer = "P2";
    } else {
        notCurrentCountry->whichPlayer = "P1";
    }

    cout << "\033[1;32m" << currentCountry->whichPlayer << " is using attack strategy: " << "\033[1;33m" << playerAttackStrategy << "\033[0m" << endl;
    cout << "before" << endl;
    cout << "\033[1;31m" << notCurrentCountry->whichPlayer << " is using defense strategy: " << "\033[1;33m" << CPUDefenseStrategy << "\033[0m" << endl;
    cout << "after" << endl;

    string attackVehicleChosen;
    string defenseVehicleChosen;

    if(playerAttackStrategy == "LandAttack"){
        attackVehicleChosen = "Tank";
    }else if(playerAttackStrategy == "AirAttack"){
        attackVehicleChosen = "Plane";
    }else if(playerAttackStrategy == "SeaAttack"){
        attackVehicleChosen = "Ship";
    }

    if(CPUDefenseStrategy == "LandAttack"){
        defenseVehicleChosen = "Tank";
    }else if(CPUDefenseStrategy == "AirAttack"){
        defenseVehicleChosen = "Plane";
    }else if(CPUDefenseStrategy == "SeaAttack"){
        defenseVehicleChosen = "Ship";
    }



    int numberOfAttackingTanks = 0;
    int numberOfAttackingPlanes = 0;
    int numberOfAttackingShips = 0;
    int numberOfAttackingSoldiers = 0;

    int numberOfDefendingTanks = 0;
    int numberOfDefendingPlanes = 0;
    int numberOfDefendingShips = 0;
    int numberOfDefendingSoldiers = 0;

    // for(int i=0; i<ourArmy.size(); i++){                                         //PRINT PLAYER1 ARMY BEFORE ATTACK COMMNECES
    //     cout << "ourArmy at: " << i << " " << ourArmy[i]->getRank() << endl;
    // }

    for (int i = 0; i < ourArmy.size(); i++) {
        if(ourArmy[i]->getType() == "soldier") {
            numberOfAttackingSoldiers++;
        } else{
            if(ourArmy[i]->getRank() == "Tank"){
                numberOfAttackingTanks++;
            } else if(ourArmy[i]->getRank() == "Plane"){
                numberOfAttackingPlanes++;
            } else if(ourArmy[i]->getRank() == "Ship"){
                numberOfAttackingShips++;
            } 
        }
    }

    for (int i = 0; i < AIArmy.size(); i++) {
        if(AIArmy[i]->getType() == "soldier") {
            numberOfDefendingSoldiers++;
        } else{
            if(AIArmy[i]->getRank() == "Tank"){
                numberOfDefendingTanks++;
            } else if(AIArmy[i]->getRank() == "Plane"){
                numberOfDefendingPlanes++;
            } else if(AIArmy[i]->getRank() == "Ship"){
                numberOfDefendingShips++;
            } 
        } 
    }

    // cout << "Attacking soldiers: " << numberOfAttackingSoldiers << endl;
    // cout << "Attacking tanks: " << numberOfAttackingTanks << endl;
    // cout << "Attacking planes: " << numberOfAttackingPlanes << endl;
    // cout << "Attacking ships: " << numberOfAttackingShips << endl;

    // cout << "Defending soldiers: " << numberOfDefendingSoldiers << endl;
    // cout << "Defending tanks: " << numberOfDefendingTanks << endl;
    // cout << "Defending planes: " << numberOfDefendingPlanes << endl;
    // cout << "Defending ships: " << numberOfDefendingShips << endl;

    if(CPUDefenseStrategy == "LandDefense"){
        if(playerAttackStrategy == "LandAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Tank"){
                        ourArmy[i]->setProbability(0.5);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Tank"){
                        AIArmy[i]->setProbability(0.5);
                    }
                }
            }

        }else if(playerAttackStrategy == "AirAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Plane"){
                        ourArmy[i]->setProbability(0.65);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Tank"){
                        AIArmy[i]->setProbability(0.35);
                    }
                }
            }

        }else if(playerAttackStrategy == "SeaAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Ship"){
                        ourArmy[i]->setProbability(0.35);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Tank"){
                        AIArmy[i]->setProbability(0.65);
                    }
                }
            }

        }

    }else if(CPUDefenseStrategy == "AirDefense"){
        if(playerAttackStrategy == "LandAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Tank"){
                        ourArmy[i]->setProbability(0.35);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Plane"){
                        AIArmy[i]->setProbability(0.65);
                    }
                }
            }

        }else if(playerAttackStrategy == "AirAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Plane"){
                        ourArmy[i]->setProbability(0.5);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Plane"){
                        AIArmy[i]->setProbability(0.5);
                    }
                }
            }

        }else if(playerAttackStrategy == "SeaAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Ship"){
                        ourArmy[i]->setProbability(0.65);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Plane"){
                        AIArmy[i]->setProbability(0.35);
                    }
                }
            }

        }

    }else if(CPUDefenseStrategy == "SeaDefense"){
        if(playerAttackStrategy == "LandAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Tank"){
                        ourArmy[i]->setProbability(0.65);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Ship"){
                        AIArmy[i]->setProbability(0.35);
                    }
                }
            }

        }else if(playerAttackStrategy == "AirAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Tank"){
                        ourArmy[i]->setProbability(0.65);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Ship"){
                        AIArmy[i]->setProbability(0.35);
                    }
                }
            }
            
        }else if(playerAttackStrategy == "SeaAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Tank"){
                        ourArmy[i]->setProbability(0.5);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Ship"){
                        AIArmy[i]->setProbability(0.5);
                    }
                }
            }

        }

}


    //simulate the fight between the vehicles:
    int attVehicleCounter = 0;
    int defendVehicleCounter = 0;
    int result;

    if(playerAttackStrategy == "LandAttack"){
        if(CPUDefenseStrategy == "LandDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingTanks > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Tank"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Tank"){//increment counter till tank vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingTanks--;

                    auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendVehicleCounter]);
                    if(it != AIArmy.end()){
                        AIArmy.erase(it);
                    }
                }else{
                    noOfAttackingVehiclesToSend--;
                    
                    auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attVehicleCounter]);
                    if(it != ourArmy.end()){
                        ourArmy.erase(it);
                    }
                }

                //cout << "Attacker tanks remaining: " << noOfAttackingVehiclesToSend << endl;
                //cout << "Defender tanks remaining: " << numberOfDefendingTanks << endl;
            }

        }else if(CPUDefenseStrategy == "AirDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingPlanes > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Tank"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingPlanes--;

                    auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendVehicleCounter]);
                    if(it != AIArmy.end()){
                        AIArmy.erase(it);
                    }
                }else{
                    noOfAttackingVehiclesToSend--;

                    auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attVehicleCounter]);
                    if(it != ourArmy.end()){
                        ourArmy.erase(it);
                    }
                }

                //cout << "Attacker tanks remaining: " << noOfAttackingVehiclesToSend << endl;
                //cout << "Defender planes remaining: " << numberOfDefendingPlanes << endl;
            }
        }else if(CPUDefenseStrategy == "SeaDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingShips > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Tank"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingShips--;

                    auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendVehicleCounter]);
                    if(it != AIArmy.end()){
                        AIArmy.erase(it);
                    }
                }else{
                    noOfAttackingVehiclesToSend--;

                    auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attVehicleCounter]);
                    if(it != ourArmy.end()){
                        ourArmy.erase(it);
                    }
                }

                //cout << "Attacker tanks remaining: " << noOfAttackingVehiclesToSend << endl;
                //cout << "Defender ships remaining: " << numberOfDefendingShips << endl;
            }
        }
    }else if(playerAttackStrategy == "AirAttack"){
        if(CPUDefenseStrategy == "LandDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingTanks > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Tank"){//increment counter till tank vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingTanks--;

                    auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendVehicleCounter]);
                    if(it != AIArmy.end()){
                        AIArmy.erase(it);
                    }
                }else{
                    noOfAttackingVehiclesToSend--;

                    auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attVehicleCounter]);
                    if(it != ourArmy.end()){
                        ourArmy.erase(it);
                    }
                }

                //cout << "Attacker planes remaining: " << noOfAttackingVehiclesToSend << endl;
                //cout << "Defender tanks remaining: " << numberOfDefendingTanks << endl;
            }

        }else if(CPUDefenseStrategy == "AirDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingPlanes > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingPlanes--;

                    auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendVehicleCounter]);
                    if(it != AIArmy.end()){
                        AIArmy.erase(it);
                    }
                }else{
                    noOfAttackingVehiclesToSend--;

                    auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attVehicleCounter]);
                    if(it != ourArmy.end()){
                        ourArmy.erase(it);
                    }
                }

                //cout << "Attacker planes remaining: " << noOfAttackingVehiclesToSend << endl;
                //cout << "Defender planes remaining: " << numberOfDefendingPlanes << endl;
            }
        }else if(CPUDefenseStrategy == "SeaDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingShips > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingShips--;

                    auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendVehicleCounter]);
                    if(it != AIArmy.end()){
                        AIArmy.erase(it);
                    }
                }else{
                    noOfAttackingVehiclesToSend--;

                    auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attVehicleCounter]);
                    if(it != ourArmy.end()){
                        ourArmy.erase(it);
                    }
                }

                //cout << "Attacker planes remaining: " << noOfAttackingVehiclesToSend << endl;
                //cout << "Defender ships remaining: " << numberOfDefendingShips << endl;
            }
        }
    }else if(playerAttackStrategy == "SeaAttack"){
        if(CPUDefenseStrategy == "LandDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingTanks > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Tank"){//increment counter till tank vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingTanks--;

                    auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendVehicleCounter]);
                    if(it != AIArmy.end()){
                        AIArmy.erase(it);
                    }
                }else{
                    noOfAttackingVehiclesToSend--;

                    auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attVehicleCounter]);
                    if(it != ourArmy.end()){
                        ourArmy.erase(it);
                    }
                }

                //cout << "Attacker ships remaining: " << noOfAttackingVehiclesToSend << endl;
                //cout << "Defender tanks remaining: " << numberOfDefendingTanks << endl;
            }

        }else if(CPUDefenseStrategy == "AirDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingPlanes > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingPlanes--;

                    auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendVehicleCounter]);
                    if(it != AIArmy.end()){
                        AIArmy.erase(it);
                    }
                }else{
                    noOfAttackingVehiclesToSend--;

                    auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attVehicleCounter]);
                    if(it != ourArmy.end()){
                        ourArmy.erase(it);
                    }
                }

                //cout << "Attacker ships remaining: " << noOfAttackingVehiclesToSend << endl;
                //cout << "Defender planes remaining: " << numberOfDefendingPlanes << endl;
            }
        }else if(CPUDefenseStrategy == "SeaDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingShips > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingShips--;

                    auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendVehicleCounter]);
                    if(it != AIArmy.end()){
                        AIArmy.erase(it);
                    }
                }else{
                    noOfAttackingVehiclesToSend--;

                    auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attVehicleCounter]);
                    if(it != ourArmy.end()){
                        ourArmy.erase(it);
                    }
                }

                //cout << "Attacker ships remaining: " << noOfAttackingVehiclesToSend << endl;
                //cout << "Defender ships remaining: " << numberOfDefendingShips << endl;
            }
        }
    }

    //print vehicle fight results
    cout << endl;
    cout << "\033[1;32m" << currentCountry->whichPlayer << "'s attacking " << attackVehicleChosen << "s remaining: " << noOfAttackingVehiclesToSend << "\033[0m" << endl; 

    if(CPUDefenseStrategy == "LandDefense"){
        cout << "\033[1;31m" << notCurrentCountry->whichPlayer << "'s defending Tanks remaining: " << numberOfDefendingTanks << "\033[0m" << endl; 
    }else if(CPUDefenseStrategy == "AirDefense"){
        cout << "\033[1;31m" << notCurrentCountry->whichPlayer << "'s defending Planes remaining: " << numberOfDefendingPlanes << "\033[0m" << endl; 
    }else if(CPUDefenseStrategy == "SeaDefense"){
        cout << "\033[1;31m" << notCurrentCountry->whichPlayer << "'s defending Ships remaining: " << numberOfDefendingShips << "\033[0m" << endl; 
    }


    //MAKING SOLDIERS FIGHT
    int attSoldierCounter = 0;
    int defendSoldierCounter = 0;

    while(noOfAttackingPrivatesToSend > 0 && numberOfDefendingSoldiers > 0){ //either attacking sergeants die or all defending troops die
        while(ourArmy[attSoldierCounter]->getType() != "soldier" || ourArmy[attSoldierCounter]->getRank() != "Private"){//increment counter till soldier found in array
            attSoldierCounter++;
        }

        while(AIArmy[defendSoldierCounter]->getType() != "soldier"){//increment counter till soldier found in array
            defendSoldierCounter++;
        }

         string attRank = ourArmy[attSoldierCounter]->getRank();
         string defRank = AIArmy[defendSoldierCounter]->getRank();

          if (attRank == "Private")  {

                switch(defRank[0]) {
                    case 'M':
                        ourArmy[attSoldierCounter]->setProbability(0.5);
                        AIArmy[defendSoldierCounter]->setProbability(0.5);
                        break;
                    case 'P':
                        ourArmy[attSoldierCounter]->setProbability(0.65);
                        AIArmy[defendSoldierCounter]->setProbability(0.35);
                        break;
                    case 'S':
                        ourArmy[attSoldierCounter]->setProbability(0.35);
                        AIArmy[defendSoldierCounter]->setProbability(0.65);
                        break;
                    default:
                        ourArmy[attSoldierCounter]->setProbability(0);
                        AIArmy[defendSoldierCounter]->setProbability(0);
                        break;
                }

            }

            result = randomNumber(ourArmy[attSoldierCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

            if(result == 1){
                numberOfDefendingSoldiers--;

                auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendSoldierCounter]);
                if(it != AIArmy.end()){
                    AIArmy.erase(it);
                }
            }else{
                noOfAttackingPrivatesToSend--;
                auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attSoldierCounter]);
                if(it != ourArmy.end()){
                    ourArmy.erase(it);
                }
            }

            //cout << "Attacker privates remaining: " << noOfAttackingPrivatesToSend << endl;
            //cout << "Defender troops remaining: " << numberOfDefendingSoldiers << endl;
    }


    attSoldierCounter = 0;
    defendSoldierCounter = 0;

    while(noOfAttackingSergeantsToSend > 0 && numberOfDefendingSoldiers > 0){ //either attacking sergeants die or all defending troops die
        while(ourArmy[attSoldierCounter]->getType() != "soldier" || ourArmy[attSoldierCounter]->getRank() != "Sergeant"){//increment counter till soldier found in array
            attSoldierCounter++;
        }

        while(AIArmy[defendSoldierCounter]->getType() != "soldier"){//increment counter till soldier found in array
            defendSoldierCounter++;
        }

         string attRank = ourArmy[attSoldierCounter]->getRank();
         string defRank = AIArmy[defendSoldierCounter]->getRank();

          if (attRank == "Sergeant")  {

                switch(defRank[0]) {
                    case 'M':
                        ourArmy[attSoldierCounter]->setProbability(0.5);
                        AIArmy[defendSoldierCounter]->setProbability(0.5);
                        break;
                    case 'P':
                        ourArmy[attSoldierCounter]->setProbability(0.65);
                        AIArmy[defendSoldierCounter]->setProbability(0.35);
                        break;
                    case 'S':
                        ourArmy[attSoldierCounter]->setProbability(0.35);
                        AIArmy[defendSoldierCounter]->setProbability(0.65);
                        break;
                    default:
                        ourArmy[attSoldierCounter]->setProbability(0);
                        AIArmy[defendSoldierCounter]->setProbability(0);
                        break;
                }

            }

            result = randomNumber(ourArmy[attSoldierCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

            if(result == 1){
                numberOfDefendingSoldiers--;

                auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendSoldierCounter]);
                if(it != AIArmy.end()){
                    AIArmy.erase(it);
                }
            }else{
                noOfAttackingSergeantsToSend--;
                auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attSoldierCounter]);
                if(it != ourArmy.end()){
                    ourArmy.erase(it);
                }
            }

            //cout << "Attacker Sergeants remaining: " << noOfAttackingSergeantsToSend << endl;
            //cout << "Defender troops remaining: " << numberOfDefendingSoldiers << endl;
    }


    attSoldierCounter = 0;
    defendSoldierCounter = 0;

    while(noOfAttackingMajorsToSend > 0 && numberOfDefendingSoldiers > 0){ //either attacking majors die or all defending troops die
        while(ourArmy[attSoldierCounter]->getType() != "soldier" || ourArmy[attSoldierCounter]->getRank() != "Major"){//increment counter till soldier found in array
            attSoldierCounter++;
        }

        while(AIArmy[defendSoldierCounter]->getType() != "soldier"){//increment counter till soldier found in array
            defendSoldierCounter++;
        }

         string attRank = ourArmy[attSoldierCounter]->getRank();
         string defRank = AIArmy[defendSoldierCounter]->getRank();

          if (attRank == "Major")  {

                switch(defRank[0]) {
                    case 'M':
                        ourArmy[attSoldierCounter]->setProbability(0.5);
                        AIArmy[defendSoldierCounter]->setProbability(0.5);
                        break;
                    case 'P':
                        ourArmy[attSoldierCounter]->setProbability(0.65);
                        AIArmy[defendSoldierCounter]->setProbability(0.35);
                        break;
                    case 'S':
                        ourArmy[attSoldierCounter]->setProbability(0.65);
                        AIArmy[defendSoldierCounter]->setProbability(0.35);
                        break;
                    default:
                        ourArmy[attSoldierCounter]->setProbability(0);
                        AIArmy[defendSoldierCounter]->setProbability(0);
                        break;
                }

            }

            result = randomNumber(ourArmy[attSoldierCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

            if(result == 1){
                numberOfDefendingSoldiers--;

                auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[defendSoldierCounter]);
                if(it != AIArmy.end()){
                    AIArmy.erase(it);
                }
            }else{
                noOfAttackingMajorsToSend--;
                auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[attSoldierCounter]);
                if(it != ourArmy.end()){
                    ourArmy.erase(it);
                }
            }

            //cout << "Attacker Majors remaining: " << noOfAttackingMajorsToSend << endl;
            //cout << "Defender troops remaining: " << numberOfDefendingSoldiers << endl;
    }


    //print soldier fight results
    cout << endl;
    cout << "\033[1;32m" << currentCountry->whichPlayer << "'s attacking troops remaining: " << noOfAttackingMajorsToSend + noOfAttackingSergeantsToSend + noOfAttackingPrivatesToSend << "\033[0m" << endl; 
    cout << "\033[1;31m" << notCurrentCountry->whichPlayer << "'s defending troops remaining: " << numberOfDefendingSoldiers << "\033[0m" << endl << endl; 


    //final check: make them fight the opposite type. eg: soldier vs vehicle or vehicle vs soldier
    int totalAttackSoldiersSent = noOfAttackingMajorsToSend + noOfAttackingPrivatesToSend + noOfAttackingSergeantsToSend;

    if(totalAttackSoldiersSent == 0){
        if(noOfAttackingVehiclesToSend == 0){
            cout << "\033[7;32m" << notCurrentCountry->whichPlayer << " won defense! clean sweep!" << "\033[0m" << endl;
            return notCurrentCountry->whichPlayer + " won the defense!";
        }else{
            //make attacker remaining vehicles fight with defenders remaining troops

            if(playerAttackStrategy == "LandAttack"){
                if((noOfAttackingVehiclesToSend * 15) >= numberOfDefendingSoldiers){

                    //remove all soldiers from the defending army
                    int tempCount = 0;

                    while(numberOfDefendingSoldiers > 0){
                        while(AIArmy[tempCount]->getType() != "soldier"){
                            tempCount++;
                        }
                        
                        auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                        if(it != AIArmy.end()){
                            AIArmy.erase(it);
                            numberOfDefendingSoldiers--;
                        }
                    }

                    cout << "\033[7;32m" << currentCountry->whichPlayer << " won attack with remaining vehicles!" << "\033[0m" << endl;
                    return currentCountry->whichPlayer + " won the attack!";

                }else{
                    
                    //remove noOfAttackingvehicles from attacking army array
                    int tempCount = 0;

                    if(playerAttackStrategy == "LandAttack"){
                        while(noOfAttackingVehiclesToSend > 0){
                            if(ourArmy[tempCount]->getType() != "vehicle" || ourArmy[tempCount]->getRank() != "Tank"){
                                tempCount++;
                            }

                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingVehiclesToSend--;
                        }
                    }else if(playerAttackStrategy == "AirAttack"){
                        while(noOfAttackingVehiclesToSend > 0){
                            if(ourArmy[tempCount]->getType() != "vehicle" || ourArmy[tempCount]->getRank() != "Plane"){
                                tempCount++;
                            }

                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingVehiclesToSend--;
                        }
                    }else if(playerAttackStrategy == "SeaAttack"){
                        while(noOfAttackingVehiclesToSend > 0){
                            if(ourArmy[tempCount]->getType() != "vehicle" || ourArmy[tempCount]->getRank() != "Ship"){
                                tempCount++;
                            }

                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingVehiclesToSend--;
                        }
                    }
                    cout << "\033[7;32m" << notCurrentCountry->whichPlayer << " won defense with remaining troops!" << "\033[0m" << endl;
                    return notCurrentCountry->whichPlayer + " won the defense!";


                }
            }else if(playerAttackStrategy == "AirAttack"){
                if((noOfAttackingVehiclesToSend * 25) >= numberOfDefendingSoldiers){
                    //remove all soldiers from the defending army
                    int tempCount = 0;

                    while(numberOfDefendingSoldiers > 0){
                        while(AIArmy[tempCount]->getType() != "soldier"){
                            tempCount++;
                        }
                        
                        auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                        if(it != AIArmy.end()){
                            AIArmy.erase(it);
                            numberOfDefendingSoldiers--;
                        }
                    }

                    cout << "\033[7;32m" << currentCountry->whichPlayer << " won attack with remaining vehicles!" << "\033[0m" << endl;
                    return currentCountry->whichPlayer + " won the attack!";

                }else{
                    
                    //remove noOfAttackingvehicles from attacking army array
                    int tempCount = 0;

                    if(playerAttackStrategy == "LandAttack"){
                        while(noOfAttackingVehiclesToSend > 0){
                            if(ourArmy[tempCount]->getType() != "vehicle" || ourArmy[tempCount]->getRank() != "Tank"){
                                tempCount++;
                            }

                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingVehiclesToSend--;
                        }
                    }else if(playerAttackStrategy == "AirAttack"){
                        while(noOfAttackingVehiclesToSend > 0){
                            if(ourArmy[tempCount]->getType() != "vehicle" || ourArmy[tempCount]->getRank() != "Plane"){
                                tempCount++;
                            }

                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingVehiclesToSend--;
                        }
                    }else if(playerAttackStrategy == "SeaAttack"){
                        while(noOfAttackingVehiclesToSend > 0){
                            if(ourArmy[tempCount]->getType() != "vehicle" || ourArmy[tempCount]->getRank() != "Ship"){
                                tempCount++;
                            }

                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingVehiclesToSend--;
                        }
                    }
                    cout << "\033[7;32m" << notCurrentCountry->whichPlayer << " won defense with remaining troops!" << "\033[0m" << endl;
                    return notCurrentCountry->whichPlayer + " won the defense!";

                }
            }else if(playerAttackStrategy == "SeaAttack"){
                if((noOfAttackingVehiclesToSend * 20) >= numberOfDefendingSoldiers){

                    //remove all soldiers from the defending army
                    int tempCount = 0;

                    while(numberOfDefendingSoldiers > 0){
                        while(AIArmy[tempCount]->getType() != "soldier"){
                            tempCount++;
                        }
                        
                        auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                        if(it != AIArmy.end()){
                            AIArmy.erase(it);
                            numberOfDefendingSoldiers--;
                        }
                    }

                    cout << "\033[7;32m" << currentCountry->whichPlayer << " won attack with remaining vehicles!" << "\033[0m" << endl;
                    return currentCountry->whichPlayer + " won the attack!";

                }else{
                    
                    //remove noOfAttackingvehicles from attacking army array
                    int tempCount = 0;

                    if(playerAttackStrategy == "LandAttack"){
                        while(noOfAttackingVehiclesToSend > 0){
                            if(ourArmy[tempCount]->getType() != "vehicle" || ourArmy[tempCount]->getRank() != "Tank"){
                                tempCount++;
                            }

                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingVehiclesToSend--;
                        }
                    }else if(playerAttackStrategy == "AirAttack"){
                        while(noOfAttackingVehiclesToSend > 0){
                            if(ourArmy[tempCount]->getType() != "vehicle" || ourArmy[tempCount]->getRank() != "Plane"){
                                tempCount++;
                            }

                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingVehiclesToSend--;
                        }
                    }else if(playerAttackStrategy == "SeaAttack"){
                        while(noOfAttackingVehiclesToSend > 0){
                            if(ourArmy[tempCount]->getType() != "vehicle" || ourArmy[tempCount]->getRank() != "Ship"){
                                tempCount++;
                            }

                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingVehiclesToSend--;
                        }
                    }
                    cout << "\033[7;32m" << notCurrentCountry->whichPlayer << " won defense with remaining troops!" << "\033[0m" << endl;
                    return notCurrentCountry->whichPlayer + " won the defense!";

                }
            }


        }
    }else{
        if(noOfAttackingVehiclesToSend == 0){
            //make defenders vehicles fight with attackers remaining troops
            if(CPUDefenseStrategy == "LandDefense"){
                if((numberOfDefendingTanks * 15) >= totalAttackSoldiersSent){
                    //defenders won. remove the attacking soldiers from attacking army
                    int tempCount = 0;

                    while(noOfAttackingMajorsToSend > 0){
                        while(ourArmy[tempCount]->getType() != "soldier" || ourArmy[tempCount]->getRank() != "Major"){
                            tempCount++;
                        }

                        if(ourArmy[tempCount]->getRank() == "Major"){
                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingMajorsToSend--;
                        }
                    }

                    tempCount = 0;

                    while(noOfAttackingSergeantsToSend > 0){
                        while(ourArmy[tempCount]->getType() != "soldier" || ourArmy[tempCount]->getRank() != "Sergeant"){
                            tempCount++;
                        }

                        if(ourArmy[tempCount]->getRank() == "Sergeant"){
                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingSergeantsToSend--;
                        }
                    }

                    tempCount = 0;

                    while(noOfAttackingSergeantsToSend > 0){
                        while(ourArmy[tempCount]->getType() != "soldier" || ourArmy[tempCount]->getRank() != "Private"){
                            tempCount++;
                        }

                        if(ourArmy[tempCount]->getRank() == "Private"){
                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingSergeantsToSend--;
                        }
                    }
                    cout << "\033[7;32m" << notCurrentCountry->whichPlayer << " won defense with remaining vehicles!" << "\033[0m" << endl;
                    return notCurrentCountry->whichPlayer + " won the defense!";

                }else{
                    //attackers won. remove the defending vehicles from defenders army
                    int tempCount = 0;

                    if(CPUDefenseStrategy == "LandDefense"){
                        while(numberOfDefendingTanks > 0){
                            while(AIArmy[tempCount]->getType() != "vehicle" || AIArmy[tempCount]->getRank() != "Tank"){
                                tempCount++;
                            }

                            auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                            if(it != AIArmy.end()){
                                AIArmy.erase(it);
                            }
                            numberOfDefendingTanks--;
                        }
                    }else if(CPUDefenseStrategy == "AirDefense"){
                        while(numberOfDefendingPlanes > 0){
                            while(AIArmy[tempCount]->getType() != "vehicle" || AIArmy[tempCount]->getRank() != "Plane"){
                                tempCount++;
                            }

                            auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                            if(it != AIArmy.end()){
                                AIArmy.erase(it);
                            }
                            numberOfDefendingPlanes--;
                        }
                    }else if(CPUDefenseStrategy == "SeaDefense"){
                        while(numberOfDefendingShips > 0){
                            while(AIArmy[tempCount]->getType() != "vehicle" || AIArmy[tempCount]->getRank() != "Ship"){
                                tempCount++;
                            }

                            auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                            if(it != AIArmy.end()){
                                AIArmy.erase(it);
                            }
                            numberOfDefendingShips--;
                        }
                    }
                    cout << "\033[7;32m" << currentCountry->whichPlayer << " won attack with remaining troops!" << "\033[0m" << endl;
                    return currentCountry->whichPlayer + " won the attack!";

                }
            }else if(CPUDefenseStrategy == "AirDefense"){
                if((numberOfDefendingTanks * 25) >= totalAttackSoldiersSent){
                    //defenders won. remove the attacking soldiers from attacking army
                     int tempCount = 0;

                    while(noOfAttackingMajorsToSend > 0){
                        while(ourArmy[tempCount]->getType() != "soldier" || ourArmy[tempCount]->getRank() != "Major"){
                            tempCount++;
                        }

                        if(ourArmy[tempCount]->getRank() == "Major"){
                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingMajorsToSend--;
                        }
                    }

                    tempCount = 0;

                    while(noOfAttackingSergeantsToSend > 0){
                        while(ourArmy[tempCount]->getType() != "soldier" || ourArmy[tempCount]->getRank() != "Sergeant"){
                            tempCount++;
                        }

                        if(ourArmy[tempCount]->getRank() == "Sergeant"){
                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingSergeantsToSend--;
                        }
                    }

                    tempCount = 0;

                    while(noOfAttackingSergeantsToSend > 0){
                        while(ourArmy[tempCount]->getType() != "soldier" || ourArmy[tempCount]->getRank() != "Private"){
                            tempCount++;
                        }

                        if(ourArmy[tempCount]->getRank() == "Private"){
                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingSergeantsToSend--;
                        }
                    }
                    cout << "\033[7;32m" << notCurrentCountry->whichPlayer << " won defense with remaining vehicles!" << "\033[0m" << endl;
                    return notCurrentCountry->whichPlayer + " won the defense!";
                }else{
                    //attackers won. remove the defending vehicles from defenders army
                    int tempCount = 0;

                    if(CPUDefenseStrategy == "LandDefense"){
                        while(numberOfDefendingTanks > 0){
                            while(AIArmy[tempCount]->getType() != "vehicle" || AIArmy[tempCount]->getRank() != "Tank"){
                                tempCount++;
                            }

                            auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                            if(it != AIArmy.end()){
                                AIArmy.erase(it);
                            }
                            numberOfDefendingTanks--;
                        }
                    }else if(CPUDefenseStrategy == "AirDefense"){
                        while(numberOfDefendingPlanes > 0){
                            while(AIArmy[tempCount]->getType() != "vehicle" || AIArmy[tempCount]->getRank() != "Plane"){
                                tempCount++;
                            }

                            auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                            if(it != AIArmy.end()){
                                AIArmy.erase(it);
                            }
                            numberOfDefendingPlanes--;
                        }
                    }else if(CPUDefenseStrategy == "SeaDefense"){
                        while(numberOfDefendingShips > 0){
                            while(AIArmy[tempCount]->getType() != "vehicle" || AIArmy[tempCount]->getRank() != "Ship"){
                                tempCount++;
                            }

                            auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                            if(it != AIArmy.end()){
                                AIArmy.erase(it);
                            }
                            numberOfDefendingShips--;
                        }
                    }
                    cout << "\033[7;32m" << currentCountry->whichPlayer << " won attack with remaining troops!" << "\033[0m" << endl;
                    return currentCountry->whichPlayer + " won the attack!";
                }
            }else if(CPUDefenseStrategy == "SeaDefense"){
                if((numberOfDefendingTanks * 20) >= totalAttackSoldiersSent){
                    //defenders won. remove the attacking soldiers from attacking army
                     int tempCount = 0;

                    while(noOfAttackingMajorsToSend > 0){
                        while(ourArmy[tempCount]->getType() != "soldier" || ourArmy[tempCount]->getRank() != "Major"){
                            tempCount++;
                        }

                        if(ourArmy[tempCount]->getRank() == "Major"){
                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingMajorsToSend--;
                        }
                    }

                    tempCount = 0;

                    while(noOfAttackingSergeantsToSend > 0){
                        while(ourArmy[tempCount]->getType() != "soldier" || ourArmy[tempCount]->getRank() != "Sergeant"){
                            tempCount++;
                        }

                        if(ourArmy[tempCount]->getRank() == "Sergeant"){
                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingSergeantsToSend--;
                        }
                    }

                    tempCount = 0;

                    while(noOfAttackingSergeantsToSend > 0){
                        while(ourArmy[tempCount]->getType() != "soldier" || ourArmy[tempCount]->getRank() != "Private"){
                            tempCount++;
                        }

                        if(ourArmy[tempCount]->getRank() == "Private"){
                            auto it = find(ourArmy.begin(), ourArmy.end(), ourArmy[tempCount]);
                            if(it != ourArmy.end()){
                                ourArmy.erase(it);
                            }
                            noOfAttackingSergeantsToSend--;
                        }
                    }
                    cout << "\033[7;32m" << notCurrentCountry->whichPlayer << " won defense with remaining vehicles!" << "\033[0m" << endl;
                    return notCurrentCountry->whichPlayer + " won the defense!";
                }else{
                    //attackers won. remove the defending vehicles from defenders army
                    int tempCount = 0;

                    if(CPUDefenseStrategy == "LandDefense"){
                        while(numberOfDefendingTanks > 0){
                            while(AIArmy[tempCount]->getType() != "vehicle" || AIArmy[tempCount]->getRank() != "Tank"){
                                tempCount++;
                            }

                            auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                            if(it != AIArmy.end()){
                                AIArmy.erase(it);
                            }
                            numberOfDefendingTanks--;
                        }
                    }else if(CPUDefenseStrategy == "AirDefense"){
                        while(numberOfDefendingPlanes > 0){
                            while(AIArmy[tempCount]->getType() != "vehicle" || AIArmy[tempCount]->getRank() != "Plane"){
                                tempCount++;
                            }

                            auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                            if(it != AIArmy.end()){
                                AIArmy.erase(it);
                            }
                            numberOfDefendingPlanes--;
                        }
                    }else if(CPUDefenseStrategy == "SeaDefense"){
                        while(numberOfDefendingShips > 0){
                            while(AIArmy[tempCount]->getType() != "vehicle" || AIArmy[tempCount]->getRank() != "Ship"){
                                tempCount++;
                            }

                            auto it = find(AIArmy.begin(), AIArmy.end(), AIArmy[tempCount]);
                            if(it != AIArmy.end()){
                                AIArmy.erase(it);
                            }
                            numberOfDefendingShips--;
                        }
                    }
                    cout << "\033[7;32m" << currentCountry->whichPlayer << " won attack with remaining troops!" << "\033[0m" << endl;
                    return currentCountry->whichPlayer + " won the attack!";
                }
            }

        }else{
            cout << "\033[7;32m" << currentCountry->whichPlayer << " won attack! clean sweep!" << "\033[0m" << endl;
            return currentCountry->whichPlayer + " won the attack!";
        }
    }
    return "Error occured";
}