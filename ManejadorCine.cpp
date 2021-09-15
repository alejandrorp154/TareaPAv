#include "ManejadorCine.h"

ManejadorCine* ManejadorCine::instancia=NULL;

ManejadorCine::ManejadorCine(){}
ManejadorCine::~ManejadorCine(){}

ManejadorCine* ManejadorCine::getInstancia(){
    if (instancia==NULL)
        instancia = new ManejadorCine();
    return instancia;
}
void ManejadorCine::agregarCine(Cine* c){
    ColeccionCines.insert(std::pair<int,Cine*>(c->getIdCine(),c));
}
Cine* ManejadorCine::obtenerCine(int id){
    map<int,Cine*>::iterator it=this->ColeccionCines.find(id);
    if(it!=ColeccionCines.end()){
        return it->second;
    }
    return NULL;
}

map<int,Cine*> ManejadorCine::getCines(){
    return ColeccionCines;
}
