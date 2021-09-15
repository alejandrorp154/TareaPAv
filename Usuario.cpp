#include "Usuario.h"
//Constructores y Destructores
Usuario::Usuario(){}
Usuario::Usuario(string n,string p,string i, bool b){
  nickname=n;
  password=p;
  imagen=i;
  admin=b;
}
Usuario::~Usuario(){}

//Getters y setters
string Usuario::getNickname(){
  return nickname;
}
string Usuario::getPassword(){
  return password;
}
string Usuario::getImagen(){
  return imagen;
}
bool Usuario::getAdmin(){
  return admin;
}
void Usuario::setNickname(string n){
  nickname=n;
}
void Usuario::setPassword(string p){
  password=p;
}
void Usuario::setImagen(string i){
  imagen=i;
}
void Usuario::setAdmin(bool a){
  admin=a;
}
