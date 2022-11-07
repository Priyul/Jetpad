#ifndef COUNTRYSTORAGE_H
#define COUNTRYSTORAGE_H

#include "Memento.h"

class CountryStorage{
private:
    Memento* backup;

public:
    CountryStorage(Memento* b);
    void setBackup(Memento* b);
    Memento* getBackup();
};
#endif