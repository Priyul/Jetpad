#include "Country.h"
#include "Bank.h"
#include <iostream>
using namespace std;

Bank::Bank() {

}

Bank::~Bank() {

}

double Bank::get() {
    return Country->getMoney();
}

void Bank::set(double num) {
    Country->setMoney(Country.getMoney() + num);
}