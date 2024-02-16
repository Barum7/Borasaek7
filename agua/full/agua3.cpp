#include <iostream>
#include <string.h>
#include <sstream>
#include <limits.h>
using namespace std;

class Cisterna {
    private:
        float max_cis = 2.0, min_cis = 0.0003, mid_cis = 1.30; //metros cubicos
    public:
        Cisterna() {}
        Cisterna(float max_cis, float min_cis){
            this->max_cis = max_cis;
            this->min_cis = min_cis;
        }

        float cisternaVacia(float cis){
            if(cis <= 0.0003){
            	cout<<"Su cisterna esta vacia"<<endl;
                return 0;
            }
            else if(cis > 0.0003 && cis < 1.30){
            		cout<<"Su cisterna esta en la media"<<endl;
                return 1;
            }
            else if(cis >= 1.30 && cis <= 2.0){
            		cout<<"Su cisterna esta llena"<<endl;
                return 2;
            }
            else {
                return -1; // Valor invalido
            }
        }
};

class Tanque {
    private:
        float max_tan = 1.80, min_tan = 0.3, mid_tan = 1.20; //metros cubicos
    public:
        Tanque() {}
        Tanque(float max_tan, float min_tan){
            this->max_tan = max_tan;
            this->min_tan = min_tan;
        }

        float tanqueVacio(float tan){
            if(tan <= 0.3){
            cout<<"Su tanque esta vacio"<<endl;
                return 0;
            }
            else if(tan > 0.3 && tan < 1.30){
            	cout<<"Su tanque esta en la media"<<endl;
                return 1;
            }
            else if(tan >= 1.30 && tan <= 1.80){
            	cout<<"Su tanque esta lleno"<<endl;
                return 2;
            }
            else {
                return -1; // Valor invalido
            }
        }
};

class Bomba {
    private:
        bool encender = true, apagar = false;
    public:
        Bomba(){}
        Bomba(bool encender, bool apagar){
            this->encender = encender;
            this->apagar = apagar;
        }

        bool on_of(float cisterna, float tanque){
            Cisterna cist;
            Tanque tanq;

            float estadoCisterna = cist.cisternaVacia(cisterna);
            float estadoTanque = tanq.tanqueVacio(tanque);


            if((estadoTanque == 0 || estadoTanque == 1) && (estadoCisterna == 1 || estadoCisterna == 2)){
                return encender;
            }
            else if(estadoTanque == 2){
                return apagar;
            }
            else if(estadoCisterna == 0){
                return apagar;
            }
            else if(estadoCisterna == 0 && encender){
                return apagar;
            }
            else if(estadoTanque == 2 && encender){
                return apagar;
            }
            else if(estadoTanque == 0 || estadoTanque == 1 && (estadoCisterna == 1 || estadoCisterna == 2) && apagar){
                return encender;
            }

            return 0; // Caso de error
        }
};






bool esFloat(const string& s) {
    istringstream iss(s);
    float f;
    iss >> noskipws >> f; // noskipws SE ASEGURA QUE NO SE SALTE NINGUN ESPACIO EN BLANCO
    return iss.eof() && !iss.fail(); // "Verifica si el analisis se realiza con exito y alcanzo el final de la cadena."
}

int main() {
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
