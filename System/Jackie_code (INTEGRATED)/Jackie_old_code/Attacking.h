#ifndef ATTACKING_H
#define ATTACKING_H

#include "WarStrategy.h"

class Attacking : public WarStrategy{
public:
    Attacking();
    void handle(vector<Army*> ourArmy, vector<Army*> AIArmy, string CPUDefenseStrategy);
};

#endif
//option 1) send remaining army to country class (reset country vector ie: country->setVector(this->vector))
//option 2) return a vector<army>; vector<Army*> remArmy = america->landAttack.handle(); 
            //

            //vector<Army*> remArmy = america->landAttack.handle(?); 
            //
            
            /* (in handle())
                sendSignal(0);
                //0 = AI won; 1 = you won
            */

           
            //country->setVector(remArmy)