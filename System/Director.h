#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <string>
#include "CountryBuilder.h"

using namespace std;

class Director {
private:
    //Builder* countryBuilder;

public:
    /**
     * @brief Construct a new Director object
     * 
    */
    Director(CountryBuilder* countryBuilder);

    /**
     * @brief Destroy the Director object
     * 
    */
    ~Director();
    //changeBuilder() -> not needed

    /**
     * @brief make director 
    */
    void make();
    CountryBuilder* countryBuilder;
};

#endif