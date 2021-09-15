#include "Sesion.h"

Sesion *Sesion::instancia = NULL;
Sesion::Sesion(){}
Sesion::Sesion(string nickname, bool admin){
    this->nickname = nickname;
    this->admin = admin;
}
Sesion::~Sesion(){}

Sesion* Sesion::getInstancia(){
    if(instancia == NULL)
        instancia = new Sesion();
    return instancia;
}

string Sesion::getNickname(){
    return this->nickname;
}
bool Sesion::getAdmin(){
    return this->admin;
}
void Sesion::setNickname(string n){
    nickname = n;
}
void Sesion::setAdmin(bool a){
    admin = a;
}
