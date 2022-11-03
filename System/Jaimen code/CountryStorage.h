#ifndef COUNTRYSTORAGE_H
#define COUNTRYSTORAGE_H

#include "Memento.h"

class CountryStorage{
    public:
        CountryStorage();
        void setMemento(Memento* memento);
        Memento* getMemento();
    private:
        Memento* memento;

};
#endif