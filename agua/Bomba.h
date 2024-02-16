#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;


class Bomba {
    private:
        bool encender = true, apagar = false;
    public:
        Bomba();
        Bomba(bool encender, bool apagar);
        bool on_of(float cisterna, float tanque);
};