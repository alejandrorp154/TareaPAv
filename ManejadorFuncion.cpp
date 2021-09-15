#include "ManejadorFuncion.h"

ManejadorFuncion* ManejadorFuncion::instancia=NULL;

ManejadorFuncion::ManejadorFuncion(){}
ManejadorFuncion::~ManejadorFuncion(){}

ManejadorFuncion* ManejadorFuncion::getInstancia(){
    if (instancia==NULL)
        instancia = new ManejadorFuncion();
    return instancia;
}

void ManejadorFuncion::agregarFuncion(Funcion* f){
    ColeccionFunciones.insert(std::pair<int,Funcion*>(f->getIdFuncion(),f));
}

Funcion* ManejadorFuncion::obtenerFuncion(int id){
    map<int,Funcion*>::iterator it=this->ColeccionFunciones.find(id);
    return it->second;
}

map<int,Funcion*> ManejadorFuncion::listarFunciones(){
  return this->ColeccionFunciones;
}

