#ifndef DEFENDING_H
#define DEFENDING_H

#include "WarStrategy.h"

class Defending: public WarStrategy
{
    public:
    // Getters
        string getBattleState();
    // Virtual Functions
        // Types of Attacks
        virtual void LandDefense();
        virtual void AirDefense();
        virtual void SeaDefense();
};

class LandDefense: public Defending
{
    public:
        void landDefense();
        LandDefense handle();
        ~landDefense();
};

class AirDefense: public Defending
{
    public:
        void airDefense();
        AirDefense handle();
        ~AirDefense();
};

class SeaDefense: public Defending
{
    public:
        void seaDefense();
        SeaDefense handle();
        ~SeaDefense();
};
#endif