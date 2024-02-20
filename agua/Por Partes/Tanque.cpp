#include "Tanque.h"
#include <iostream>

#include <string>
#include <sstream>
#include <limits>
using namespace std;




Tanque::Tanque() {}



int Tanque::tanqueVacio(float tan) {
     if( tan == 1.80){
            	cout<<"Su tanque esta lleno"<<endl;
                return 0;
            }
            else {
            		cout<<"Su tanque debe ser llenado"<<endl;
                return 1; 
            }
}