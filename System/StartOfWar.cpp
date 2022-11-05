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


/* ~~~~~~~~~~~~~~ P1 initial country pick */ 

    Country* P1Country;
    vector<Country*> P1Vector;
    Country* P2Country;
    vector<Country*> P2Vector;

    cout << "\033[1;31m" << "P1 enter the number that represents the Country you want to play with:" << "\033[0m" << endl;
    cin >> num;
    countriesVector[num]->isMainCountry = true;
    cout << "The country you have selected: " << countriesVector[num]->getCountryName() <<endl;

    P1Country = countriesVector[num]; //p1 country stored in as an object
    P1Country->setArmy(0,0,0,0,0,0);
    P1Country->setMoney(50000000);
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
    cin >> P2input;
    countriesVector[P2input]->isMainCountry = true;
    cout << "The country you have selected: " << countriesVector[P2input]->getCountryName() <<endl;

    P2Country = countriesVector[P2input]; //p1 country stored in as an object
    P2Country->setArmy(0,0,0,0,0,0);
    P2Country->setMoney(50000000);
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

        cout << "\033[1;31m" << "P1 select your allies:" << "\033[0m" << endl;
        cin >> AllyInput1;

        P1Vector.push_back(countriesVector[AllyInput1]);
        P1Vector[0]->setMoney(P1Vector[0]->getMoney()-countriesVector[AllyInput1]->getCostOfCountry()); //cost of forming an alliance is reflected in main countries money

        auto it6 = find(countriesVector.begin(), countriesVector.end(), countriesVector[AllyInput1]);
        if(it6 != countriesVector.end()){
            countriesVector.erase(it6);
        }


/* ~~~ P2 TURN ~~~ */
        showAvailableAllies(countriesVector);
        cout << "\033[1;31m" << "P2 select your allies:" << "\033[0m" << endl;
        cin >> AllyInput2;

        P2Vector.push_back(countriesVector[AllyInput2]);
        P2Vector[0]->setMoney(P2Vector[0]->getMoney()-countriesVector[AllyInput2]->getCostOfCountry()); //cost of forming an alliance is reflected in main countries money

        //remove country from countries array
        auto it7 = find(countriesVector.begin(), countriesVector.end(), countriesVector[AllyInput2]);
        if(it7 != countriesVector.end()){
            countriesVector.erase(it7);
        }
    }

    Engine* engine = new Engine(P1Vector, P2Vector);

/* select which country to pick from list of allies */
    int input;
    //Country* P1Selected;
    cout << "\033[1;31m" << "P1 select which country to attack with:" << "\033[0m" << endl;
    for (int i = 0; i < P1Vector.size(); i++) {
        cout << i << " ==> " << P1Vector[i]->getCountryName() << endl;
    }
    cin >> input;
    //P1Selected = P1Vector[input];
    P1Vector[input]->setMoney(50000000);

    engine->P1SelectedCountry = P1Vector[input];

    // Country* P2SelectedCountry;
    // cout << "\033[1;31m" << "P1 select which country to attack with:" << "\033[0m" << endl;
    // for (int i = 0; i < P2Vector.size(); i++) {
    //     cout << i << " ==> " << P2Vector[i]->getCountryName() << endl;
    // }
    // cin >> input;
    // P2SelectedCountry = P2Vector[input];


    c->setState(new Action(engine));// implement

}

string StartOfWar::getState(){
    return "(Start of the War)";
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
    //cout << "going into buildarmy function" << endl << endl << endl;
    countryDirector->countryBuilder->buildArmy(); //automated
    

    Country* temp = countryBuilder->getCountry();

    return temp;
}

void StartOfWar :: showAvailableAllies(vector<Country*> allyCountries) {
    for (int i = 0; i < allyCountries.size(); i++) {

        allyCountries[i]->countNumberOfIndividualTroops(allyCountries[i]->army);

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
