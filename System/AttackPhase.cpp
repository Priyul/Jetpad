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

    int opposingCountryInput;
    for (int i = 0; i < this->engine->P2CountryVector.size(); i++) {
        string tempName;

        if(this->engine->P2CountryVector[i]->isMainCountry){
            tempName = this->engine->P2CountryVector[i]->getCountryName() + " (Main Country) ";
        }else{
            tempName = this->engine->P2CountryVector[i]->getCountryName();
        }

        this->engine->P2CountryVector[i]->countNumberOfIndividualTroops(this->engine->P2CountryVector[i]->army);
        cout << fixed;
        cout << setprecision(2);
        cout << i << " ==> " << "\033[1;33m" << tempName << "\033[0m" <<endl << "\033[1;32m" << "R " << this->engine->P2CountryVector[i]->getMoney() << endl <<
            "Soilders available: "<< this->engine->P2CountryVector[i]->numberOfMajors + this->engine->P2CountryVector[i]->numberOfSergeants + this->engine->P2CountryVector[i]->numberOfPrivates << endl <<
            "Majors available: " << this->engine->P2CountryVector[i]->numberOfMajors << endl <<
            "Sergent available: " << this->engine->P2CountryVector[i]->numberOfSergeants << endl <<
            "Private available: " <<  this->engine->P2CountryVector[i]->numberOfPrivates << endl <<
            endl <<
            "Vehicles available: " << this->engine->P2CountryVector[i]->numberOfPlanes + this->engine->P2CountryVector[i]->numberOfShips + this->engine->P2CountryVector[i]->numberOfTanks << endl <<
            "Tanks: " << (this->engine->P2CountryVector[i]->numberOfTanks) << endl <<
            "Ships: " << this->engine->P2CountryVector[i]->numberOfShips << endl << 
            "Planes: "  << this->engine->P2CountryVector[i]->numberOfPlanes << endl << endl <<
            "\033[0m" << endl;
    }
    cout << "\033[1;31m" << "Which opposing country would you like to attack? " << "\033[0m" << endl;
    cout << "select option: > ";
    cin >> opposingCountryInput;

    engine->P2SelectedCountry = engine->P2CountryVector[opposingCountryInput];


    this->engine->P1SelectedCountry->countNumberOfIndividualTroops(this->engine->P1SelectedCountry->army);

    Country* p1ArmyBeforeAttack = new Country();
    Country* p2ArmyBeforeAttack = new Country();

    p1ArmyBeforeAttack->army = this->engine->P1SelectedCountry->getArmy();
    p2ArmyBeforeAttack->army = this->engine->P2SelectedCountry->getArmy();

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
    CPUDefenseChoice = (rand() % 3) + 0;

    if(CPUDefenseChoice == 0){
        CPUDefenseType = "LandDefense";
    }else if(CPUDefenseChoice == 1){
        CPUDefenseType = "AirDefense";
    }else if(CPUDefenseChoice == 2){
        CPUDefenseType = "SeaDefense";
    }else{
        cout << "Error in CPUDefenceChoice" << endl;
    }

    while(AttackStrategyInput != 1 && AttackStrategyInput != 2 && AttackStrategyInput != 3){
        cout << "\033[1;31m" << "Choose Attack strategy" << "\033[0m" << endl;
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
        if(this->engine->P1SelectedCountry->numberOfTanks >= 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfTanks << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any tanks to make this kind of attack. Select a new attack strategy or build more tanks " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfTanks << "\033[0m" << endl;
            return;
        }
    }else if(vehicleChosenForAttack == "Plane"){
        if(this->engine->P1SelectedCountry->numberOfPlanes >= 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfPlanes << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any planes to make this kind of attack. Select a new attack strategy or build more planes " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfPlanes << "\033[0m" << endl;
            return;
        }
    }else if(vehicleChosenForAttack == "Ship"){
        if(this->engine->P1SelectedCountry->numberOfShips >= 1){
            cout << "\033[1;31m" << "How many " << vehicleChosenForAttack << "s would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfShips << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> ChooseNumberOfVehiclesToSend;
        }else{
            cout << "\033[7;31m" << "You do not have any ships to make this kind of attack. Select a new attack strategy or build more ships " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfShips << "\033[0m" << endl;
            return;
        }
    }

    if(vehicleChosenForAttack == "Tank"){
        if(ChooseNumberOfVehiclesToSend > this->engine->P1SelectedCountry->numberOfTanks){
            cout << "\033[7;31m" << "You do not have enough tanks to make this kind of attack. Select a new attack strategy or build more tanks " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfTanks << "\033[0m" << endl;
            return;
        }
    }else if(vehicleChosenForAttack == "Plane"){
        if(ChooseNumberOfVehiclesToSend > this->engine->P1SelectedCountry->numberOfPlanes){
            cout << "\033[7;31m" << "You do not have enough planes to make this kind of attack. Select a new attack strategy or build more planes " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfPlanes << "\033[0m" << endl;
            return;
        }
    }else if(vehicleChosenForAttack == "Ship"){
        if(ChooseNumberOfVehiclesToSend > this->engine->P1SelectedCountry->numberOfShips){
            cout << "\033[7;31m" << "You do not have enough ships to make this kind of attack. Select a new attack strategy or build more ships " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfShips << "\033[0m" << endl;
            return;
        }
    }

    if(this->engine->P1SelectedCountry->numberOfMajors > 0){
        cout << "\033[1;31m" << "How many Majors would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfMajors << "\033[0m" << endl;
        cout << "select option: > ";
        cin >> ChooseNumberOfMajorsToSend;

        if(ChooseNumberOfMajorsToSend > this->engine->P1SelectedCountry->numberOfMajors){
            cout << "\033[7;31m" << "You do not have enough majors to make this kind of attack. Pick fewer mages to send to war or make more majors instead " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfMajors << "\033[0m" << endl;
            return;
        }
    }

    if(this->engine->P1SelectedCountry->numberOfSergeants > 0){
        cout << "\033[1;31m" << "How many Sergeants would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfSergeants << "\033[0m" << endl;
        cout << "select option: > ";
        cin >> ChooseNumberOfSergeantsToSend;

        if(ChooseNumberOfSergeantsToSend > this->engine->P1SelectedCountry->numberOfSergeants){
            cout << "\033[7;31m" << "You do not have enough sergeants to make this kind of attack. Pick fewer sergeants to send to war or make more sergeants instead " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfSergeants << "\033[0m" << endl;
            return;
        }
    }

    if(this->engine->P1SelectedCountry->numberOfPrivates > 0){
        cout << "\033[1;31m" << "How many Privates would you like to send for this attack? " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfPrivates << "\033[0m" << endl;
        cout << "select option: > ";
        cin >> ChooseNumberOfPrivatesToSend;

        if(ChooseNumberOfPrivatesToSend > this->engine->P1SelectedCountry->numberOfPrivates){
            cout << "\033[7;31m" << "You do not have enough privates to make this kind of attack. Pick fewer privates to send to war or make more privates instead " << "\033[7;32m" << "Available: "  << this->engine->P1SelectedCountry->numberOfPrivates << "\033[0m" << endl;
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

    // for(int i=0; i <engine->P2SelectedCountry->army.size(); i++){
    //     cout << "player 2 army at: " << i << " " << engine->P2SelectedCountry->army[i]->getRank() << endl;
    // }

    WarStrategy* attackStrategy = new Attacking();

    attackStrategy->handle(this->engine->P1SelectedCountry->army, engine->P2SelectedCountry->army, PlayerAttackType, CPUDefenseType, ChooseNumberOfVehiclesToSend, ChooseNumberOfMajorsToSend, ChooseNumberOfSergeantsToSend, ChooseNumberOfPrivatesToSend);
    
    cout << endl;
    cout << "before attack" << endl << endl;
    cout << "\033[1;32m" << "Player 1 army before the attack (" << this->engine->P1SelectedCountry->getCountryName() << ")" << "\033[0m";
    p1ArmyBeforeAttack->showArmy();
    cout << endl;

    cout << "\033[1;32m" << "Player 2 army before the attack (" << this->engine->P2SelectedCountry->getCountryName() << ")" << "\033[0m";
    p2ArmyBeforeAttack->showArmy();
    cout << endl;



    cout << "after attack" << endl << endl;
    cout << "\033[1;32m" << "Player 1 army after the attack (" << this->engine->P1SelectedCountry->getCountryName() << ")" << "\033[0m";
    this->engine->P1SelectedCountry->showArmy();
    cout << endl;

    cout << "\033[1;32m" << "Player 2 army after the attack (" << this->engine->P2SelectedCountry->getCountryName() << ")" << "\033[0m";
    this->engine->P2SelectedCountry->showArmy();
    cout << endl;

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