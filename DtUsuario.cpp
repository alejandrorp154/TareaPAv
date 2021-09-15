//DTUSUARIO.CPP
#include "DtUsuario.h"
//Constructores y Destructores
DtUsuario::DtUsuario(){}
DtUsuario::DtUsuario(string n,string p,string i){
    nickname=n;
    password=p;
    imagen=i;
}
DtUsuario::~DtUsuario(){}

//Getters y setters
string DtUsuario::getNickname(){
    return nickname;
}
string DtUsuario::getPassword(){
    return password;
}
string DtUsuario::getImagen(){
    return imagen;
}
bool DtUsuario::getAdmin(){
    return admin;
}
