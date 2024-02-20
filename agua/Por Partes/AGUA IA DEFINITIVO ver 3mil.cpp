
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

class Cisterna {
    private:
        float MAX_CISTERNA = 2.0; //metros cubicos
		float MIN_CISTERNA = 0.0003; //metros cubicos
	
    public:
        Cisterna() {}
      

        int cisternaVacia(float cis){
            if(cis <= 0.0003){
            	cout<<"Su cisterna esta vacia"<<endl;
                return 0;
            }
            
            else {
            		cout<<"Su cisterna tiene agua"<<endl;
                return 1; 
            }
        }
};

class Tanque {
    private:
        float MAX_TANQUE = 1.80;//metros cubicos
		 float MIN_TANQUE = 0.3;//metros cubicos
		 
    public:
        Tanque() {}
       

        int tanqueVacio(float tan){
            
             if( tan == 1.80){
            	cout<<"Su tanque esta lleno"<<endl;
                return 0;
            }
            else {
            		cout<<"Su tanque debe ser llenado"<<endl;
                return 1; 
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


            if(estadoTanque == 1  && estadoCisterna == 1) {
                return encender;
            }
            else if(estadoTanque == 0){
                return apagar;
            }
            else if(estadoCisterna == 0){
                return apagar;
            }
            else if(estadoCisterna == 0 && encender){
                return apagar;
            }
            else if(estadoTanque == 0 && encender){
                return apagar;
            }
            

            return 0; // Caso de error
        }
};






bool esFloat(const string& s) {
    istringstream iss(s);
    float f;
    iss >> noskipws >> f; // noskipws SE ASEGURA QUE NO SE SALTE NINGUN ESPACIO EN BLANCO
    return iss.eof() && !iss.fail(); // "Verifica si el análisis se realizó con éxito y alcanzó el final de la cadena."
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

        break; // Salir del bucle si las entradas son válidas
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
