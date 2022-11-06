#include "Route.h"

std::string Route::getDescription() {
    return this->routeDescription;
}

void Route::setDescription(std::string description) {
    this->routeDescription = description;
}

double Route::getMoneyGained() {
    return moneyGained;
}

void Route::setMoneyGained(double money) {
    this->moneyGained = money;
}

void Route::setTurnsToSkip(int turns){
    this->turnsToSkip = turns;
}

int Route::getTurnsToSkip(){
    return turnsToSkip;
}