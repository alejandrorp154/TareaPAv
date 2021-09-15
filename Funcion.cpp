#include "Funcion.h"
#include"Reloj.h"
int Funcion::idFuncionEsta = 0;
Funcion::Funcion(){}
Funcion::Funcion(FechaHora horario, Pelicula* pelicula){
    this->idFuncion = idFuncionEsta;
    this->horario = horario;
    this->p=pelicula;
    idFuncionEsta++;
}
Funcion::~Funcion(){}

int Funcion::getIdFuncion(){
    return this->idFuncion;
}
FechaHora Funcion::getHorario(){
    return this->horario;
}
void Funcion::setIdFuncion(int idF){
    idFuncion = idF;
}
void Funcion::setHorario(FechaHora h){
    horario = h;
}
void Funcion::setPelicula(Pelicula* p){
  p = p;
}
string Funcion::getTituloPelicula(){
    return this->p->getTitulo();
}

void Funcion::eliminarReservas(){
    for(list<Reserva*>::iterator it=reservas.begin();it!=reservas.end();++it){
        delete (*it);
    }
    reservas.clear();
}
void Funcion::crearReserva(Reserva* res){
    reservas.push_back(res);
}
