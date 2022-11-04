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

    string countryNames[12] = {"United State of America", "Russia", "China", "United Kingdom", "Canada", "Japan", "Australia", "Egypt", "Iraq","South Africa", "Zimbabwe", "Nepal"};
    double countryMoney[12] = {25000000.00, 21000000.00, 14000000.00, 13500000.00, 11000000.00 , 18250000.00, 9000000.00, 5000000.00, 4500000.00, 3800000.00, 2000000.00, 1000000.00 };
    
    vector<string> countriesArray;
    for (int i = 0; i < 12; i++) {
        countriesArray.push_back(countryNames[i]);
        
    }

    vector<double> moneyArray;
    for (int i = 0; i < 12; i++) {
        moneyArray.push_back(countryMoney[i]);
    }

    // //print money vector
    // cout << "Money vector: " << endl;
    // for (int i = 0; i < moneyArray.size(); i++) {
    //     cout << moneyArray[i] << endl;
    // }

    cout << "\033[1;31m" <<"The countries you can select from are listed below: " << "\033[0m" << endl;
    
    for(int i = 0; i < 12; i++){
        cout<< i <<" ==> "<< countryNames[i] << endl;   
    }
    cout << "\033[1;31m" << "Enter the number that represents the Country you want to play with:" << "\033[0m" << endl;
    cin >> num;
    cout << "The country you have selected: " << countryNames[num] <<endl;

    //selected country goes to createCountry function
    buildCountry(countryNames[num], countryMoney[num]); /**/
    
    //remove selected country from country vector
    auto it = find(countriesArray.begin(), countriesArray.end(), countriesArray[num]);
    if(it != countriesArray.end()){
        countriesArray.erase(it);
    }

    //remove selected country's money from money vector
    auto it3 = find(moneyArray.begin(), moneyArray.end(), moneyArray[num]);
    if(it3 != moneyArray.end()){
        moneyArray.erase(it3);
    }

    string var1 = "";
    cout << "Array after user picks country: " << endl;
    for(auto it = countriesArray.begin(); it != countriesArray.end(); ++it){
        if(it == countriesArray.end()-1){
            var1 += *it;
        }else{
            var1 += *it + ", ";
        }
    }

    cout << "[" << var1 << "]"<<endl;

    int randNumber;
    //AI Selects random country from countriesArray
    // Initialize random number generator.
    randNumber = (rand() % countriesArray.size()) + 0;

    cout << endl;
    cout << endl << "\033[1;31m" << "Player 2 has selcted: " << countryNames[randNumber] << "\033[0m" << endl;

    auto it2 = find(countriesArray.begin(), countriesArray.end(), countriesArray[randNumber]);
    if(it2 != countriesArray.end()){
        countriesArray.erase(it2);
    }

    auto it4 = find(moneyArray.begin(), moneyArray.end(), moneyArray[randNumber]);
    if(it4 != moneyArray.end()){
        moneyArray.erase(it4);
    }



    // cout << "Array after AI selects a country: " << endl;
    // for(auto it2 = countriesArray.begin(); it2 != countriesArray.end(); ++it2){
    //     cout << "[" << *it2 << "]";
    // }
    
    buildCountry(countryNames[randNumber], countryMoney[randNumber]); /**/

    string var2 = "";
    cout << "Array after user picks country: " << endl;
    for(auto it = countriesArray.begin(); it != countriesArray.end(); ++it){
        if(it == countriesArray.end()-1){
            var2 += *it;
        }else{
            var2 += *it + ", ";
        }
    }

    cout << "[" << var2 << "]"<<endl;


    //User chooses alliances
    cout << endl;
    vector<string> AlliesArray;

    int AllyInput;

    cout << "\033[1;31m" <<"Select your alliances from the listed countries below: " << "\033[0m" << endl;
    
    for (int i = 0; i < countriesArray.size(); i++){
        cout << i << " ==> " << countriesArray[i] << endl << "R " << moneyArray[i] << endl <<
            " Soilders available: "<< "Major available: " << "Sergent available: " << "Private available: " << endl <<
            "Vehicles available: " << "Tanks: " << "Ships: " << "Planes"  << endl;
        
    }

    cout << "\033[1;31m" << "Select your ally:" << "\033[0m" << endl;
    cin >> AllyInput;
    AlliesArray.push_back(countriesArray[AllyInput]);


    //c->setState(new Action());

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
    countryDirector->countryBuilder->buildArmy();

    this->myCountry = countryDirector->countryBuilder->getCountry();

    cout << "Country created: " << endl;
    cout << "Country name: " << this->myCountry->getCountryName() << endl;
    cout << fixed;
    cout << "Country money: R" << setprecision(2) << this->myCountry->getMoney() << endl << endl;

    //after this, make countries for AI
    // string iname = "";
    // double imoney = 0;

    // for (int i = 0; i < 11; i++) {
    //     CountryBuilder* countryBuilder = new CountryBuilder();
    //     Director* countryDirector = new Director(countryBuilder);
    //     iname = "AI country";
    //     imoney = 0;

    //     countryDirector->countryBuilder->buildName(countryName);
    //     countryDirector->countryBuilder->buildMoney(money);

    //     Country* AIcountry = countryDirector->countryBuilder->getCountry();
    //     // cout << "AI Country" << endl;
    //     // cout << endl << AIcountry->getCountryName() << endl << AIcountry->getMoney() << endl;
    // }

    //return ourCountry;
}

Country* StartOfWar :: getmyCountry() {
    return this->myCountry;
}


Country* StartOfWar :: getAllyCountry() {
    return this->allyCountry;
}