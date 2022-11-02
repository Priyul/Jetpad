#include "TransportObserver.h"
#include "Transport.h"
using namespace std;

TransportObserver::TransportObserver() {
    
}

TransportObserver::TransportObserver(Transport* transport) {
    TransportToObs = Transport;
}

TransportObserver::~TransportObserver() {

}

Transport* TransportObserver::getTransport() {
    return TransportToObs;
}

void TransportObserver::setTransport(Transport* transport) {
    transportToObs = transport
}