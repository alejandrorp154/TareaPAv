#ifndef PELICULA_H
#define PELICULA_H
#include <iostream>
#include <map>
#include <list>

#include "Comentario.h"
#include "Puntaje.h"
#include "Cine.h"
#include "DtCine.h"
#include "DtPuntaje.h"
#include "DtComentario.h"

using namespace std;

// class Cine;

class Pelicula{
    private:
        string titulo;
        string poster;
        string sinopsis;
        float puntajePromedio;
        list<Puntaje*> puntajes;
        map<int,Comentario*> comentarios;
        map<int,Cine*> cines;
    public:
        //Constructores y Destructores
        Pelicula();
        Pelicula(string,string,string);
        ~Pelicula();
        //Getters y Setters
        string getTitulo();
        string getPoster();
        string getSinopsis();
        float getPuntajePromedio();
        void setTitulo(string);
        void setPoster(string);
        void setSinopsis(string);
        void agregarCine(Cine* c);
        map<int,Cine*> obtenerCines();
        list<DtPuntaje*> obtenerPuntajes();
        void agregarPuntaje(Puntaje*);
        list<DtComentario*> crearDtComentarios();
        void agregarComentario(Comentario* c);
        Comentario* obtenerComentario(int);
        bool existePuntajeUsuario(string);
        float puntajeUsuario(string);
        void modificarPuntaje(float,string);
        void eliminarFunciones(string);
        void eliminarComentariosPuntajes();

        /*crearReserva();
        seleccionarFuncion(string);
        obtenerDtFuncion();
        listaCines();
        guardarFunciones();
        eliminarPelicula();
        listaCines();*/
};



#endif
