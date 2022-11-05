#include "Country.h"
#include "Bank.h"
#include <iostream>
using namespace std;

Bank::Bank() {

}

Bank::~Bank() {

}

double Bank::get() {
    return this->Country::getMoney();
}

void Bank::set(double num) {
    this->Country::setMoney(this->Country::getMoney() + num);
}