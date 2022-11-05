#include "Defending.h"

#include <string>
#include <cstdlib>
#include <random>
#include <ctime>

Defending::Defending(){
     std::cout << "Defending constructor called" << endl;
}

// double randomNumber(double prob)  
// {
//     double number = rand() % 100 + 1;  //Generate random number 1 to 100

//     if (number <= prob*100) 
//         return 1;
//     else
//         return 0;     
// }

string Defending::handle(vector<Army*> &ourArmy, vector<Army*> &AIArmy, std::string playerAttackStrategy, std::string CPUDefenseStrategy, int noOfAttackingVehiclesToSend, int noOfAttackingMajorsToSend, int noOfAttackingSergeantsToSend, int noOfAttackingPrivatesToSend){
    srand(time(NULL));

    int result;
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

            //result = randomNumber(ourArmy[attSoldierCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

            cout << "Attacker privates remaining: " << noOfAttackingPrivatesToSend << endl;
            cout << "Defender troops remaining: " << numberOfDefendingSoldiers << endl;
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

            //Number(ourArmy[attSoldierCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

            cout << "Attacker Sergeants remaining: " << noOfAttackingSergeantsToSend << endl;
            cout << "Defender troops remaining: " << numberOfDefendingSoldiers << endl;
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

            //result = randomNumber(ourArmy[attSoldierCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

            cout << "Attacker Majors remaining: " << noOfAttackingMajorsToSend << endl;
            cout << "Defender troops remaining: " << numberOfDefendingSoldiers << endl;
    }




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

    if(playerAttackStrategy == "LandAttack"){
        if(CPUDefenseStrategy == "LandDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingTanks > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Tank"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Tank"){//increment counter till tank vehicle found in array
                    defendVehicleCounter++;
                }

                //result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

                cout << "Attacker tanks remaining: " << noOfAttackingVehiclesToSend << endl;
                cout << "Defender tanks remaining: " << numberOfDefendingTanks << endl;
            }

        }else if(CPUDefenseStrategy == "AirDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingPlanes > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Tank"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                //result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

                cout << "Attacker tanks remaining: " << noOfAttackingVehiclesToSend << endl;
                cout << "Defender planes remaining: " << numberOfDefendingPlanes << endl;
            }
        }else if(CPUDefenseStrategy == "SeaDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingShips > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Tank"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                //result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

                cout << "Attacker tanks remaining: " << noOfAttackingVehiclesToSend << endl;
                cout << "Defender ships remaining: " << numberOfDefendingShips << endl;
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

                //result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

                cout << "Attacker planes remaining: " << noOfAttackingVehiclesToSend << endl;
                cout << "Defender tanks remaining: " << numberOfDefendingTanks << endl;
            }

        }else if(CPUDefenseStrategy == "AirDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingPlanes > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                //result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

                cout << "Attacker planes remaining: " << noOfAttackingVehiclesToSend << endl;
                cout << "Defender planes remaining: " << numberOfDefendingPlanes << endl;
            }
        }else if(CPUDefenseStrategy == "SeaDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingShips > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                //result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

                cout << "Attacker planes remaining: " << noOfAttackingVehiclesToSend << endl;
                cout << "Defender ships remaining: " << numberOfDefendingShips << endl;
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

                //result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

                cout << "Attacker ships remaining: " << noOfAttackingVehiclesToSend << endl;
                cout << "Defender tanks remaining: " << numberOfDefendingTanks << endl;
            }

        }else if(CPUDefenseStrategy == "AirDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingPlanes > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                //result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

                cout << "Attacker ships remaining: " << noOfAttackingVehiclesToSend << endl;
                cout << "Defender planes remaining: " << numberOfDefendingPlanes << endl;
            }
        }else if(CPUDefenseStrategy == "SeaDefense"){
            while(noOfAttackingVehiclesToSend > 0 && numberOfDefendingShips > 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" || ourArmy[attVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" || AIArmy[defendVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                //result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

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

                cout << "Attacker ships remaining: " << noOfAttackingVehiclesToSend << endl;
                cout << "Defender ships remaining: " << numberOfDefendingShips << endl;
            }
        }
    }




    //final check: make them fight the opposite type. eg: soldier vs vehicle or vehicle vs soldier
    int totalAttackSoldiersSent = noOfAttackingMajorsToSend + noOfAttackingPrivatesToSend + noOfAttackingSergeantsToSend;

    if(totalAttackSoldiersSent == 0){
        if(noOfAttackingVehiclesToSend == 0){
            cout << "Player 2 won defense. clean sweep" << endl;
            return "Player 2 won the defense!";
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

                    cout << "Player 1 won attack with vehicles 1" << endl;
                    return "Player 1 won the attack!";

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
                    cout << "Player 2 won defense with troops 1" << endl;
                    return "Player 2 won the defense!";


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

                    cout << "Player 1 won attack with vehicles 1" << endl;
                    return "Player 1 won the attack!";

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
                    cout << "Player 2 won defense with troops 1" << endl;
                    return "Player 2 won the defense!";

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

                    cout << "Player 1 won attack with vehicles 1" << endl;
                    return "Player 1 won the attack!";

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
                    cout << "Player 2 won defense with troops 1" << endl;
                    return "Player 2 won the defense!";

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
                    cout << "Player 2 won defense with vehicles 2" << endl;
                    return "Player 2 won the defense!";

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
                    cout << "Player 1 won attack with troops 2" << endl;
                    return "Player 1 won the attack!";

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
                    cout << "Player 2 won defense with vehicles 2" << endl;
                    return "Player 2 won the defense!";
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
                    cout << "Player 1 won attack with troops 2" << endl;
                    return "Player 1 won the attack!";
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
                    cout << "Player 2 won defense with vehicles 2" << endl;
                    return "Player 2 won the defense!";
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
                    cout << "Player 1 won attack with troops 2" << endl;
                    return "Player 1 won the attack!";
                }
            }

        }else{
            cout << "Player 1 won attack. Clean sweep" << endl;
            return "Player 1 won the attack!";
        }
    }
}