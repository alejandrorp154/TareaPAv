#ifndef FINANCIERA_H
#define FINANCIERA_H

#include <string>

using namespace std;

class Financiera{
    private:
        string nombre;
        float descuento;
    public:
        Financiera();
        Financiera(string, float);
        ~Financiera();
        string getNombre();
        float getDescuento();
};

#endif
