#include "DtPeliculaPuntajeComentario.h"

DtPeliculaPuntajeComentario::DtPeliculaPuntajeComentario(){}
DtPeliculaPuntajeComentario::DtPeliculaPuntajeComentario(string titulo, float puntajePromedio){
    this->titulo = titulo;
    this->puntajePromedio = puntajePromedio;
}
DtPeliculaPuntajeComentario::~DtPeliculaPuntajeComentario(){}

string DtPeliculaPuntajeComentario::getTitulo(){
    return this->titulo;
}
float DtPeliculaPuntajeComentario::getPuntajePromedio(){
    return this->puntajePromedio;
}

string DtPeliculaPuntajeComentario::getNickname(){
    return this->nickname;
}

void DtPeliculaPuntajeComentario::agregarPuntaje(DtPuntaje* dt){
    puntajes.push_back(dt);
}
void DtPeliculaPuntajeComentario::agregarComentario(DtComentario* dtc){
    comentarios.push_back(dtc);
}
list<DtPuntaje*> DtPeliculaPuntajeComentario::obtenerPuntajes(){
    return puntajes;
}
list<DtComentario*> DtPeliculaPuntajeComentario::obtenerComentarios(){
    return comentarios;
}
