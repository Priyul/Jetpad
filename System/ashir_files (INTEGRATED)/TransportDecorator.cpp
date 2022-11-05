#include "TransportDecorator.h"

TransportDecorator::TransportDecorator(Transport* transport) {
    this->transport = transport;
}

std::string TransportDecorator::getDescription() {
    return this->transport->getDescription();
}

void TransportDecorator::setDescription(std::string description) {
    return this->transport->setDescription(description);
}

double TransportDecorator::getMoneyGained() {
    return this->transport->getMoneyGained();
}

void TransportDecorator::setMoneyGained(double money) {
    this->transport->setMoneyGained(money);
}

void TransportDecorator::setTurnsToSkip(int turns){
    this->transport->setTurnsToSkip(turns);
}

int TransportDecorator::getTurnsToSkip(){
    return this->transport->getTurnsToSkip();
}