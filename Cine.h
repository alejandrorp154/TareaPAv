#ifndef CINE_H
#define CINE_H
#include <iostream>
#include <map>

#include "DtReserva.h"
#include "DtSala.h"
#include "DtFuncionHorario.h"

using namespace std;

class Sala;

class Cine{
    private:
        int idCine;
        static int idCinesG;
        string direccion;
        map<int,Sala*> ColeccionSalas;
    public:
        //Constructores
        Cine();
        Cine(string);
        ~Cine();
        //Getters y Setters
        int getIdCine();
        string getDireccion();
        void setIdCine(int);
        void setDireccion(string);
        // Operaciones
        void agregarSala(DtSala*);
        map<int,Sala*> obtenerSalas();
        map<int,DtSala*> obtenerDtSala();
        Sala* obtenerSala(int);
        void agregarSalaCine(Sala*);
        void eliminarFunciones(string);

};

#include "Sala.h"

#endif
