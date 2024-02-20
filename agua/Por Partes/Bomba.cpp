#include "Bomba.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;




Bomba::Bomba() {}

Bomba::Bomba(bool encender, bool apagar) {
    this->encender = encender;
    this->apagar = apagar;
}

bool Bomba::on_of(float cisterna, float tanque) {
    Cisterna cist;
    Tanque tanq;

    float estadoCisterna = cist.cisternaVacia(cisterna);
    float estadoTanque = tanq.tanqueVacio(tanque);

    if ((estadoTanque == 0 || estadoTanque == 1) && (estadoCisterna == 1 || estadoCisterna == 2)) {
        return encender;
    } else if (estadoTanque == 2) {
        return apagar;
    } else if (estadoCisterna == 0) {
        return apagar;
    } else if (estadoCisterna == 0 && encender) {
        return apagar;
    } else if (estadoTanque == 2 && encender) {
        return apagar;
    } else if (estadoTanque == 0 || estadoTanque == 1 && (estadoCisterna == 1 || estadoCisterna == 2) && apagar) {
        return encender;
    }

    return 0; // Caso de error
}