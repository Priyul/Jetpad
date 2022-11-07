#include "EndOfWar.h"
#include "Context.h"
#include<iostream>
#include<string>
using namespace std;

EndOfWar :: EndOfWar(Engine* engine) {
    this->engine = engine;
}

void EndOfWar::handleAction(Context* c){
    
    Country* currentCountry = this->engine->whichPlayerTurnCountry();
    vector<Country*> currentCountryVector = this->engine->whichPlayerTurnVector();

    Country* notCurrentCountry = this->engine->whichNotPlayerTurnCountry();
    vector<Country*> notCurrentCountryVector = this->engine->whichNotPlayerTurnVector();

    for(int i=0; i<currentCountryVector.size(); i++){
        if(currentCountryVector[i]->isMainCountry){
            if(currentCountryVector[i]->hasLost){
                cout << "\033[1;32m" <<  notCurrentCountryVector[i]->whichPlayer << " (" << notCurrentCountryVector[i]->getCountryName() << ") has won the war!" << "\033[0m" << endl;
                cout << "\033[1;31m" << currentCountryVector[i]->whichPlayer << " (" << currentCountryVector[i]->getCountryName() << ") has lost the war!" << "\033[0m" << endl;
                abort();
            }
        }
    }

    for(int i=0; i<notCurrentCountryVector.size(); i++){
        if(notCurrentCountryVector[i]->isMainCountry){
            if(notCurrentCountryVector[i]->hasLost){
                cout << "\033[1;32m" <<  currentCountryVector[i]->whichPlayer << " (" << currentCountryVector[i]->getCountryName() << ") has won the war!" << "\033[0m" << endl;
                cout << "\033[1;31m" << notCurrentCountryVector[i]->whichPlayer << " (" << notCurrentCountryVector[i]->getCountryName() << ") has lost the war!" << "\033[0m" << endl;
                abort();
            }
        }
    }

    int p1Count = 0;
    for(int i=0; i<currentCountryVector.size(); i++){
        if(currentCountryVector[i]->hasLost){
            p1Count++;
        }
    }

    if(p1Count == 6){
        for(int i=0; i<currentCountryVector.size(); i++){
            if(currentCountryVector[i]->isMainCountry){
                cout << "\033[1;32m" << notCurrentCountryVector[i]->whichPlayer << " (" << notCurrentCountryVector[i]->getCountryName() << ") has won the war!" << "\033[0m" << endl ;
                cout << "\033[1;31m" << currentCountryVector[i]->whichPlayer << " (" << currentCountryVector[i]->getCountryName() << ") has lost the war!" << "\033[0m" << endl;
                abort();
            }
        }
    }

    int p2Count = 0;
    for(int i=0; i<notCurrentCountryVector.size(); i++){
        if(notCurrentCountryVector[i]->hasLost){
            p2Count++;
        }
    }

    if(p2Count == 6){
        for(int i=0; i<notCurrentCountryVector.size(); i++){
            if(notCurrentCountryVector[i]->isMainCountry){
                cout << "\033[1;32m" <<  currentCountryVector[i]->whichPlayer << " (" << currentCountryVector[i]->getCountryName() << ") has won the war!" << "\033[0m" << endl;
                cout << "\033[1;31m" << notCurrentCountryVector[i]->whichPlayer << " (" << notCurrentCountryVector[i]->getCountryName() << ") has lost the war!" << "\033[0m" << endl;
                abort();
            }
        }
    }


    //Jackie code:
    // cout<<"-----------------------------------------------"<<endl;
    // cout<<endl;
    // cout<<"You Win/Lose the war!"<<endl;
    // cout<<endl;
    // cout<<c->getState()<<endl;

}

string EndOfWar::getState(){
    return "(End of the War)";
}