#ifndef MANEJADORCINE_H
#define MANEJADORCINE_H

#include <iostream>
#include <map>
#include <list>

#include "Cine.h"
#include "Sala.h"
#include "DtSala.h"


using namespace std;

class ManejadorCine{
    private:
        map<int,Cine*> ColeccionCines;
        static ManejadorCine* instancia;
        ManejadorCine();
    public:
        virtual ~ManejadorCine();
        static ManejadorCine* getInstancia();
        void agregarCine(Cine*);
        Cine* obtenerCine(int);
        map<int,Cine*> getCines();
        void borrarCine(int);
};
#endif
