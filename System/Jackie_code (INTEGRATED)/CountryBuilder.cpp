#include "CountryBuilder.h"

CountryBuilder :: CountryBuilder() {
    this->country = new Country();
}
    
void CountryBuilder :: buildName(string name) {
    this->country->setName(name);
}

void CountryBuilder :: buildArmy() {

    int firstInput = 2; //build army option selected
    bool firstPass = false;

    vector<Army*> returningArmy;
    //this->country->buildArmy();
    //this->country->
    char buyMore;

    ArmyFactory* soldierFactory = new SoldierFactory();
    ArmyFactory* vehicleFactory = new VehicleFactory();

    do{

        if(this->country->getMoney() > 50){
            int firstInput = chooseArmyType(); 
            bool firstPass = false;

            int secondInput;
            bool secondPass = false;

            while(!firstPass) {
                switch (firstInput) {
                    case 1:
                        cout << "Soldier selected" << endl;
                        secondInput = chooseSoldierRank();
                        firstPass = true;
                        break;
                    case 2:
                        cout << "Vehicle selected" << endl;
                        secondInput = chooseVehicleType();
                        firstPass = true;
                        break;
                    default:
                        cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                        firstInput = chooseArmyType();
                }
            }

            bool thirdPass = false;
            int thirdInput;

            string vehicleOrSoldier;

            if(firstInput == 1){
                thirdInput = buyMoreSoldiers(secondInput, "soldier");
                vehicleOrSoldier = "soldier";
            }else{
                thirdInput = buyMoreSoldiers(secondInput, "vehicle");
                vehicleOrSoldier = "vehicle";
            }

            while(!thirdPass){
                if(thirdInput < 0){ //chose a negative number for soldier or vehicle size
                    cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                    thirdInput = chooseArmySize(vehicleOrSoldier);
                }else if(thirdInput == 0){ //chose zero for soldier or vehicle size
                    if(vehicleOrSoldier == "soldier"){
                        cout << "\033[7;31m" << "No soldiers were bought" << "\033[0m" << endl;
                    }else{
                        cout << "\033[7;31m" << "No vehicles were bought" << "\033[0m" << endl;
                    }
                    thirdPass = true;
                }else{ //chose a positive value for soldier or vehicle size

                    if(vehicleOrSoldier == "soldier"){
                        if(secondInput == 1) { //rank is major
                            double cost = thirdInput * 500;
                            if(cost > this->country->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add soldiers to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->country->army.push_back(new Soldier("Major", 0.5));
                                }
                                this->country->setMoney(this->country->getMoney() - cost);
                                cout << endl;
                                cout << "\033[1;32m" << "Soldiers have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->country->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        } else if(secondInput == 2)  { //rank is sergeant
                            double cost = thirdInput * 100;
                            if(cost > this->country->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add soldiers to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->country->army.push_back(new Soldier("Sergeant", 0.5));
                                }
                                this->country->setMoney(this->country->getMoney() - cost);
                                cout << endl;
                                cout << "\033[1;32m" << "Soldiers have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->country->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        } else if(secondInput == 3) { //rank is private
                            double cost = thirdInput * 50;
                            if(cost > this->country->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add soldiers to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->country->army.push_back(new Soldier("Private", 0.5));
                                }
                                this->country->setMoney(this->country->getMoney() - cost);
                                cout << endl;
                                cout << "\033[1;32m" << "Soldiers have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->country->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        }
                    }else if(vehicleOrSoldier == "vehicle"){
                        if(secondInput == 1) { //type is plane
                            double cost = thirdInput * 10000;
                            if(cost > this->country->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add vehicles to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->country->army.push_back(new Vehicle("Plane", 0));
                                }
                                this->country->setMoney(this->country->getMoney()-cost);
                                cout << endl;
                                cout << "\033[1;32m" << "Planes have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->country->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        } else if(secondInput == 2)  { //type is tank
                            double cost = thirdInput * 10000;
                            if(cost > this->country->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add vehicles to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->country->army.push_back(new Vehicle("Tank", 0));
                                }
                                this->country->setMoney(this->country->getMoney() - cost);
                                cout << endl;
                                cout << "\033[1;32m" << "Tanks have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->country->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        } else if(secondInput == 3) { //type is ship
                            double cost = thirdInput * 10000;
                            if(cost > this->country->getMoney()){ //not enough money for purchase
                                cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                                thirdInput = chooseArmySize(vehicleOrSoldier);
                            }else{ //add soldiers to army and subtract cost from money
                                for(int i=0; i<thirdInput; i++){
                                    this->country->army.push_back(new Vehicle("Ship", 0));
                                }
                                this->country->setMoney(this->country->getMoney() - cost);
                                cout << endl;
                                cout << "\033[1;32m" << "Ships have been added to your army!" << "\033[0m" << endl;
                                cout << "Remaining money: " << this->country->getMoney() << endl; //testing
                                thirdPass = true;
                            }
                        }
                    }
                    
                }
            }

            cout << "\033[1;33m" << "Would you like to purchase more troops? [Y/N]" << "\033[0m" << endl;
            cout << "select option: > ";
            cin >> buyMore;
        }else{
            cout << "\033[7;31m" << "You do not have enough money to make more purchases of any kind" << "\033[0m" << endl;
            buyMore = 'N';
        }

    }while(toupper(buyMore) == 'Y');
    

                 
}

int CountryBuilder :: chooseArmyType(){
    int input;
    cout << "\033[1;31m" << "Choose an army type:" << "\033[0m" << endl;
    cout << "1. Build soldiers" << endl;
    cout << "2. Build vehicles" << endl;
    cout << "select option: > ";
    cin >> input;
    return input;
}

int CountryBuilder :: chooseSoldierRank(){
    int input;
    cout << "\033[1;31m" << "Choose soldier rank" << "\033[0m" << endl;
    cout << "1. Major [R 500]" << endl;
    cout << "2. Sergeant [R 100]" << endl;
    cout << "3. Private [R 50]" << endl;
    cout << "select option: > ";
    cin >> input;
    return input;
}

int CountryBuilder :: chooseVehicleType(){
    int input;
    cout << "\033[1;31m" << "Choose vehicle type" << "\033[0m" << endl;
    cout << "1. Planes [R 10 000]" << endl;
    cout << "2. Tanks [R 10 000]" << endl;
    cout << "3. Ships [R 10 000]" << endl;
    cout << "select option: > ";
    cin >> input;
    return input;
}

int CountryBuilder :: buyMoreSoldiers(int secondInput, string type){

    int thirdInput;
    bool secondPass = false;

    if(type == "soldier"){
        while(!secondPass){
            switch (secondInput) {
                case 1:
                    cout << "Major selected" << endl;
                    thirdInput = chooseArmySize("soldier");
                    secondPass = true;
                    break;
                case 2:
                    cout << "Sergeant selected" << endl;
                    thirdInput = chooseArmySize("soldier");
                    secondPass = true;
                    break;
                case 3:
                    cout << "Private selected" << endl;
                    thirdInput = chooseArmySize("soldier");
                    secondPass = true;
                    break;
                default:
                    cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                    secondInput = chooseSoldierRank();
            }
        }
    }else if(type == "vehicle"){
        while(!secondPass){
            switch (secondInput) {
                case 1:
                    cout << "Plane selected" << endl;
                    thirdInput = chooseArmySize("vehicle");
                    secondPass = true;
                    break;
                case 2:
                    cout << "Tank selected" << endl;
                    thirdInput = chooseArmySize("vehicle");
                    secondPass = true;
                    break;
                case 3:
                    cout << "Ship selected" << endl;
                    thirdInput = chooseArmySize("vehicle");
                    secondPass = true;
                    break;
                default:
                    cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                    secondInput = chooseSoldierRank();
            }
        }
    }

    return thirdInput;
}

int CountryBuilder :: chooseArmySize(string type){
    int input;
    if(type == "soldier"){
        cout << "\033[1;31m" << "How many soldiers of this type would you like to make?" << "\033[0m" << endl;
    }else{
        cout << "\033[1;31m" << "How many vehicles of this type would you like to make?" << "\033[0m" << endl;
    }
    cout << "select option: > ";
    cin >> input;
    return input;
} //up  till here

void CountryBuilder :: buildMoney(double money) {
    this->country->setMoney(money);
}

Country* CountryBuilder :: getCountry() {
    return this->country;
}

