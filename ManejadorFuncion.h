#ifndef MANEJADORFUNCION_H
#define MANEJADORFUNCION_H

#include "Funcion.h"

#include <iostream>
#include <map>

using namespace std;

class ManejadorFuncion{
    private:
        map<int,Funcion*> ColeccionFunciones;
        static ManejadorFuncion* instancia;
        ManejadorFuncion();
    public:
        virtual ~ManejadorFuncion();
        static ManejadorFuncion* getInstancia();
        void agregarFuncion(Funcion*);
        Funcion* obtenerFuncion(int);
        map<int,Funcion*> listarFunciones();
};
#endif