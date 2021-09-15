#ifndef DTRESERVA_H
#define DTRESERVA_H
#include <iostream>

using namespace std;

class DtReserva{
    private:
        int cantEntradas;
        float costo;
    public:
        //Constructores
        DtReserva();
        DtReserva(int, float);
        ~DtReserva();
        //Getters
        int getCantEntradas();
        float getCosto();
};
#endif