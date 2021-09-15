#include "Reserva.h"
// Constructores y Destructores
Reserva::Reserva(){}
Reserva::Reserva(int cant,float c){
  cantEntradas=cant;
  costo=c;
}
Reserva::~Reserva(){}

// Getters y Setters
int Reserva::getCantEntradas(){
  return cantEntradas;
}
float Reserva::getCosto(){
  return costo;
}
void Reserva::setCantEntradas(int cant){
  cantEntradas=cant;
}
void Reserva::setCosto(float c){
  costo=c;
}
void Reserva::agregarUsuario(Usuario* u){
    usuario=u;
}
