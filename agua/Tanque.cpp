#include "Tanque.h"
#include <iostream>

#include <string>
#include <sstream>
#include <limits>
using namespace std;




Tanque::Tanque() {}

Tanque::Tanque(float max_tan, float min_tan) {
    this->max_tan = max_tan;
    this->min_tan = min_tan;
}

float Tanque::tanqueVacio(float tan) {
    if (tan <= 0.3) {
        std::cout << "Su tanque esta vacio" << std::endl;
        return 0;
    } else if (tan > 0.3 && tan < 1.30) {
        std::cout << "Su tanque esta en la media" << std::endl;
        return 1;
    } else if (tan >= 1.30 && tan <= 1.80) {
        std::cout << "Su tanque esta lleno" << std::endl;
        return 2;
    } else {
        return -1; // Valor inválido
    }
}