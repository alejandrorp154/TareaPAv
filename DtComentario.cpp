#include "DtComentario.h"

DtComentario::DtComentario(){}
DtComentario::DtComentario(string texto, string nickname,int idComentario){
    this->idComentario= idComentario;
    this->texto = texto;
    this->nickname = nickname;
}
DtComentario::~DtComentario(){}

int DtComentario::getIdComentario(){
    return this->idComentario;
}
string DtComentario::getTexto(){
    return this->texto;
}

string DtComentario::getNickname(){
    return this->nickname;
}
list<DtComentario*> DtComentario::obtenerRespuestas(){
    return respuestas;
}
void DtComentario::agregarRespuesta(DtComentario* dtc){
    respuestas.push_back(dtc);
}
