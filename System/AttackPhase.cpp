#include "AttackPhase.h"
#include "Context.h"
#include "Action.h"
#include "DefendPhase.h"
#include "EndOfWar.h"
#include <iostream>
#include <string>
#include <iomanip>

//for testing
#include "WarStrategy.h"
#include "Attacking.h"
using namespace std;

AttackPhase :: AttackPhase(Engine *engine) {
    this->engine = engine;
}

void AttackPhase::handleAction(Context* c)
{

    Country* currentCountry = this->engine->whichPlayerTurnCountry();
    vector<Country*> currentCountryVector = this->engine->whichPlayerTurnVector();

    Country* notCurrentCountry = engine->whichNotPlayerTurnCountry();
    vector<Country*> notCurrentCountryVector = engine->whichNotPlayerTurnVector();
    
    int opposingCountryInput;
    for (int i = 0; i < notCurrentCountryVector.size(); i++) {
        string tempName;

        if(notCurrentCountryVector[i]->isMainCountry){
            tempName = notCurrentCountryVector[i]->getCountryName() + " (Main Country) ";
        }else{
            tempName = notCurrentCountryVector[i]->getCountryName();
        }

        notCurrentCountryVector[i]->countNumberOfIndividualTroops(notCurrentCountryVector[i]->army);
        cout << fixed;
        cout << setprecision(2);
        cout << i << " ==> " << "\033[1;33m" << tempName << "\033[0m" <<endl << "\033[1;32m" << "R " << notCurrentCountryVector[i]->getMoney() << endl <<
            "Soilders available: "<< notCurrentCountryVector[i]->numberOfMajors + notCurrentCountryVector[i]->numberOfSergeants + notCurrentCountryVector[i]->numberOfPrivates << endl <<
            "Majors available: " << notCurrentCountryVector[i]->numberOfMajors << endl <<
            "Sergent available: " << notCurrentCountryVector[i]->numberOfSergeants << endl <<
            "Private available: " <<  notCurrentCountryVector[i]->numberOfPrivates << endl <<
            endl <<
            "Vehicles available: " << notCurrentCountryVector[i]->numberOfPlanes + notCurrentCountryVector[i]->numberOfShips + notCurrentCountryVector[i]->numberOfTanks << endl <<
            "Tanks: " << (notCurrentCountryVector[i]->numberOfTanks) << endl <<
            "Ships: " << notCurrentCountryVector[i]->numberOfShips << endl << 
            "Planes: "  << notCurrentCountryVector[i]->numberOfPlanes << endl << endl <<
            "\033[0m" << endl;
    }
    cout << "\033[1;31m" << this->engine->printCurrentPlayer() << " Which opposing country would you like to attack? " << "\033[0m" << endl;
    cout << "select option: > ";
    cin >> opposingCountryInput;

    notCurrentCountry = notCurrentCountryVector[opposingCountryInput];


    currentCountry->countNumberOfIndividualTroops(currentCountry->army);

    Country* p1ArmyBeforeAttack = new Country();
    Country* p2ArmyBeforeAttack = new Country();

    p1ArmyBeforeAttack->army = currentCountry->getArmy();
    p2ArmyBeforeAttack->army = notCurrentCountry->getArmy();

    string CPUDefenseType;
    int CPUDefenseChoice;
    int AttackStrategyInput = -1;
    int ChooseNumberOfVehiclesToSend = -1;
    int ChooseNumberOfMajorsToSend = 0;
    int ChooseNumberOfSergeantsToSend = 0;
    int ChooseNumberOfPrivatesToSend = 0;

    string vehicleChosenForAttack;
    string PlayerAttackType;

    //MAKE AI CHOOSE A DEFENSE:
    srand(time(0));  // Initialize random number generator.

    while(CPUDefenseChoice != 1 && CPUDefenseChoice != 2 && CPUDefenseChoice != 3){
        cout << "\033[1;31m" << notCurrentCountry->whichPlayer << " Choose a defense strategy" << "\033[0m" << endl;
        cout << "1. Land Defense (You must own 1 or more Tanks)" << endl;
        cout << "2. Air Defense (You must own 1 or more Planes)" << endl;
        cout << "3. Sea Defense (You must own 1 or more Ships)" << endl;
        cout << "select option: > ";
        cin >> CPUDefenseChoice;
        

        if(CPUDefenseChoice != 1 && CPUDefenseChoice != 2 && CPUDefenseChoice != 3){
            cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
        }
    }

  

    if(CPUDefenseChoice == 1){
        CPUDefenseType = "LandDefense";
    }else if(CPUDefenseChoice == 2){
        CPUDefenseType = "AirDefense";
    }else if(CPUDefenseChoice == 3){
        CPUDefenseType = "SeaDefense";
    }else{
        cout << "Error in CPUDefenceChoice" << endl;
    }

    while(AttackStrategyInput != 1 && AttackStrategyInput != 2 && AttackStrategyInput != 3){
        cout << "\033[1;31m" << currentCountry->whichPlayer << " Choose Attack strategy" << "\033[0m" << endl;
        cout << "1. Land Attack (You must own 1 or more Tanks)" << endl;
        cout << "2. Air Attack (You must own 1 or more Planes)" << endl;
        cout << "3. Sea Attack (You must own 1 or more Ships)" << endl;
        cout << "select option: > ";
        cin >> AttackStrategyInput;

        if(AttackStrategyInput != 1 && AttackStrategyInput != 2 && AttackStrategyInput != 3){
            cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
        }
    }

    switch (AttackStrategyInput)
    {
        case 1:
            vehicleChosenForAttack = "Tank";
            PlayerAttackType = "LandAttack";
            break;
        case 2:
            vehicleChosenForAttack = "Plane";
            PlayerAttackType = "AirAttack";
            break;
        case 3:
            vehicleChosenForAttack = "Ship";
            PlayerAttackType = "SeaAttack";
            break;
    }
    
    if(vehicleChosenForAttack == "Tank"){
        if(currentCountry->numberOfTanks >= 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack? " << "\033[7;32m" << "Available: "  << currentCountry->numberOfTanks << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any tanks to make this kind of attack. Select a new attack strategy or build more tanks " << "\033[7;32m" << "Available: "  << currentCountry->numberOfTanks << "\033[0m" << endl;
            return;
        }
    }else if(vehicleChosenForAttack == "Plane"){
        if(currentCountry->numberOfPlanes >= 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack? " << "\033[7;32m" << "Available: "  << currentCountry->numberOfPlanes << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any planes to make this kind of attack. Select a new attack strategy or build more planes " << "\033[7;32m" << "Available: "  << currentCountry->numberOfPlanes << "\033[0m" << endl;
            return;
        }
    }else if(vehicleChosenForAttack == "Ship"){
        if(currentCountry->numberOfShips >= 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack? " << "\033[7;32m" << "Available: "  << currentCountry->numberOfShips << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any ships to make this kind of attack. Select a new attack strategy or build more ships " << "\033[7;32m" << "Available: "  << currentCountry->numberOfShips << "\033[0m" << endl;
            return;
        }
    }

    if(vehicleChosenForAttack == "Tank"){
        if(ChooseNumberOfVehiclesToSend > currentCountry->numberOfTanks){
            cout << "\033[7;31m" << "You do not have enough tanks to make this kind of attack. Select a new attack strategy or build more tanks " << "\033[7;32m" << "Available: "  << currentCountry->numberOfTanks << "\033[0m" << endl;
            return;
        }
    }else if(vehicleChosenForAttack == "Plane"){
        if(ChooseNumberOfVehiclesToSend > currentCountry->numberOfPlanes){
            cout << "\033[7;31m" << "You do not have enough planes to make this kind of attack. Select a new attack strategy or build more planes " << "\033[7;32m" << "Available: "  << currentCountry->numberOfPlanes << "\033[0m" << endl;
            return;
        }
    }else if(vehicleChosenForAttack == "Ship"){
        if(ChooseNumberOfVehiclesToSend > currentCountry->numberOfShips){
            cout << "\033[7;31m" << "You do not have enough ships to make this kind of attack. Select a new attack strategy or build more ships " << "\033[7;32m" << "Available: "  << currentCountry->numberOfShips << "\033[0m" << endl;
            return;
        }
    }

    if(currentCountry->numberOfMajors > 0){
        cout << "\033[1;31m" << "How many Majors would you like to send for this attack? " << "\033[7;32m" << "Available: "  << currentCountry->numberOfMajors << "\033[0m" << endl;
        cout << "select option: > ";
        cin >> ChooseNumberOfMajorsToSend;

        if(ChooseNumberOfMajorsToSend > currentCountry->numberOfMajors){
            cout << "\033[7;31m" << "You do not have enough majors to make this kind of attack. Pick fewer mages to send to war or make more majors instead " << "\033[7;32m" << "Available: "  << currentCountry->numberOfMajors << "\033[0m" << endl;
            return;
        }
    }

    if(currentCountry->numberOfSergeants > 0){
        cout << "\033[1;31m" << "How many Sergeants would you like to send for this attack? " << "\033[7;32m" << "Available: "  << currentCountry->numberOfSergeants << "\033[0m" << endl;
        cout << "select option: > ";
        cin >> ChooseNumberOfSergeantsToSend;

        if(ChooseNumberOfSergeantsToSend > currentCountry->numberOfSergeants){
            cout << "\033[7;31m" << "You do not have enough sergeants to make this kind of attack. Pick fewer sergeants to send to war or make more sergeants instead " << "\033[7;32m" << "Available: "  << currentCountry->numberOfSergeants << "\033[0m" << endl;
            return;
        }
    }

    if(currentCountry->numberOfPrivates > 0){
        cout << "\033[1;31m" << "How many Privates would you like to send for this attack? " << "\033[7;32m" << "Available: "  << currentCountry->numberOfPrivates << "\033[0m" << endl;
        cout << "select option: > ";
        cin >> ChooseNumberOfPrivatesToSend;

        if(ChooseNumberOfPrivatesToSend > currentCountry->numberOfPrivates){
            cout << "\033[7;31m" << "You do not have enough privates to make this kind of attack. Pick fewer privates to send to war or make more privates instead " << "\033[7;32m" << "Available: "  << currentCountry->numberOfPrivates << "\033[0m" << endl;
            return;
        }
    }

    // vector<Army*> aiArmy;    //testing begin

    // for(int i=0; i<20; i++){
    //     aiArmy.push_back(new Soldier("Private", 0.5));
    // }

    // for(int i=0; i<10; i++){
    //     aiArmy.push_back(new Soldier("Major", 0.5));
    // }

    // for(int i=0; i<40; i++){
    //     aiArmy.push_back(new Soldier("Sergeant", 0.5));
    // }

    // for(int i=0; i<3; i++){
    //     aiArmy.push_back(new Vehicle("Ship", 0));
    // }

    // for(int i=0; i<5; i++){
    //     aiArmy.push_back(new Vehicle("Tank", 0));
    // }

    // for(int i=0; i <notCurrentCountry->army.size(); i++){
    //     cout << "player 2 army at: " << i << " " << notCurrentCountry->army[i]->getRank() << endl;
    // }

    WarStrategy* attackStrategy = new Attacking();

    attackStrategy->handle(currentCountry->army, notCurrentCountry->army, PlayerAttackType, CPUDefenseType, ChooseNumberOfVehiclesToSend, ChooseNumberOfMajorsToSend, ChooseNumberOfSergeantsToSend, ChooseNumberOfPrivatesToSend, engine);
    
    cout << endl;
    cout << "before attack" << endl << endl;
    cout << "\033[1;32m" << "Player 1 army before the attack (" << currentCountry->getCountryName() << ")" << "\033[0m";
    p1ArmyBeforeAttack->showArmy();
    cout << endl;

    cout << "\033[1;32m" << "Player 2 army before the attack (" << notCurrentCountry->getCountryName() << ")" << "\033[0m";
    p2ArmyBeforeAttack->showArmy();
    cout << endl;



    cout << "after attack" << endl << endl;
    cout << "\033[1;32m" << "Player 1 army after the attack (" << currentCountry->getCountryName() << ")" << "\033[0m";
    currentCountry->showArmy();
    cout << endl;

    cout << "\033[1;32m" << "Player 2 army after the attack (" << notCurrentCountry->getCountryName() << ")" << "\033[0m";
    notCurrentCountry->showArmy();
    cout << endl;

    //CHECK if country still has money and an army
    
    int numVehicles = notCurrentCountry->numberOfPlanes + notCurrentCountry->numberOfShips + notCurrentCountry->numberOfTanks;

    int numberOfVehiclesThatCameBack = 0; 

    if(CPUDefenseType == "LandDefense"){
        for(int i=0; i<notCurrentCountry->army.size(); i++){
            if(notCurrentCountry->army[i]->getRank() == "Tank"){
                numberOfVehiclesThatCameBack++;
            }
        }
    }else if(CPUDefenseType == "AirDefense"){
        for(int i=0; i<notCurrentCountry->army.size(); i++){
            if(notCurrentCountry->army[i]->getRank() == "Plane"){
                numberOfVehiclesThatCameBack++;
            }
        }
    }else if(CPUDefenseType == "SeaDefense"){
        for(int i=0; i<notCurrentCountry->army.size(); i++){
            if(notCurrentCountry->army[i]->getRank() == "Ship"){
                numberOfVehiclesThatCameBack++;
            }
        }
    }


    if (notCurrentCountry->getMoney() < 20000 || numberOfVehiclesThatCameBack == 0) {
        notCurrentCountry->hasLost = true;


        if (notCurrentCountry->isMainCountry == true) {
            c->setState(new EndOfWar(this->engine));
            return;
        }else{
               
            auto it = find(notCurrentCountryVector.begin(), notCurrentCountryVector.end(), notCurrentCountry);
            if(it != notCurrentCountryVector.end()){
                cout << "he got removed" << endl << endl;

                notCurrentCountryVector.erase(it);
         
                if (this->engine->isP1Turn == true) {
                    this->engine->P2CountryVector = notCurrentCountryVector;
                } else {
                    this->engine->P1CountryVector = notCurrentCountryVector;
                    
                }
            }
        }
           
    }

    this->engine->switchTurns();

    c->setState(new ChoosePlayerPhase(this->engine));

    return;
    //Jackie code:
    // int num;
    // cout<<"-----------------------------------------------"<<endl;
    // cout<<c->getState()<<endl;
    // cout<<"State: Attack Phase"<<endl;
    // cout<<endl;
    // //cout<< "Country "<< this->myCountry->getName() << "is declaring war on "<< << endl;
    // cout<<endl; 

    // cin>>num;
    // if(num == 1)
    // {
    //     c->setState(new Action(this->engine));
    // }
    // else if(num == 2)
    // {
    //     c->setState(new DefendPhase(this->engine));
    // }
    // else if(num == 3)
    // {
    //     c->setState(new EndOfWar());
    // }
    
}

string AttackPhase::getState(){
    return "(Attack state)";
}