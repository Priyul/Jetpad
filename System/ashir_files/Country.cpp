//
// Created by Ashir on 2022/10/29.
//

#include "Country.h"

using namespace std;

Country::Country(std::string name, double money) {
    this->name = name;
    this->money = money;
}

std::string Country::getCountryName() {
    return this->name;
}

double Country::getMoney() {
    return this->money;
}

int chooseArmyType(){
    int input;
    cout << "\033[1;31m" << "Choose an army type:" << "\033[0m" << endl;
    cout << "1. Build soldiers" << endl;
    cout << "2. Build vehicles" << endl;
    cin >> input;
    return input;
}

int chooseSoldierRank(){
    int input;
    cout << "\033[1;31m" << "Choose soldier rank" << "\033[0m" << endl;
    cout << "1. Major [R 500]" << endl;
    cout << "2. Sergeant [R 100]" << endl;
    cout << "3. Private [R 50]" << endl;
    cin >> input;
    return input;
}

int chooseArmySize(){
    int input;
    cout << "\033[1;31m" << "How many soldiers of this type would you like to make?" << "\033[0m" << endl;
    cin >> input;
    return input;
}

int buyMoreSoldiers(int secondInput){

    int thirdInput;
    bool secondPass = false;

    while(!secondPass){
        switch (secondInput) {
            case 1:
                cout << "Major selected" << endl;
                thirdInput = chooseArmySize();
                secondPass = true;
                break;
            case 2:
                cout << "Sergeant selected" << endl;
                thirdInput = chooseArmySize();
                secondPass = true;
                break;
            case 3:
                cout << "Private selected" << endl;
                thirdInput = chooseArmySize();
                secondPass = true;
                break;
            default:
                cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                secondInput = chooseSoldierRank();
        }
    }

    return thirdInput;
}

void Country::buildArmy() {

    char buyMore;

    do{

        if(this->getMoney() > 50){
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
                        firstPass = true;
                        break;
                    default:
                        cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                        firstInput = chooseArmyType();
                }
            }

            bool thirdPass = false;

            int thirdInput = buyMoreSoldiers(secondInput);

            while(!thirdPass){
                if(thirdInput < 0){ //chose a negative number for soldier or vehicle size
                    cout << "\033[7;31m" << "Invalid input, try again!" << "\033[0m" << endl;
                    thirdInput = chooseArmySize();
                }else if(thirdInput == 0){ //chose zero for soldier or vehicle size
                    cout << "\033[7;31m" << "No soldiers were bought" << "\033[0m" << endl;
                    thirdPass = true;
                }else{ //chose a positive value for soldier or vehicle size

                    if(secondInput == 1) { //rank is major
                        double cost = thirdInput * 500;
                        if(cost > this->getMoney()){ //not enough money for purchase
                            cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                            thirdInput = chooseArmySize();
                        }else{ //add soldiers to army and subtract cost from money
                            for(int i=0; i<thirdInput; i++){
                                Soldier* soldier = new Soldier("Major");
                                this->army.push_back(soldier);
                            }
                            this->money = this->money - cost;
                            cout << endl;
                            cout << "\033[1;32m" << "Soldiers have been added to your army!" << "\033[0m" << endl;
                            cout << "Remaining money: " << this->getMoney() << endl; //testing
                            thirdPass = true;
                        }
                    } else if(secondInput == 2)  { //rank is sergeant
                        double cost = thirdInput * 100;
                        if(cost > this->getMoney()){ //not enough money for purchase
                            cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                            thirdInput = chooseArmySize();
                        }else{ //add soldiers to army and subtract cost from money
                            for(int i=0; i<thirdInput; i++){
                                Soldier* soldier = new Soldier("Sergeant");
                                this->army.push_back(soldier);
                            }
                            this->money = this->money - cost;
                            cout << endl;
                            cout << "\033[1;32m" << "Soldiers have been added to your army!" << "\033[0m" << endl;
                            cout << "Remaining money: " << this->getMoney() << endl; //testing
                            thirdPass = true;
                        }
                    } else if(secondInput == 3) { //rank is private
                        double cost = thirdInput * 50;
                        if(cost > this->getMoney()){ //not enough money for purchase
                            cout << "\033[7;31m" << "You do not have enough money to make this purchase. Try again!" << "\033[0m" << endl;
                            thirdInput = chooseArmySize();
                        }else{ //add soldiers to army and subtract cost from money
                            for(int i=0; i<thirdInput; i++){
                                Soldier* soldier = new Soldier("Private");
                                this->army.push_back(soldier);
                            }
                            this->money = this->money - cost;
                            cout << endl;
                            cout << "\033[1;32m" << "Soldiers have been added to your army!" << "\033[0m" << endl;
                            cout << "Remaining money: " << this->getMoney() << endl; //testing
                            thirdPass = true;
                        }
                    }
                }
            }

            cout << "\033[1;33m" << "Would you like to purchase more soldiers? [Y/N]" << "\033[0m" << endl;
            cin >> buyMore;
        }else{
            cout << "\033[7;31m" << "You do not have enough money to make more purchases of any kind" << "\033[0m" << endl;
            buyMore = 'N';
        }

    }while(toupper(buyMore) == 'Y');

}

void Country::showArmy() {

    int majorCount = 0;
    int sergeantCount = 0;
    int privateCount = 0;

    for(int i=0; i<this->army.size(); i++){
        if(this->army[i]->getRank() == "Major"){
            majorCount++;
        }else if(this->army[i]->getRank() == "Sergeant"){
            sergeantCount++;
        }else if(this->army[i]->getRank() == "Private"){
            privateCount++;
        }
    }

    cout << endl << "\033[1;33m" << "Your army has: " << "\033[0m" << endl;
    cout << "\033[1;33m" << majorCount << " Majors" << "\033[0m" << endl;
    cout << "\033[1;33m" << sergeantCount << " Sergeants" << "\033[0m" << endl;
    cout << "\033[1;33m" << privateCount << " Privates" << "\033[0m" << endl;
}