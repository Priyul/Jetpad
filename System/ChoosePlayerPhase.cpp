#include "ChoosePlayerPhase.h"

ChoosePlayerPhase :: ChoosePlayerPhase(Engine* engine) {
    this->engine = engine;
}


void ChoosePlayerPhase::handleAction(Context* c){
    /* select which country to pick from list of allies */
    int input;

    Country* currentCountry = this->engine->whichPlayerTurnCountry();
    vector<Country*> currentCountryVector = this->engine->whichPlayerTurnVector();
    
    int count = 0;
    for (int i = 0; i < currentCountryVector.size() ; i++) {
        if (currentCountryVector[i]->hasLost == false) {
            count++;
        }
    }

    input = -1;
    while ((input < 0) || (input > count)) { 
        cout << "\033[1;31m" << this->engine->printCurrentPlayer() << " select which country to perform an action with:" << "\033[0m" << endl;
        for (int i = 0; i < currentCountryVector.size(); i++) {
            if (currentCountryVector[i]->hasLost == false) {
                if(currentCountryVector[i]->isMainCountry == true){
                    cout << i << " ==> " << currentCountryVector[i]->getCountryName() << " (Main country) " << endl;
                }else{
                    cout << i << " ==> " << currentCountryVector[i]->getCountryName() << endl;
                }
            }
        }

        cout << "Select option: > ";
        cin >> input;
    }

    if (engine->isP1Turn) {
        engine->P1SelectedCountry = currentCountryVector[input];
    } else {
        engine->P2SelectedCountry = currentCountryVector[input];
    }

    c->setState(new Action(this->engine));

}

string ChoosePlayerPhase :: getState() {
    return "(Choose Player phase.)";
}