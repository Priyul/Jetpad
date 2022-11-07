#include "LongRoute.h"

LongRoute::LongRoute(Transport *transport) : TransportDecorator(transport){}

std::string LongRoute::getDescription() {
    this->setDescription("Long route");
    return TransportDecorator::getDescription();
}

void LongRoute::setDescription(std::string description) {
    TransportDecorator::setDescription(TransportDecorator::getDescription() + description + + "\n");
}

void LongRoute::setMoneyGained(double money) {
    TransportDecorator::setMoneyGained(TransportDecorator::getMoneyGained() + money);
}

double LongRoute::getMoneyGained() {
    this->setMoneyGained(1500000);
    return TransportDecorator::getMoneyGained();
}

void LongRoute::setTurnsToSkip(int turns){
    TransportDecorator::setTurnsToSkip(TransportDecorator::getTurnsToSkip() + turns);
}

int LongRoute::getTurnsToSkip(){
    this->setTurnsToSkip(3);
    this->turnsToSkip = 3;
    return TransportDecorator::getTurnsToSkip();
}