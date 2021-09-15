#include "DtPuntaje.h"

DtPuntaje::DtPuntaje(){}
DtPuntaje::DtPuntaje(string nickname, float puntos){
    this->nickname = nickname;
    this->puntos = puntos;
}
DtPuntaje::~DtPuntaje(){}

string DtPuntaje::getNickname(){
    return this->nickname;
}
float DtPuntaje::getPuntos(){
    return this->puntos;
}
