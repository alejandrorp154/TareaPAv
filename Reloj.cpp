#include "Reloj.h"

Reloj* Reloj::instancia = NULL;
Reloj::Reloj(){}
Reloj::Reloj(FechaHora fecha){
  this->fh=fecha;
}
Reloj::~Reloj(){}

Reloj* Reloj::getInstancia(){
    if (instancia == NULL)
        instancia = new Reloj();
    return instancia;
}
void Reloj::modificarFecha(FechaHora fecha){
    this->fh=fecha;
}
FechaHora Reloj::obtenerFecha(){
    return this->fh;
}
