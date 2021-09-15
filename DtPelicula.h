#ifndef DTPELICULA_H
#define DTPELICULA_H
#include <iostream>
#include <map>
#include "DtCine.h"

using namespace std;

class DtPelicula{
    private:
        string titulo;
        string poster;
        string sinopsis;
        float puntajePromedio;
        map<int,DtCine*> cines;
    public:
        // Constructores
        DtPelicula();
        DtPelicula(string, string, string);
        ~DtPelicula();
        // Getters
        string getTitulo();
        string getPoster();
        string getSinopsis();
        float getPuntajePromedio();
        map<int,DtCine*> obtenerCines();
};
#endif
