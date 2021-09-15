#include "Cine.h"

int Cine::idCinesG=1;
Cine::Cine(){}
Cine::Cine(string direccion){
    this->direccion = direccion;
    idCine=idCinesG;
    idCinesG++;
}
Cine::~Cine(){}

int Cine::getIdCine(){
    return this->idCine;
}
string Cine::getDireccion(){
    return this->direccion;
}
void Cine::setIdCine(int idC){
    idCine = idC;
}
void Cine::setDireccion(string dir){
    direccion = dir;
}
void Cine::agregarSala(DtSala* dts){
    Sala* s=new Sala(dts->getCapacidad());
    ColeccionSalas.insert(std::pair<int,Sala*>(s->getIdSala(),s));
}
map<int,Sala*> Cine::obtenerSalas(){
    return ColeccionSalas;
}

 map<int,DtSala*> Cine::obtenerDtSala(){

    map<int,DtSala*> auxDt;
    list <DtFuncionHorario*> listaFH;
     for (map<int,Sala*>::iterator it=ColeccionSalas.begin(); it!=ColeccionSalas.end(); ++it){
        DtSala* dts = new DtSala(it->second->getIdSala(),it->second->getCapacidad());
        listaFH=it->second->obtenerDtFuncionHorario();
        for (list<DtFuncionHorario*>::iterator it2=listaFH.begin(); it2!=listaFH.end(); ++it2){
            dts->agregarDtFuncionHorario((*it2));
        }
        auxDt.insert(std::pair<int,DtSala*> (dts->getIdSala(),dts));
    }
    return auxDt;
 }

Sala* Cine::obtenerSala(int idSala){
    map<int,Sala*>::iterator it=this->ColeccionSalas.find(idSala);
    if(it!=this->ColeccionSalas.end()) {
        return it->second;
    }else{
      return NULL;
    }
}

void Cine::agregarSalaCine(Sala* s){
    ColeccionSalas.insert(std::pair<int,Sala*>(s->getIdSala(),s));
}

void Cine::eliminarFunciones(string titulo){
     for(map<int,Sala*>::iterator it=ColeccionSalas.begin();it!=ColeccionSalas.end();++it){
        it->second->eliminarFunciones(titulo);
    }
}
