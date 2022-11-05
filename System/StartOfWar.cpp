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

    /* builder integration */

    string countryNames[12] = {"United States of America", "Russia", "China", "United Kingdom", "Canada", "Japan", "Australia", "Egypt", "Iraq","South Africa", "Zimbabwe", "Nepal"};
    double countryMoney[12] = {25000000.00, 21000000.00, 14000000.00, 13500000.00, 11000000.00 , 18250000.00, 9000000.00, 5000000.00, 4500000.00, 3800000.00, 2000000.00, 1000000.00 };
    
    vector<string> countriesVector;
    vector<double> moneyVector;
    for (int i = 0; i < 12; i++) {
        countriesVector.push_back(countryNames[i]);
        moneyVector.push_back(countryMoney[i]);
    }

    cout << "\033[1;31m" <<"The countries you can select from are listed below: " << "\033[0m" << endl;
    
    for(int i = 0; i < 12; i++){
        cout<< i <<" ==> "<< countryNames[i] << endl;   
    }


/* ~~~~~~~~~~~~~~ */


    cout << "\033[1;31m" << "P1 enter the number that represents the Country you want to play with:" << "\033[0m" << endl;
    cin >> num;
    cout << "The country you have selected: " << countryNames[num] <<endl;

    //selected country goes to createCountry function
    buildCountry(countryNames[num], countryMoney[num]); /**/
    
    //remove selected country from country vector
    auto it = find(countriesVector.begin(), countriesVector.end(), countriesVector[num]);
    if(it != countriesVector.end()){
        countriesVector.erase(it);
    }

    //remove selected country's money from money vector
    auto it3 = find(moneyVector.begin(), moneyVector.end(), moneyVector[num]);
    if(it3 != moneyVector.end()){
        moneyVector.erase(it3);
    }


/* ~~~~~~~~~~~~~~ */


    int P2input;
    cout << endl;
    cout << "\033[1;31m" <<"The countries you can select from are listed below: " << "\033[0m" << endl;
    
    for(int k = 0; k < countriesVector.size(); k++){
        cout<< k <<" ==> "<< countriesVector[k] << endl;   
    }


/* ~~~~~~~~~~~~~~ */

    
    cout << "\033[1;31m" << "P2 enter the number that represents the Country you want to play with:" << "\033[0m" << endl;
    cin >> P2input;
    cout << "The country you have selected: " << countryNames[P2input] <<endl;

    buildCountry(countryNames[P2input], countryMoney[P2input]); /**/


/* ~~~~~~~~~~~~~~ */

    vector<Country*> allyCountries;
    for (int i = 0; i < 12; i++) {
        if ((i == num) || (i == P2input)) {
            //do nothing
        } else {
            //make rest of the countries & add it to an array
            cout << "Making ally country..." << endl;
            allyCountries.push_back(buildAllyCountry(countryNames[i], countryMoney[i]));
            cout << "Country made." << endl;
            //cout << allyCountries[i]->getCountryName() << endl;
        }
    }
//ally countries made and stored in allyCountries[i] ~ vector

/* ~~~~~~~~~~~~~~ */


    //User chooses alliances
    cout << endl;
    vector<Country*> AlliesArrayP1;
    vector<Country*> AlliesArrayP2;

    int AllyInput1; //p1
    int AllyInput2; //p2

    cout << "\033[1;31m" <<"Select your alliances from the listed countries below: " << "\033[0m" << endl;

    for (int i = 0; i < 4; i++) {
/* ~~~ P1 TURN ~~~ */
        //show available alliances...
        showAvailableAllies(allyCountries);

        cout << "\033[1;31m" << "P1 select your allies:" << "\033[0m" << endl;
        cin >> AllyInput1;

        Country* temp = allyCountries[AllyInput1];
        AlliesArrayP1.push_back(temp);

        //remove country from available allies array
        auto it5 = find(allyCountries.begin(), allyCountries.end(), temp);
        if(it5 != allyCountries.end()){
            allyCountries.erase(it5);
        }

/* ~~~ P2 TURN ~~~ */
        showAvailableAllies(allyCountries);
        cout << "\033[1;31m" << "P2 select your allies:" << "\033[0m" << endl;
        cin >> AllyInput2;

        temp = allyCountries[AllyInput2];
        AlliesArrayP2.push_back(temp);
        //remove country from countries array
        auto it6 = find(allyCountries.begin(), allyCountries.end(), temp);
        if(it6 != allyCountries.end()){
            allyCountries.erase(it6);
        }
    }

    c->setState(new Action());// implement

}

string StartOfWar::getState(){
    return "(Start of the War)";
}


/*BUILDER INTEGRATION */
void StartOfWar :: buildCountry(string countryName, double money) {
    CountryBuilder* countryBuilder = new CountryBuilder();
    Director* countryDirector = new Director(countryBuilder);
    
    countryDirector->countryBuilder->buildName(countryName);
    countryDirector->countryBuilder->buildMoney(money);
    //cout << "going into buildarmy function" << endl << endl << endl;
    countryDirector->countryBuilder->buildArmy(); //automated
    
    this->myCountry = countryDirector->countryBuilder->getCountry();
    this->myCountry->countNumberOfIndividualTroops(this->myCountry->army);

    this->myCountry->setMoney(50000000);
    this->myCountry->army.clear();

    cout << "Country created :)" << endl;
    cout << "Country name: " << this->myCountry->getCountryName() << endl;
    cout << fixed;
    cout << "Country money: R" << setprecision(2) << this->myCountry->getMoney() << endl << endl;

}

Country* StartOfWar :: getmyCountry() {
    return this->myCountry;
}


Country* StartOfWar :: getAllyCountry() {
    return this->allyCountry;
}

Country* StartOfWar :: buildAllyCountry(string countryName, double money) {
    CountryBuilder* allyCountryBuilder = new CountryBuilder();
    Director* allyCountryDirector = new Director(allyCountryBuilder);
    
    allyCountryDirector->countryBuilder->buildName(countryName);
    allyCountryDirector->countryBuilder->buildMoney(money);
    //cout << "going into buildarmy function" << endl << endl << endl;
    allyCountryDirector->countryBuilder->buildArmy(); //automated

    Country* temp = allyCountryBuilder->getCountry();
    //delete
    //delete allyCountryBuilder;
    //delete allyCountryDirector;

    cout << "Ally country made" << endl;

    return temp;
}

void StartOfWar :: showAvailableAllies(vector<Country*> allyCountries) {
    for (int i = 0; i < allyCountries.size(); i++) {
        // int numOfMajors = allyCountries[i]->numberOfPlanes;
        // cout << "numOfMajors variable : " << numOfMajors << endl;
        // cout << "testing " << allyCountries[i]->getCountryName() << " hellooooo " << numOfMajors << endl;

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
