#include "MediumRoute.h"

MediumRoute::MediumRoute(Transport *transport) : TransportDecorator(transport){}

std::string MediumRoute::getDescription() {
    this->setDescription("Medium route");
    return TransportDecorator::getDescription();
}

void MediumRoute::setDescription(std::string description) {
    TransportDecorator::setDescription(TransportDecorator::getDescription() + description + + "\n");
}

void MediumRoute::setMoneyGained(double money) {
    TransportDecorator::setMoneyGained(TransportDecorator::getMoneyGained() + money);
}

double MediumRoute::getMoneyGained() {
    this->setMoneyGained(500000);
    return TransportDecorator::getMoneyGained();
}

void MediumRoute::setTurnsToSkip(int turns){
    TransportDecorator::setTurnsToSkip(TransportDecorator::getTurnsToSkip() + turns);
}

int MediumRoute::getTurnsToSkip(){
    this->setTurnsToSkip(2);
    return TransportDecorator::getTurnsToSkip();
}