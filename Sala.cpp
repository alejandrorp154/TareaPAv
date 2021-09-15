#include "Sala.h"

int Sala::idSalaEsta = 0;

Sala::Sala(){}
Sala::Sala(int capacidad){
    this->idSala=Sala::idSalaEsta;
    this->capacidad = capacidad;
    idSalaEsta++;
}
Sala::~Sala(){}

int Sala::getIdSala(){
    return this->idSala;
}
int Sala::getCapacidad(){
    return this->capacidad;
}
void Sala::setIdSala(int idS){
    this->idSala = idS;
}
void Sala::setCapacidad(int c){
    this->capacidad = c;
}
void Sala::agregarFuncion(Funcion* f){ // FIX
  ColeccionFunciones.insert(std::pair<int,Funcion*>(f->getIdFuncion(),f));
}

map<int,Funcion*> Sala::obtenerFunciones(){
  return this->ColeccionFunciones;
}

list<DtFuncionHorario*> Sala::obtenerDtFuncionHorario(){
    list<DtFuncionHorario*> auxDt;
    for (map<int,Funcion*>::iterator it=ColeccionFunciones.begin(); it!=ColeccionFunciones.end(); ++it){
        DtFuncionHorario* dt = new DtFuncionHorario(it->second->getHorario());
        auxDt.push_back(dt);
    }
    return auxDt;
}

void Sala::eliminarFunciones(string titulo){
    for(map<int,Funcion*>::iterator it=ColeccionFunciones.begin();it!=ColeccionFunciones.end();++it){
        if (it->second->getTituloPelicula()==titulo){
           it->second->eliminarReservas();
            Funcion* f=it->second;
            if (f!=NULL){
                delete f;
            }
            ColeccionFunciones.erase(it);
        }
    }
}
