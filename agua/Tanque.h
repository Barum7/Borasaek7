#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;


class Tanque {
    private:
        float max_tan = 1.80, min_tan = 0.3, mid_tan = 1.20; //metros cubicos
    public:
        Tanque();
        Tanque(float max_tan, float min_tan);
        float tanqueVacio(float tan);
};