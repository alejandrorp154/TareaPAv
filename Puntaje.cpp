#include "Puntaje.h"

Puntaje::Puntaje(){}
Puntaje::Puntaje(float puntos){
    this->puntos = puntos;
}
Puntaje::~Puntaje(){}

float Puntaje::getPuntos(){
    return this->puntos;
}
void Puntaje::setPuntos(float p){
    puntos = p;
}
string Puntaje::getNicknameUsuario(){
    return this->usuario->getNickname();
}
void Puntaje::agregarUsuario(Usuario* u){
    this->usuario=u;
}
