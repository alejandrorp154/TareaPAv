#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <iostream>
#include <map>
#include <list>
#include "Usuario.h"
#include "DtComentario.h"

class Comentario{
    private:
        int idComentario;
        static int idComentarioG;
        string texto;
        map<int,Comentario*> respuesta;
        Usuario* usuario;
    public:
        //Constructores
        Comentario();
        Comentario(string);
        ~Comentario();
        //Getters y Setters
        int getIdComentario();
        string getTexto();
        void setIdComentario(int);
        void setTexto(string);
        void agregarUsuario(Usuario*);
        void agregarRespuesta(Comentario*);
        Usuario* obtenerUsuario();
        map<int,Comentario*> obtenerRespuestas();
        DtComentario* retornarDtComentario();
        Comentario* buscarRespuestaComentario(int);
        // eliminarRespuesta()
};
#endif
