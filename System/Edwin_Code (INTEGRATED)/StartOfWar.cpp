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
    cout << "\033[1;31m" << "P1 enter the number that represents the Country you want to play with:" << "\033[0m" << endl;
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
    cout << "Array after P1 picks country: " << endl;
    for(auto it = countriesArray.begin(); it != countriesArray.end(); ++it){
        if(it == countriesArray.end()-1){
            var1 += *it;
        }else{
            var1 += *it + ", ";
        }
    }

    cout << "[" << var1 << "]"<<endl;

    int P2input;
    cout << endl;
    cout << "\033[1;31m" <<"The countries you can select from are listed below: " << "\033[0m" << endl;
    
    for(int k = 0; k < 11; k++){
        cout<< k <<" ==> "<< countriesArray[k] << endl;   
    }
    
    cout << "\033[1;31m" << "P2 enter the number that represents the Country you want to play with:" << "\033[0m" << endl;
    cin >> P2input;
    cout << "The country you have selected: " << countryNames[P2input] <<endl;

    buildCountry(countryNames[P2input], countryMoney[P2input]); /**/

    auto it2 = find(countriesArray.begin(), countriesArray.end(), countriesArray[P2input]);
    if(it2 != countriesArray.end()){
        countriesArray.erase(it2);
    }

    // auto it4 = find(moneyArray.begin(), moneyArray.end(), moneyArray[P2input]);
    // if(it4 != moneyArray.end()){
    //     moneyArray.erase(it4);
    // }



    cout << "Array after p2 selects a country: " << endl;
    for(auto it2 = countriesArray.begin(); it2 != countriesArray.end(); ++it2){
        cout << "[" << *it2 << "]";
    }
    
   

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
    vector<string> AlliesArrayP1;
    vector<string> AlliesArrayP2;

    int AllyInput1; //p1
    int AllyInput2; //p2

    cout << "\033[1;31m" <<"Select your alliances from the listed countries below: " << "\033[0m" << endl;
    
    for (int i = 0; i < countriesArray.size(); i++){
        cout << i << " ==> " << "\033[1;33m" <<countriesArray[i] << "\033[0m" <<endl << "\033[1;32m" << "R " << moneyArray[i] << endl <<
            "Soilders available: "<< "Major available: " << "Sergent available: " << "Private available: " << endl <<
            "Vehicles available: " << "Tanks: " << "Ships: " << "Planes"  << "\033[0m" << endl;
        
    }

    cout << "\033[1;31m" << "P1 select your allies:" << "\033[0m" << endl;
    cin >> AllyInput1;
    AlliesArrayP1.push_back(countriesArray[AllyInput1]);
    
    //remove country from countries array
    auto it5 = find(countriesArray.begin(), countriesArray.end(), countriesArray[AllyInput1]);
    if(it5 != countriesArray.end()){
        countriesArray.erase(it5);
    }

    cout << "\033[1;31m" << "P2 select your allies:" << "\033[0m" << endl;

    for (int i = 0; i < countriesArray.size(); i++){
        cout << i << " ==> " << "\033[1;33m" <<countriesArray[i] << "\033[0m" <<endl << "\033[1;32m" << "R " << moneyArray[i] << endl <<
            "Soilders available: "<< "Major available: " << "Sergent available: " << "Private available: " << endl <<
            "Vehicles available: " << "Tanks: " << "Ships: " << "Planes"  << "\033[0m" << endl;
        
    }
    cin >> AllyInput2;
    AlliesArrayP2.push_back(countriesArray[AllyInput2]);

    //remove country from country array
    auto it53 = find(countriesArray.begin(), countriesArray.end(), countriesArray[AllyInput2]);
    if(it53 != countriesArray.end()){
        countriesArray.erase(it53);
    }

    

    cout << "\033[1;31m" << "P1 select your allies:" << "\033[0m" << endl;
    for (int i = 0; i < countriesArray.size(); i++){
        cout << i << " ==> " << "\033[1;33m" <<countriesArray[i] << "\033[0m" <<endl << "\033[1;32m" << "R " << moneyArray[i] << endl <<
            "Soilders available: "<< "Major available: " << "Sergent available: " << "Private available: " << endl <<
            "Vehicles available: " << "Tanks: " << "Ships: " << "Planes"  << "\033[0m" << endl;
        
    }
    cin >> AllyInput1;
    AlliesArrayP1.push_back(countriesArray[AllyInput1]);

    auto it55 = find(countriesArray.begin(), countriesArray.end(), countriesArray[AllyInput1]);
    if(it55 != countriesArray.end()){
        countriesArray.erase(it55);
    }

    cout << "\033[1;31m" << "P2 select your allies:" << "\033[0m" << endl;
    for (int i = 0; i < countriesArray.size(); i++){
        cout << i << " ==> " << "\033[1;33m" <<countriesArray[i] << "\033[0m" <<endl << "\033[1;32m" << "R " << moneyArray[i] << endl <<
            "Soilders available: "<< "Major available: " << "Sergent available: " << "Private available: " << endl <<
            "Vehicles available: " << "Tanks: " << "Ships: " << "Planes"  << "\033[0m" << endl;
        
    }
    cin >> AllyInput2;
    AlliesArrayP2.push_back(countriesArray[AllyInput2]);
    auto it6 = find(countriesArray.begin(), countriesArray.end(), countriesArray[AllyInput2]);
    if(it6 != countriesArray.end()){
        countriesArray.erase(it6);
    }

    cout << "\033[1;31m" << "P1 select your allies:" << "\033[0m" << endl;
    for (int i = 0; i < countriesArray.size(); i++){
        cout << i << " ==> " << "\033[1;33m" <<countriesArray[i] << "\033[0m" <<endl << "\033[1;32m" << "R " << moneyArray[i] << endl <<
            "Soilders available: "<< "Major available: " << "Sergent available: " << "Private available: " << endl <<
            "Vehicles available: " << "Tanks: " << "Ships: " << "Planes"  << "\033[0m" << endl;
        
    }
    cin >> AllyInput1;
    AlliesArrayP1.push_back(countriesArray[AllyInput1]);
    auto it7 = find(countriesArray.begin(), countriesArray.end(), countriesArray[AllyInput1]);
    if(it7!= countriesArray.end()){
        countriesArray.erase(it7);
    }

    cout << "\033[1;31m" << "P2 select your allies:" << "\033[0m" << endl;
    for (int i = 0; i < countriesArray.size(); i++){
        cout << i << " ==> " << "\033[1;33m" <<countriesArray[i] << "\033[0m" <<endl << "\033[1;32m" << "R " << moneyArray[i] << endl <<
            "Soilders available: "<< "Major available: " << "Sergent available: " << "Private available: " << endl <<
            "Vehicles available: " << "Tanks: " << "Ships: " << "Planes"  << "\033[0m" << endl;
        
    }
    cin >> AllyInput2;
    AlliesArrayP2.push_back(countriesArray[AllyInput2]);
    auto it8 = find(countriesArray.begin(), countriesArray.end(), countriesArray[AllyInput2]);
    if(it8 != countriesArray.end()){
        countriesArray.erase(it8);
    }

    cout << "\033[1;31m" << "P1 select your allies:" << "\033[0m" << endl;
    for (int i = 0; i < countriesArray.size(); i++){
        cout << i << " ==> " << "\033[1;33m" <<countriesArray[i] << "\033[0m" <<endl << "\033[1;32m" << "R " << moneyArray[i] << endl <<
            "Soilders available: "<< "Major available: " << "Sergent available: " << "Private available: " << endl <<
            "Vehicles available: " << "Tanks: " << "Ships: " << "Planes"  << "\033[0m" << endl;
        
    }
    cin >> AllyInput1;
    AlliesArrayP1.push_back(countriesArray[AllyInput1]);
    auto it9 = find(countriesArray.begin(), countriesArray.end(), countriesArray[AllyInput1]);
    if(it9 != countriesArray.end()){
        countriesArray.erase(it9);
    }

    cout << "\033[1;31m" << "P2 select your allies:" << "\033[0m" << endl;
    for (int i = 0; i < countriesArray.size(); i++){
        cout << i << " ==> " << "\033[1;33m" <<countriesArray[i] << "\033[0m" <<endl << "\033[1;32m" << "R " << moneyArray[i] << endl <<
            "Soilders available: "<< "Major available: " << "Sergent available: " << "Private available: " << endl <<
            "Vehicles available: " << "Tanks: " << "Ships: " << "Planes"  << "\033[0m" << endl;
        
    }
    cin >> AllyInput2;
    AlliesArrayP2.push_back(countriesArray[AllyInput2]);
    auto it10 = find(countriesArray.begin(), countriesArray.end(), countriesArray[AllyInput2]);
    if(it10 != countriesArray.end()){
        countriesArray.erase(it10);
    }

    cout << "\033[1;31m" << "P1 select your allies:" << "\033[0m" << endl;
    for (int i = 0; i < countriesArray.size(); i++){
        cout << i << " ==> " << "\033[1;33m" <<countriesArray[i] << "\033[0m" <<endl << "\033[1;32m" << "R " << moneyArray[i] << endl <<
            "Soilders available: "<< "Major available: " << "Sergent available: " << "Private available: " << endl <<
            "Vehicles available: " << "Tanks: " << "Ships: " << "Planes"  << "\033[0m" << endl;
        
    }
    cin >> AllyInput1;
    AlliesArrayP1.push_back(countriesArray[AllyInput1]);
    auto it11 = find(countriesArray.begin(), countriesArray.end(), countriesArray[AllyInput1]);
    if(it11 != countriesArray.end()){
        countriesArray.erase(it11);
    }

    cout << "\033[1;31m" << "P2 select your allies:" << "\033[0m" << endl;
    for (int i = 0; i < countriesArray.size(); i++){
        cout << i << " ==> " << "\033[1;33m" <<countriesArray[i] << "\033[0m" <<endl << "\033[1;32m" << "R " << moneyArray[i] << endl <<
            "Soilders available: "<< "Major available: " << "Sergent available: " << "Private available: " << endl <<
            "Vehicles available: " << "Tanks: " << "Ships: " << "Planes"  << "\033[0m" << endl;
        
    }
    cin >> AllyInput2;
    AlliesArrayP2.push_back(countriesArray[AllyInput2]);
    auto it12 = find(countriesArray.begin(), countriesArray.end(), countriesArray[AllyInput2]);
    if(it12 != countriesArray.end()){
        countriesArray.erase(it12);
    }



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