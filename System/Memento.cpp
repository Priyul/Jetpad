#include "Memento.h"


Memento :: Memento(Originator* o) {
    this->originator = o;
}

void Memento :: setOriginator(Originator* o) {
    this->originator = o;
}

Originator*  Memento :: getOriginator() {
    return this->originator;
}