#include "EndOfWar.h"
#include "Context.h"
#include<iostream>
#include<string>
using namespace std;

EndOfWar :: EndOfWar(Engine* engine) {
    this->engine = engine;
}

void EndOfWar::handleAction(Context* c){
    cout << "In End of war" << endl;
    
    Country* currentCountry = this->engine->whichPlayerTurnCountry();
    vector<Country*> currentCountryVector = this->engine->whichPlayerTurnVector();

    Country* notCurrentCountry = this->engine->whichNotPlayerTurnCountry();
    vector<Country*> notCurrentCountryVector = this->engine->whichNotPlayerTurnVector();

    for(int i=0; i<currentCountryVector.size(); i++){
        if(currentCountryVector[i]->isMainCountry){
            if(currentCountryVector[i]->hasLost){
                cout << notCurrentCountryVector[i]->whichPlayer << " (" << notCurrentCountryVector[i]->getCountryName() << ") has won the war!" ;
                cout << currentCountryVector[i]->whichPlayer << " (" << currentCountryVector[i]->getCountryName() << ") has lost the war!";
                return;
            }
        }
    }

    for(int i=0; i<notCurrentCountryVector.size(); i++){
        if(notCurrentCountryVector[i]->isMainCountry){
            if(notCurrentCountryVector[i]->hasLost){
                cout << currentCountryVector[i]->whichPlayer << " (" << currentCountryVector[i]->getCountryName() << ") has won the war!" ;
                cout << notCurrentCountryVector[i]->whichPlayer << " (" << notCurrentCountryVector[i]->getCountryName() << ") has lost the war!";
                return;
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
                cout << notCurrentCountryVector[i]->whichPlayer << " (" << notCurrentCountryVector[i]->getCountryName() << ") has won the war!" ;
                cout << currentCountryVector[i]->whichPlayer << " (" << currentCountryVector[i]->getCountryName() << ") has lost the war!";
                return;
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
                cout << currentCountryVector[i]->whichPlayer << " (" << currentCountryVector[i]->getCountryName() << ") has won the war!" ;
                cout << notCurrentCountryVector[i]->whichPlayer << " (" << notCurrentCountryVector[i]->getCountryName() << ") has lost the war!";
                return;
            }
        }
    }


    //Jackie code:
    // cout<<"-----------------------------------------------"<<endl;
    // cout<<endl;
    // cout<<"You Win/Lose the war!"<<endl;
    // cout<<endl;
    // cout<<c->getState()<<endl;

    exit(0);

}

string EndOfWar::getState(){
    return "(End of the War)";
}