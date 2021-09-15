#ifndef CONTROLADORCINE_H
#define CONTROLADORCINE_H

#include <iostream>
#include <list>
#include <map>
#include "FechaHora.h"
#include "Sesion.h"
#include "Cine.h"
#include "DtCine.h"
#include "DtSala.h"
#include "DtFuncion.h"
#include "Funcion.h"
#include "Pelicula.h"
#include "FechaHora.h"
#include "Sala.h"
#include "ManejadorPelicula.h"
#include "ManejadorFuncion.h"
#include "ManejadorCine.h"
#include "IControladorCine.h"

using namespace std;

class ControladorCine:public IControladorCine{
    private:
        string dirCine;
    public:
        ControladorCine();
        ~ControladorCine();
        // Operaciones
        void cargarCines();
        DtCine* altaCine();
        void ingresarDirecionCine(string);
        void agregarSala(DtSala*,int);
        list<DtSala*> getSalas(int);
        list<DtFuncion*> getFuncionesSala(int,int);

};
#endif
