#include "TransportSpy.h"
#include "Bank.h"
#include "Transport.h"
using namespace std;

TransportSpy::TransportSpy() {

}

TransportSpy::TransportSpy(Bank* bank) {
    BankList = bank;
}

TransportSpy::~TransportSpy() {

}

void TransportSpy::notify(double num) {
    this->set(num);
}

Bank* TransportSpy::getBankList() {
    return BankList;
}

void TransportSpy::setBankList(Bank* bank) {
    BankList = bank
}