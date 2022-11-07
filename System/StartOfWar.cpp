#include "StartOfWar.h"
#include "Context.h"
#include "Action.h"

#include <iostream>
#include <ctime> //for random number generation
#include <cstdlib> //for random number generation
#include <string>
#include <iomanip>


#include <algorithm>
#include <vector>

/* BUILDER INTEGRATON */
#include "Director.h"

/* END OF BUILDER INTEGRATON */


using namespace std;

void StartOfWar::handleAction(Context* c){

    srand(time(0));

    string myCountry="";
    int num;
    cout << c->getState() << endl;
    cout<<"State: Start of war"<<endl;

    // 

    /* builder integration */

    string countryNames[12] = {"United States of America", "Russia", "China", "United Kingdom", "Canada", "Japan", "Australia", "Egypt", "Iraq","South Africa", "Zimbabwe", "Nepal"};
    double countryMoney[12] = {25000000.00, 21000000.00, 14000000.00, 13500000.00, 11000000.00 , 18250000.00, 9000000.00, 5000000.00, 4500000.00, 3800000.00, 2000000.00, 1000000.00 };
    
    vector<Country*> countriesVector;
    vector<double> moneyVector;
    for (int i = 0; i < 12; i++) {
        countriesVector.push_back(buildCountry(countryNames[i], countryMoney[i])); //building the countries & storing them inn the country vector
    }

    cout << "\033[1;31m" <<"The countries you can select from are listed below: " << "\033[0m" << endl;
    for(int i = 0; i < 12; i++){
        cout<< i <<" ==> "<< countriesVector[i]->getCountryName() << endl;
    }

    for (int i = 0; i < 12; i++) {
        if (countriesVector[i]->getCountryName() == "United States of America") {
            countriesVector[i]->setCostOfCountry(20000000);
        } else if (countriesVector[i]->getCountryName() == "Russia") {
            countriesVector[i]->setCostOfCountry(17000000);
        } else if (countriesVector[i]->getCountryName() == "China") {
            countriesVector[i]->setCostOfCountry(12000000);
        } else if (countriesVector[i]->getCountryName() == "United Kingdom") {
            countriesVector[i]->setCostOfCountry(10000000);
        } else if (countriesVector[i]->getCountryName() == "Japan") {
            countriesVector[i]->setCostOfCountry(7000000);
        } else if (countriesVector[i]->getCountryName() == "Canada") {
            countriesVector[i]->setCostOfCountry(5000000);
        } else if (countriesVector[i]->getCountryName() == "Australia") {
            countriesVector[i]->setCostOfCountry(4000000);
        } else if (countriesVector[i]->getCountryName() == "Egypt") {
            countriesVector[i]->setCostOfCountry(2000000);
        } else if (countriesVector[i]->getCountryName() == "Iraq") {
            countriesVector[i]->setCostOfCountry(1600000);
        } else if (countriesVector[i]->getCountryName() == "South Africa") {
            countriesVector[i]->setCostOfCountry(1000000);
        } else if (countriesVector[i]->getCountryName() == "Zimbabwe") {
            countriesVector[i]->setCostOfCountry(700000);
        } else if (countriesVector[i]->getCountryName() == "Nepal") {
            countriesVector[i]->setCostOfCountry(300000);
        }
    }


/* ~~~~~~~~~~~~~~ P1 initial country pick */ 

    Country* P1Country;
    vector<Country*> P1Vector;
    Country* P2Country;
    vector<Country*> P2Vector;

    cout << "\033[1;31m" << "P1 enter the number that represents the Country you want to play with:" << "\033[0m" << endl;
    cout << "select option: > ";
    cin >> num;
    countriesVector[num]->isMainCountry = true;
    cout << "The country you have selected: " << countriesVector[num]->getCountryName() <<endl;

    P1Country = countriesVector[num]; //p1 country stored in as an object
    P1Country->setArmy(0,0,0,0,0,0);
    P1Country->setMoney(50000000);
    P1Country->whichPlayer = "P1";
    P1Vector.push_back(P1Country);

    //remove selected country from country vector
    auto it = find(countriesVector.begin(), countriesVector.end(), countriesVector[num]);
    if(it != countriesVector.end()){
        countriesVector.erase(it);
    }


/* ~~~~~~~~~~~~~~ */


    int P2input;
    cout << endl;
    cout << "\033[1;31m" <<"The countries you can select from are listed below: " << "\033[0m" << endl;
    
    for(int k = 0; k < countriesVector.size(); k++){
        cout<< k <<" ==> "<< countriesVector[k]->getCountryName() << endl;   
    }

    
    cout << "\033[1;31m" << "P2 enter the number that represents the Country you want to play with:" << "\033[0m" << endl;
    cout << "select option: > ";
    cin >> P2input;
    countriesVector[P2input]->isMainCountry = true;
    cout << "The country you have selected: " << countriesVector[P2input]->getCountryName() <<endl;

    P2Country = countriesVector[P2input]; //p2 country stored in as an object
    P2Country->setArmy(0,0,0,0,0,0);
    P2Country->setMoney(50000000);
    P2Country->whichPlayer = "P2";
    P2Vector.push_back(P2Country);


    //remove selected country from country vector
    auto it5 = find(countriesVector.begin(), countriesVector.end(), countriesVector[P2input]);
    if(it5 != countriesVector.end()){
        countriesVector.erase(it5);
    }

    int AllyInput1; //p1
    int AllyInput2; //p2

    cout << "\033[1;31m" <<"Select your alliances from the listed countries below: " << "\033[0m" << endl;

    for (int i = 0; i < 5; i++) {
    /* ~~~ P1 TURN ~~~ */
        //show available alliances...
        showAvailableAllies(countriesVector);
        cout << fixed;
        cout << setprecision(2);
        cout << "\033[1;31m" << "P1 select your allies: [Remaining Money: R" << P1Country->getMoney() << "]" << "\033[0m" << endl;
        cout << "select option: > ";
        cin >> AllyInput1;

        if (countriesVector[AllyInput1]->getCostOfCountry() > P1Country->getMoney()) {
            while (countriesVector[AllyInput1]->getCostOfCountry() > P1Country->getMoney()) {
                cout << "\033[1;31m" <<  "Not enough money to buy ally, pick again" << "\033[0m" << endl;
                cout <<  "select option: > ";
                cin >> AllyInput1;
            } 
        } else {
            P1Country->setMoney(P1Country->getMoney() - countriesVector[AllyInput1]->getCostOfCountry());
        }

        countriesVector[AllyInput1]->whichPlayer = "P1";
        P1Vector.push_back(countriesVector[AllyInput1]);
        
        //cout << "picked ally " << countriesVector[AllyInput1]->getCountryName() << endl;

        auto it6 = find(countriesVector.begin(), countriesVector.end(), countriesVector[AllyInput1]);
        if(it6 != countriesVector.end()){
            countriesVector.erase(it6);
        }

        //cout << count

/* ~~~ P2 TURN ~~~ */
        showAvailableAllies(countriesVector);
        cout << fixed;
        cout << setprecision(2);
        cout << "\033[1;31m" << "P2 select your allies: [Remaining Money: R" << P2Country->getMoney() << "]" << "\033[0m" << endl;
        cout << "select option: > ";
        cin >> AllyInput2;

        if (countriesVector[AllyInput2]->getCostOfCountry() > P2Country->getMoney()) {
            while (countriesVector[AllyInput2]->getCostOfCountry() > P2Country->getMoney()) {
                cout << "\033[1;31m" <<  "Not enough money to buy ally, pick again" << "\033[0m" << endl;
                cout <<  "select option: > ";
                cin >> AllyInput2;
            } 
        } else {
            P2Country->setMoney(P2Country->getMoney() - countriesVector[AllyInput2]->getCostOfCountry());
        }

        countriesVector[AllyInput2]->whichPlayer = "P2";
        P2Vector.push_back(countriesVector[AllyInput2]);
    
        //remove country from countries array
        auto it7 = find(countriesVector.begin(), countriesVector.end(), countriesVector[AllyInput2]);
        if(it7 != countriesVector.end()){
            countriesVector.erase(it7);
        }
    }

    Engine* engine = new Engine(P1Vector, P2Vector);

    engine->bank = new Bank();

    // Country* P2SelectedCountry;
    // cout << "\033[1;31m" << "P1 select which country to attack with:" << "\033[0m" << endl;
    // for (int i = 0; i < P2Vector.size(); i++) {
    //     cout << i << " ==> " << P2Vector[i]->getCountryName() << endl;
    // }
    // cin >> input;
    // P2SelectedCountry = P2Vector[input];


    c->setState(new ChoosePlayerPhase(engine));// implement

}

