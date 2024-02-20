#include "Cisterna.h"
#include "Tanque.h"
#include <iostream>

using namespace std;



class Bomba {
    private:
        bool encender = true, apagar = false;
    public:
        Bomba();
        Bomba(bool encender, bool apagar);
        bool on_of(float cisterna, float tanque);
};