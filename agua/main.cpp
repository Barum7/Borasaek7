#include <iostream>
#include "Cisterna.h"
#include "Tanque.h"
#include "Bomba.h"
#include <string>
#include <sstream>
#include <limits>
using namespace std;

bool esFloat(const string& s) {
    istringstream iss(s);
    float f;
    iss >> noskipws >> f; // noskipws SE ASEGURA QUE NO SE SALTE NINGUN ESPACIO EN BLANCO
    return iss.eof() && !iss.fail(); // "Verifica si el analisis se realizo con exito y alcanzo el final de la cadena."
}

int main(int argc, char** argv) {
	
	float valorCisterna, valorTanque;
    string input;

    while (true) {
        cout << "Usted Posee una cisterna de 2 metros cubicos y un tanque de 1.80 metros de altura" << endl;
        cout << "Ingrese los valores que se le piden a continuacion :)" << endl;
        cout << "Tenga en consideracion las caracteristicas de su cisterna" << endl;

        cout << "Ingrese el nivel del agua de la cisterna en metros cubicos: ";
        getline(cin, input);
        if (!esFloat(input) || (valorCisterna = stof(input)) < 0 || valorCisterna > 2) {
            cout << "Error: Entrada no valida o valor fuera de rango. Vuelva a intentarlo." << endl;
            system("pause");
                system("cls");
            continue;
        }

        cout << "Ingrese el nivel del agua del tanque en metros cubicos: ";
        getline(cin, input);
        if (!esFloat(input) || (valorTanque = stof(input)) < 0 || valorTanque > 1.80) {
            cout << "Error: Entrada no valida o valor fuera de rango. Vuelva a intentarlo." << endl;
            system("pause");
                system("cls");
            continue;
        }

        break; // Salir del bucle si las entradas son validas
    }

  
    Bomba bomba;
    bool estadoBomba = bomba.on_of(valorCisterna, valorTanque);

    if (!estadoBomba) {
        cout << "Estado de la bomba: Apagada" << endl;
    } else {
        cout << "Estado de la bomba: Encendida" << endl;
    }

	
	
	
	
	return 0;
}