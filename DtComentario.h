#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H
#include <iostream>
#include <list>

using namespace std;

class DtComentario{
    private:
        int idComentario;
        string texto;
        string nickname;
        list<DtComentario*> respuestas;

    public:
        //Constructores
        DtComentario();
        DtComentario(string,string,int);
        ~DtComentario();
        //Getters
        int getIdComentario();
        string getTexto();
        string getNickname();
        list<DtComentario*> obtenerRespuestas();
        void agregarRespuesta(DtComentario*);

};
#endif
