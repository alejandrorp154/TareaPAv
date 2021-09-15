#ifndef DEBITO_H
#define DEBITO_H
#include <iostream>

#include "Reserva.h"

class Debito:public Reserva{
    private:
        string banco;
    public:
        //Constructores
        Debito();
        Debito(int,float,string);
        ~Debito();
        //Getters y Setters
        string getBanco();
        void setBanco(string);
};
#endif
