#ifndef FUNCION_H
#define FUNCION_H
#include <iostream>
#include <list>
#include <map>

#include "FechaHora.h"
#include "Reserva.h"
#include "DtDebito.h"
#include "DtCredito.h"
#include "DtReserva.h"
#include "Debito.h"
#include "Credito.h"

using namespace std;

class Pelicula;

class Funcion{
    private:
        int idFuncion;
        static int idFuncionEsta;
        FechaHora horario;
        Pelicula* p;
        list<Reserva*> reservas;
    public:
        //Constructores
        Funcion();
        Funcion(FechaHora, Pelicula*);
        ~Funcion();
        //Getters y Setters
        int getIdFuncion();
        FechaHora getHorario();
        void setIdFuncion(int);
        void setHorario(FechaHora);
        string getTituloPelicula();
        void setPelicula(Pelicula*);
        void eliminarReservas();
        void crearReserva(Reserva*);
        //eliminarReserva();
};

#include "Pelicula.h"

#endif
