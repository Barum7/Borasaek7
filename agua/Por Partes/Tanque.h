#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;


class Tanque {
    private:
         float MAX_TANQUE = 1.80;//metros cubicos
		 float MIN_TANQUE = 0.3;//metros cubicos
    public:
        Tanque();
        
        int tanqueVacio(float tan);
};