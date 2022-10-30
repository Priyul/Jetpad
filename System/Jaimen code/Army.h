#ifndef ARMY_H
#define ARMY_H

#include <iostream>

using namespace std;

class Army {
public:
    Army();
    Army(string type, double probability);
    ~Army();

    double getProbability();
    string getType();

protected:
    string type;
    double probability;

private:
    
};

#endif