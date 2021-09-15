#ifndef FECHAHORA_H
#define FECHAHORA_H
#include <iostream>
#include "Fecha.h"

using namespace std;

class FechaHora:public Fecha{
    private:
        int hora;
        int minuto;
    public:
        //Constructores
        FechaHora();
        FechaHora(int,int,int,int,int);
        ~FechaHora();
        //Getters y Setters
        int getHora();
        int getMinuto();
        void setHora(int);
        void setMinuto(int);
        friend ostream& operator<<(ostream&,const FechaHora&);
};
#endif
