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
        Cisterna();
        int cisternaVacia(float cis);
};