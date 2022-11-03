#include "State.h"
#include "Context.h"
#include "StartOfWar.h"
//#include "Action.h"
#include <iostream>
#include <string>
using namespace std;
class State;

// int main(){
//     Context* context = new Context();
//     //cout<<"Start of the War:"<<endl;
//     /*context->change();
//     return 0;*/
// }

#include <vector>

#include "Country.h"
#include "Soldier.h"
#include "SoldierFactory.h"
#include "VehicleFactory.h"
#include "ArmyFactory.h"

using namespace std;

int main() {
    Context* context = new Context();
    cout<<"Start of the War:"<<endl;
    context->change();



    return 0;
}