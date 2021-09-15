#ifndef CREDITO_H
#define CREDITO_H
#include <iostream>

#include "Reserva.h"

using namespace std;

class Credito:public Reserva{
    private:
        string financiera;
    public:
        //Constructores
        Credito();
        Credito(string,int,float);
        ~Credito();
        //Getters y Setters
        string getFinanciera();
        void setFinanciera(string);
};
#endif
