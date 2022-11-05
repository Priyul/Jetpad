#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <string>
#include "CountryBuilder.h"

using namespace std;

class Director {
private:
    //Builder* countryBuilder;

public:
    Director(CountryBuilder* countryBuilder);
    ~Director();
    //changeBuilder() -> not needed
    void make();
    CountryBuilder* countryBuilder;
};

#endif