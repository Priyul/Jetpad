#include "Country.h"
#include "Engine.h"
using namespace std;

Engine::Engine() {

}

Engine::~Engine() {

}

void Engine::assignP1(Country* country) {
    p1 = country;
}

void Engine::assignP2(Country* country) {
    p2 = country;
}