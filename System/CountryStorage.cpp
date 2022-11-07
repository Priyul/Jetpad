#include "CountryStorage.h" 
using namespace std;
    
CountryStorage :: CountryStorage(Memento* b) {
    this->backup = b;
}

void CountryStorage :: setBackup(Memento* b) {
    this->backup = b;
}

Memento* CountryStorage :: getBackup() {
    return this->backup;
}