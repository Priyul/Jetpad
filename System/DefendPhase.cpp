// #include "DefendPhase.h"
// #include "Context.h"
// #include "Action.h"
// #include "EndOfWar.h"
// #include <iostream>
// #include <string>
// using namespace std;

// DefendPhase :: DefendPhase(Engine* engine) {
//     this->engine;
// }

// void DefendPhase::handleAction(Context* c)
// {
//     int num;
//     cout<<"-----------------------------------------------"<<endl;
//     cout<<c->getState()<<endl;
//     cout<<"State: Defend Phase"<<endl;
//     cout<<endl;
//     cout<<"Doing some defend here"<<endl;
//     cout<<endl;
//     cout<<"For Testing"<<endl;
//     cout<<"1. Back to choose next action"<<endl;
//     cout<<"2. Lose the war"<<endl;
//     cout<<"Select your next action by enter the number: ";
//     cin>>num;
//     if(num == 1)
//     {
//         c->setState(new Action(this->engine));
//     }
//     else if(num == 2)
//     {
//         c->setState(new EndOfWar());
//     }
    
// }

// string DefendPhase::getState(){
//     return "(Defending)";
// }