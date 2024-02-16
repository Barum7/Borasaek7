#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

class Cisterna {
    private:
        float max_cis = 2.0, min_cis = 0.0003, mid_cis = 1.30; //metros cubicos
        
    public:
        Cisterna();
        Cisterna(float max_cis, float min_cis);
        float cisternaVacia(float cis);
};