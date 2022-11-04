#include "Attacking.h"

Attacking::Attacking(){
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

void Attacking::handle(vector<Army*> ourArmy, vector<Army*> AIArmy, string playerAttackStrategy, string CPUDefenseStrategy){
    
    int numberOfAttackingTanks = 0;
    int numberOfAttackingPlanes = 0;
    int numberOfAttackingShips = 0;
    int numberOfAttackingSoldiers = 0;

    int numberOfDefendingTanks = 0;
    int numberOfDefendingPlanes = 0;
    int numberOfDefendingShips = 0;
    int numberOfDefendingSoldiers = 0;

    for (int i = 0; i < ourArmy.size(); i++) {
        if(ourArmy[i]->getType() == "soldier") {
            numberOfAttackingSoldiers++;
        } else if(ourArmy[i]->getRank() == "Tank"){
            numberOfAttackingTanks++;
        } else if(ourArmy[i]->getRank() == "Plane"){
            numberOfAttackingPlanes++;
        } else if(ourArmy[i]->getRank() == "Ship"){
            numberOfAttackingShips++;
        } 
    }

    for (int i = 0; i < AIArmy.size(); i++) {
        if(AIArmy[i]->getType() == "soldier") {
            numberOfDefendingSoldiers++;
        } else if(AIArmy[i]->getRank() == "Tank"){
            numberOfDefendingTanks++;
        } else if(ourArmy[i]->getRank() == "Plane"){
            numberOfDefendingPlanes++;
        } else if(ourArmy[i]->getRank() == "Ship"){
            numberOfDefendingShips++;
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
                        ourArmy[i]->setProbability(0.75);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Tank"){
                        AIArmy[i]->setProbability(0.15);
                    }
                }
            }

        }else if(playerAttackStrategy == "SeaAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Ship"){
                        ourArmy[i]->setProbability(0.15);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Tank"){
                        AIArmy[i]->setProbability(0.75);
                    }
                }
            }

        }

    }else if(CPUDefenseStrategy == "AirDefense"){

        if(playerAttackStrategy == "LandAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Tank"){
                        ourArmy[i]->setProbability(0.15);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Plane"){
                        AIArmy[i]->setProbability(0.75);
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
                        ourArmy[i]->setProbability(0.75);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Plane"){
                        AIArmy[i]->setProbability(0.15);
                    }
                }
            }

        }

    }else if(CPUDefenseStrategy == "SeaDefense"){

        if(playerAttackStrategy == "LandAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Tank"){
                        ourArmy[i]->setProbability(0.75);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Ship"){
                        AIArmy[i]->setProbability(0.15);
                    }
                }
            }

        }else if(playerAttackStrategy == "AirAttack"){

            for(int i=0; i<ourArmy.size(); i++){
                if(ourArmy[i]->getType() == "vehicle") {
                    if(ourArmy[i]->getRank() == "Tank"){
                        ourArmy[i]->setProbability(0.75);
                    }
                }
            }

            for(int i=0; i<AIArmy.size(); i++){
                if(AIArmy[i]->getType() == "vehicle") {
                    if(AIArmy[i]->getRank() == "Ship"){
                        AIArmy[i]->setProbability(0.15);
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
            while(numberOfAttackingTanks >= 0 && numberOfDefendingTanks >= 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" && ourArmy[attVehicleCounter]->getRank() != "Tank"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" && AIArmy[defendVehicleCounter]->getRank() != "Tank"){//increment counter till tank vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingTanks--;
                }else{
                    numberOfAttackingTanks--;
                }

                cout << "Attacker tanks remaining: " << numberOfAttackingTanks << endl;
                cout << "Defender tanks remaining: " << numberOfDefendingTanks << endl;
            }

        }else if(CPUDefenseStrategy == "AirDefense"){
            while(numberOfAttackingTanks >= 0 && numberOfDefendingPlanes >= 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" && ourArmy[attVehicleCounter]->getRank() != "Tank"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" && AIArmy[defendVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingPlanes--;
                }else{
                    numberOfAttackingTanks--;
                }

                cout << "Attacker tanks remaining: " << numberOfAttackingTanks << endl;
                cout << "Defender planes remaining: " << numberOfDefendingPlanes << endl;
            }
        }else if(CPUDefenseStrategy == "SeaDefense"){
            while(numberOfAttackingTanks >= 0 && numberOfDefendingShips >= 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" && ourArmy[attVehicleCounter]->getRank() != "Tank"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" && AIArmy[defendVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingShips--;
                }else{
                    numberOfAttackingTanks--;
                }

                cout << "Attacker tanks remaining: " << numberOfAttackingTanks << endl;
                cout << "Defender ships remaining: " << numberOfDefendingShips << endl;
            }
        }
    }else if(playerAttackStrategy == "AirAttack"){
        if(CPUDefenseStrategy == "LandDefense"){
            while(numberOfAttackingPlanes >= 0 && numberOfDefendingTanks >= 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" && ourArmy[attVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" && AIArmy[defendVehicleCounter]->getRank() != "Tank"){//increment counter till tank vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingTanks--;
                }else{
                    numberOfAttackingPlanes--;
                }

                cout << "Attacker planes remaining: " << numberOfAttackingPlanes << endl;
                cout << "Defender tanks remaining: " << numberOfDefendingTanks << endl;
            }

        }else if(CPUDefenseStrategy == "AirDefense"){
            while(numberOfAttackingPlanes >= 0 && numberOfDefendingPlanes >= 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" && ourArmy[attVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" && AIArmy[defendVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingPlanes--;
                }else{
                    numberOfAttackingPlanes--;
                }

                cout << "Attacker planes remaining: " << numberOfAttackingPlanes << endl;
                cout << "Defender planes remaining: " << numberOfDefendingPlanes << endl;
            }
        }else if(CPUDefenseStrategy == "SeaDefense"){
            while(numberOfAttackingPlanes >= 0 && numberOfDefendingShips >= 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" && ourArmy[attVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" && AIArmy[defendVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingShips--;
                }else{
                    numberOfAttackingPlanes--;
                }

                cout << "Attacker planes remaining: " << numberOfAttackingPlanes << endl;
                cout << "Defender ships remaining: " << numberOfDefendingShips << endl;
            }
        }
    }else if(playerAttackStrategy == "SeaAttack"){
        if(CPUDefenseStrategy == "LandDefense"){
            while(numberOfAttackingShips >= 0 && numberOfDefendingTanks >= 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" && ourArmy[attVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" && AIArmy[defendVehicleCounter]->getRank() != "Tank"){//increment counter till tank vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingTanks--;
                }else{
                    numberOfAttackingShips--;
                }

                cout << "Attacker ships remaining: " << numberOfAttackingShips << endl;
                cout << "Defender tanks remaining: " << numberOfDefendingTanks << endl;
            }

        }else if(CPUDefenseStrategy == "AirDefense"){
            while(numberOfAttackingShips >= 0 && numberOfDefendingPlanes >= 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" && ourArmy[attVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" && AIArmy[defendVehicleCounter]->getRank() != "Plane"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingPlanes--;
                }else{
                    numberOfAttackingShips--;
                }

                cout << "Attacker ships remaining: " << numberOfAttackingShips << endl;
                cout << "Defender planes remaining: " << numberOfDefendingPlanes << endl;
            }
        }else if(CPUDefenseStrategy == "SeaDefense"){
            while(numberOfAttackingShips >= 0 && numberOfDefendingShips >= 0){ //keep fighting until one of the countries vehicles dies

                while(ourArmy[attVehicleCounter]->getType() != "vehicle" && ourArmy[attVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    attVehicleCounter++;
                }

                while(AIArmy[defendVehicleCounter]->getType() != "vehicle" && AIArmy[defendVehicleCounter]->getRank() != "Ship"){//increment counter till vehicle found in array
                    defendVehicleCounter++;
                }

                result = randomNumber(ourArmy[attVehicleCounter]->getProbability()); //resturns either 0 or 1, 1 for win and 0 for loss

                if(result == 1){
                    numberOfDefendingShips--;
                }else{
                    numberOfAttackingShips--;
                }

                cout << "Attacker ships remaining: " << numberOfAttackingShips << endl;
                cout << "Defender ships remaining: " << numberOfDefendingShips << endl;
            }
        }
    }
}







    // while (numberOfAttackers >= 0 && numberOfDefenders >= 0) {
    //         while(ourArmy[attCounter]->getType() != "soldier"){//increment counter till soldier found in array
    //             attCounter++;
    //         }

    //         while(AIArmy[defendCounter]->getType() != "soldier"){//increment counter till soldier found in array
    //             defendCounter++;
    //         }


    //         string attRank = ourArmy[attCounter]->getRank();

    //         string defRank = AIArmy[defendCounter]->getRank();

    //         if (attRank == "Major")  {

    //             switch(defRank[0]) {
    //                 case 'M':
    //                     ourArmy[attCounter]->setProbability(0.5);
    //                     AIArmy[defendCounter]->setProbability(0.5);
    //                     break;
    //                 case 'P':
    //                     ourArmy[attCounter]->setProbability(0.85);
    //                     AIArmy[defendCounter]->setProbability(0.15);
    //                     break;
    //                 case 'S':
    //                     ourArmy[attCounter]->setProbability(0.6);
    //                     AIArmy[defendCounter]->setProbability(0.4);
    //                     break;
    //                 default:
    //                     ourArmy[attCounter]->setProbability(0);
    //                     AIArmy[defendCounter]->setProbability(0);
    //                     break;
    //             }

    //         } else if (attRank == "Private") {
    //             switch(defRank[0]) {
    //                 case 'M':
    //                     ourArmy[attCounter]->setProbability(0.15);
    //                     AIArmy[defendCounter]->setProbability(0.85);
    //                     break;
    //                 case 'P':
    //                     ourArmy[attCounter]->setProbability(0.5);
    //                     AIArmy[defendCounter]->setProbability(0.5);
    //                     break;
    //                 case 'S':
    //                     ourArmy[attCounter]->setProbability(0.4);
    //                     AIArmy[defendCounter]->setProbability(0.6);
    //                     break;
    //                 default:
    //                     ourArmy[attCounter]->setProbability(0);
    //                     AIArmy[defendCounter]->setProbability(0);
    //                     break;
    //             }

    //         } else if (attRank == "Sergeant") {
    //             switch(defRank[0]) {
    //                 case 'M':
    //                     ourArmy[attCounter]->setProbability(0.4);
    //                     //cout << "attack prob at: " << numberOfAttackers << " : " << ourArmy[attCounter]->getProbability();
    //                     AIArmy[defendCounter]->setProbability(0.6);
    //                     break;
    //                 case 'P':
    //                     ourArmy[attCounter]->setProbability(0.6);
    //                     AIArmy[defendCounter]->setProbability(0.4);
    //                     break;
    //                 case 'S':
    //                     ourArmy[attCounter]->setProbability(0.5);
    //                     AIArmy[defendCounter]->setProbability(0.5);
    //                     break;
    //                 default:
    //                     ourArmy[attCounter]->setProbability(0);
    //                     AIArmy[defendCounter]->setProbability(0);
    //                     break;
    //             }
    //         }
    // }



    // bool hasAtLeastOneTank = false;

    // for(int i=0; i < ourArmy.size(); i++){
    //     if(ourArmy[i]->getRank() == "Tank"){
    //         hasAtLeastOneTank = true;
    //     }
    // }

    // if(hasAtLeastOneTank){
    //     int numberOfAttackers = 0;
    //     int numberOfDefenders = 0;

    //     int numberOfAttackingTanks = 0;
    //     int numberOfDefendingTanks = 0;

    //     for (int i = 0; i < ourArmy.size(); i++) {
    //         if(ourArmy[i]->getType() == "soldier") {
    //             numberOfAttackers++;
    //         } else if(ourArmy[i]->getRank() == "Tank"){
    //             numberOfAttackingTanks++;
    //         }
    //     }

    //     for(int i=0; i<AIArmy.size(); i++){
    //         if(AIArmy[i]->getType() == "soldier"){
    //         numberOfDefenders++;
    //         }else if(ourArmy[i]->getRank() == "Tank"){
    //             numberOfDefendingTanks++;
    //         }
    //     }

    //     int attCounter = 0;
    //     int defendCounter = 0;


    //     //for the soldiers fighting
    //     while (numberOfAttackers >= 0 && numberOfDefenders >= 0) {


    //         while(ourArmy[attCounter]->getType() != "soldier"){//increment counter till soldier found in array
    //         attCounter++;
    //         }

    //         while(AIArmy[defendCounter]->getType() != "soldier"){//increment counter till soldier found in array
    //             defendCounter++;
    //         }


    //         string attRank = ourArmy[attCounter]->getRank();

    //         string defRank = AIArmy[defendCounter]->getRank();

    //         if (attRank == "Major")  {

    //             switch(defRank[0]) {
    //                 case 'M':
    //                     ourArmy[attCounter]->setProbability(0.5);
    //                     AIArmy[defendCounter]->setProbability(0.5);
    //                     break;
    //                 case 'P':
    //                     ourArmy[attCounter]->setProbability(0.85);
    //                     AIArmy[defendCounter]->setProbability(0.15);
    //                     break;
    //                 case 'S':
    //                     ourArmy[attCounter]->setProbability(0.6);
    //                     AIArmy[defendCounter]->setProbability(0.4);
    //                     break;
    //                 default:
    //                     ourArmy[attCounter]->setProbability(0);
    //                     AIArmy[defendCounter]->setProbability(0);
    //                     break;
    //             }

    //         } else if (attRank == "Private") {
    //             switch(defRank[0]) {
    //                 case 'M':
    //                     ourArmy[attCounter]->setProbability(0.15);
    //                     AIArmy[defendCounter]->setProbability(0.85);
    //                     break;
    //                 case 'P':
    //                     ourArmy[attCounter]->setProbability(0.5);
    //                     AIArmy[defendCounter]->setProbability(0.5);
    //                     break;
    //                 case 'S':
    //                     ourArmy[attCounter]->setProbability(0.4);
    //                     AIArmy[defendCounter]->setProbability(0.6);
    //                     break;
    //                 default:
    //                     ourArmy[attCounter]->setProbability(0);
    //                     AIArmy[defendCounter]->setProbability(0);
    //                     break;
    //             }

    //         } else if (attRank == "Sergeant") {
    //             switch(defRank[0]) {
    //                 case 'M':
    //                     ourArmy[attCounter]->setProbability(0.4);
    //                     //cout << "attack prob at: " << numberOfAttackers << " : " << ourArmy[attCounter]->getProbability();
    //                     AIArmy[defendCounter]->setProbability(0.6);
    //                     break;
    //                 case 'P':
    //                     ourArmy[attCounter]->setProbability(0.6);
    //                     AIArmy[defendCounter]->setProbability(0.4);
    //                     break;
    //                 case 'S':
    //                     ourArmy[attCounter]->setProbability(0.5);
    //                     AIArmy[defendCounter]->setProbability(0.5);
    //                     break;
    //                 default:
    //                     ourArmy[attCounter]->setProbability(0);
    //                     AIArmy[defendCounter]->setProbability(0);
    //                     break;
    //             }
    //         }
    //     }


    //     //for the vehicles fighting
    //     int attVehicleCounter = 0;
    //     int defendVehicleCounter = 0;

    //     while(numberOfAttackingTanks >= 0 && numberOfDefendingTanks >= 0){
    //         while(ourArmy[attVehicleCounter]->getType() != "vehicle"){ //increment counter till vehicle found in array
    //            attVehicleCounter++;
    //         }

    //         while(AIArmy[defendVehicleCounter]->getType() != "vehicle"){  //increment counter till vehicle found in array
    //             defendVehicleCounter++;
    //         }

    //         string attVehicleRank = ourArmy[attVehicleCounter]->getRank();

    //         string defVehicleRank = AIArmy[defendVehicleCounter]->getRank();

    //         if(attVehicleRank == "Tank"){
    //             if(CPUDefenseStrategy == "TankDefense"){
    //                 ourArmy[attVehicleCounter]->setProbability(0.50); 
    //             }else if(CPUDefenseStrategy == "AirDefense"){
    //                 ourArmy[attVehicleCounter]->setProbability(0.15); 
    //             }else if(CPUDefenseStrategy == "SeaDefense"){
    //                 ourArmy[attVehicleCounter]->setProbability(0.75); 
    //             }
               
    //         }
    //     }
    // }else{
    //     //return message that user does not have enough tanks for this attack
    // }