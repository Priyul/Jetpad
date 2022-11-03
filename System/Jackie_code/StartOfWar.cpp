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

    cout << "\033[1;31m" <<"The countries you can select from are listed below: " << "\033[0m" << endl;
    
    for(int i = 0; i < 12; i++){
        cout<< i <<" ==> "<< countryNames[i] << endl;   
    }
    cout << "\033[1;31m" << "Enter the number that represents the Country you want to play with:" << "\033[0m" << endl;
    cin >> num;
    cout << "The country you have selected: " << countryNames[num] <<endl;

    //selected country goes to createCountry function
    buildCountry(countryNames[num], countryMoney[num]);
    
    //remove selected country from vector
    auto it = find(countriesArray.begin(), countriesArray.end(), countriesArray[num]);
    if(it != countriesArray.end()){
        countriesArray.erase(it);
    }

    for(auto it = countriesArray.begin(); it != countriesArray.end(); ++it){
        cout << " " << *it;
    }

    int randNumber;
    //AI Selects random country from countriesArray
    // Initialize random number generator.
    randNumber = (rand() % countriesArray.size()) + 0;




    c->setState(new Action());

}

string StartOfWar::getState(){
    return "(Start of the War)";
}


/*BUILDER INTEGRATION */
Country* StartOfWar :: buildCountry(string countryName, double money) {
    CountryBuilder* countryBuilder = new CountryBuilder();
    Director* countryDirector = new Director(countryBuilder);
    
    countryDirector->countryBuilder->buildName(countryName);
    countryDirector->countryBuilder->buildMoney(money);

    Country* ourCountry = countryDirector->countryBuilder->getCountry();

    cout << "Country created: " << endl;
    cout << "Country name: " << ourCountry->getCountryName() << endl;
    cout << fixed;
    cout << "Country money: R" << setprecision(2) << ourCountry->getMoney() << endl << endl;

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

    return ourCountry;
}