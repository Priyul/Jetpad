#include "CountrySpy.h"
#include "Bank.h"
using namespace std;

CountrySpy::CountrySpy() {

}

CountrySpy::CountrySpy(Bank* bank) {
    BankList = bank;
}

CountrySpy::~CountrySpy() {

}

void CountrySpy::notify() {
    // code here
}

Bank* CountrySpy::getBankList() {
    return BankList;
}

void CountrySpy::setBankList(Bank* bank) {
    BankList = bank
}