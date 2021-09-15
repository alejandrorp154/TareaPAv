#ifndef MANEJADORPELICULA_H
#define MANEJADORPELICULA_H

#include <iostream>
#include <map>
#include <list>

#include "Pelicula.h"
#include "DtPelicula.h"
#include "DtPeliculaPoster.h"

using namespace std;

class ManejadorPelicula{
    private:
        map<string,Pelicula*> ColeccionPeliculas;
        static ManejadorPelicula* instancia;
        ManejadorPelicula();
    public:
        virtual ~ManejadorPelicula();
        static ManejadorPelicula* getInstancia();
        DtPelicula* CrearDt(Pelicula*);
        void agregarPelicula(Pelicula*);
        map<string,DtPelicula*> listaPeliculas();
        Pelicula* obtenerPelicula(string);
        map<string,Pelicula*> obtenerPelis();
        void borrarPelicula(string);
        list<string> getTitulos();
        list<DtPeliculaPoster*> getListaDtPeliculaPoster();
};
#endif
