#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        //Constructores
        Fecha();
        Fecha(int,int,int);
        virtual ~Fecha();
        //Getters y Setters
        int getDia();
        int getMes();
        int getAnio();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        friend ostream& operator<<(ostream&,const Fecha&);
};
#endif
