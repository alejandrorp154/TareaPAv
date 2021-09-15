#ifndef DTPELICULAPUNTAJECOMENTARIO_H
#define DTPELICULAPUNTAJECOMENTARIO_H
#include <iostream>
#include <map>
#include <list>
#include "DtPuntaje.h"
#include "DtComentario.h"
using namespace std;

class DtPeliculaPuntajeComentario{
    private:
        string titulo;
        float puntajePromedio;
        string nickname;
        list<DtPuntaje*> puntajes;
        list<DtComentario*> comentarios;
    public:
        DtPeliculaPuntajeComentario();
        DtPeliculaPuntajeComentario(string, float);
        ~DtPeliculaPuntajeComentario();
        string getTitulo();
        float getPuntajePromedio();
        string getNickname();
        void agregarPuntaje(DtPuntaje*);
        void agregarComentario(DtComentario*);
        list<DtPuntaje*> obtenerPuntajes();
        list<DtComentario*> obtenerComentarios();
};
#endif
