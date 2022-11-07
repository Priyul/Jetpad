#include "ShortRoute.h"

ShortRoute::ShortRoute(Transport *transport) : TransportDecorator(transport){}

std::string ShortRoute::getDescription() {
    this->setDescription("Short route");
    return TransportDecorator::getDescription();
}

void ShortRoute::setDescription(std::string description) {
    TransportDecorator::setDescription(TransportDecorator::getDescription() + description + + "\n");
}

void ShortRoute::setMoneyGained(double money) {
    TransportDecorator::setMoneyGained(TransportDecorator::getMoneyGained() + money);
}

double ShortRoute::getMoneyGained() {
    this->setMoneyGained(100000);
    return TransportDecorator::getMoneyGained();
}

void ShortRoute::setTurnsToSkip(int turns){
    TransportDecorator::setTurnsToSkip(TransportDecorator::getTurnsToSkip() + turns);
}

int ShortRoute::getTurnsToSkip(){
    this->setTurnsToSkip(1);
    this->turnsToSkip = 1;
    return TransportDecorator::getTurnsToSkip();
}