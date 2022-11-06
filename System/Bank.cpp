#include "Bank.h"

void Bank :: sendMoney(Country* country, double moneyToSend) {
    country->setMoney(country->getMoney() + moneyToSend);
    cout << "Bank has added money " << endl;
    cout << "moneyToSend : " << moneyToSend << endl; 
}