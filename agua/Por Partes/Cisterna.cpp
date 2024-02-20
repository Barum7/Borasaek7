#include "Cisterna.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

Cisterna::Cisterna() {}



int Cisterna::cisternaVacia(float cis) {
    if(cis <= 0.0003){
            	cout<<"Su cisterna esta vacia"<<endl;
                return 0;
            }
            
            else {
            		cout<<"Su cisterna tiene agua"<<endl;
                return 1; 
            }
}