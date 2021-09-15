#ifndef DTDEBITO_H
#define DTDEBITO_H
#include <iostream>
#include "DtReserva.h"

using namespace std;

class DtDebito:public DtReserva{
    private:
        string banco;
    public:
        DtDebito();
        DtDebito(int, float, string);
        ~DtDebito();
        string getBanco();
};
#endif