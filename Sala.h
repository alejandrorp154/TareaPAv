#ifndef SALA_H
#define SALA_H
#include <iostream>
#include <map>

#include "Funcion.h"
#include "DtFuncionHorario.h"
#include "FechaHora.h"
#include "DtPelicula.h"
#include "DtReserva.h"

using namespace std;

class Sala{
    private:
        int idSala;
        static int idSalaEsta;
        int capacidad;
        map<int,Funcion*> ColeccionFunciones;
    public:
        //Constructores
        Sala();
        Sala(int);
        ~Sala();
        //Getters y Setters
        int getIdSala();
        int getCapacidad();
        void setIdSala(int);
        void setCapacidad(int);
        void agregarFuncion(Funcion*);
        map<int,Funcion*> obtenerFunciones();
        list<DtFuncionHorario*> obtenerDtFuncionHorario();
        void eliminarFunciones(string);

};
#endif
