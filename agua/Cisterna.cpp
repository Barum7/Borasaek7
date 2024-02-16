#include "Cisterna.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

Cisterna::Cisterna() {}

Cisterna::Cisterna(float max_cis, float min_cis) {
    this->max_cis = max_cis;
    this->min_cis = min_cis;
}

float Cisterna::cisternaVacia(float cis) {
    if (cis <= 0.0003) {
        std::cout << "Su cisterna esta vacia" << std::endl;
        return 0;
    } else if (cis > 0.0003 && cis < 1.30) {
        std::cout << "Su cisterna esta en la media" << std::endl;
        return 1;
    } else if (cis >= 1.30 && cis <= 2.0) {
        std::cout << "Su cisterna esta llena" << std::endl;
        return 2;
    } else {
        return -1; // Valor inválido
    }
}