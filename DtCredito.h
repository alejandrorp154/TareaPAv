#ifndef DTCREDITO_H
#define DTCREDITO_H
#include <iostream>
#include "DtReserva.h"

using namespace std;

class DtCredito:public DtReserva{
    private:
        string financiera;
        float porcentajeDescuento;
    public:
        DtCredito();
        DtCredito(int, float, string, float);
        ~DtCredito();
        string getFinanciera();
        float getPorcentajeDescuento();
};
#endif