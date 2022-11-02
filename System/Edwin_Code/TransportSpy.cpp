#include "TransportSpy.h"
#include "Bank.h"
using namespace std;

TransportSpy::TransportSpy() {

}

TransportSpy::TransportSpy(Bank* bank) {
    BankList = bank;
}

TransportSpy::~TransportSpy() {

}

void TransportSpy::notify() {
    // code here
}

Bank* TransportSpy::getBankList() {
    return BankList;
}

void TransportSpy::setBankList(Bank* bank) {
    BankList = bank
}