string StartOfWar::getState(){
    return "";
}


Country* StartOfWar :: getmyCountry() {
    return this->myCountry;
}


Country* StartOfWar :: getAllyCountry() {
    return this->allyCountry;
}

Country* StartOfWar :: buildCountry(string countryName, double money) {
    CountryBuilder* countryBuilder = new CountryBuilder();
    Director* countryDirector = new Director(countryBuilder);
    
    countryDirector->countryBuilder->buildName(countryName);
    countryDirector->countryBuilder->buildMoney(money);
    countryDirector->countryBuilder->buildArmy(); //automated

    Country* temp = countryBuilder->getCountry();

    return temp;
}

void StartOfWar :: showAvailableAllies(vector<Country*> allyCountries) {
    for (int i = 0; i < allyCountries.size(); i++) {

        allyCountries[i]->countNumberOfIndividualTroops(allyCountries[i]->army);
        cout << fixed;
        cout << setprecision(2);
        cout << i << " ==> " << "\033[1;33m" << allyCountries[i]->getCountryName() << "\033[0m" <<endl << "\033[1;32m" << "R " << allyCountries[i]->getMoney() << endl <<
            "Soilders available: "<< allyCountries[i]->numberOfMajors + allyCountries[i]->numberOfSergeants + allyCountries[i]->numberOfPrivates << endl <<
            "Majors available: " << allyCountries[i]->numberOfMajors << endl <<
            "Sergent available: " << allyCountries[i]->numberOfSergeants << endl <<
            "Private available: " <<  allyCountries[i]->numberOfPrivates << endl <<
            endl <<
            "Vehicles available: " << allyCountries[i]->numberOfPlanes + allyCountries[i]->numberOfShips + allyCountries[i]->numberOfTanks << endl <<
            "Tanks: " << (allyCountries[i]->numberOfTanks) << endl <<
            "Ships: " << allyCountries[i]->numberOfShips << endl << 
            "Planes: "  << allyCountries[i]->numberOfPlanes << endl << endl <<
            "\033[0m" << endl;   
    }
}
