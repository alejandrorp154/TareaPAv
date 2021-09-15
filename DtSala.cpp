#include "DtSala.h"
// Constructores y Destructores
DtSala::DtSala(){}
DtSala::DtSala(int i,int c){
  idSala=i;
  capacidad=c;
}
DtSala::~DtSala(){}
// Getters
int DtSala::getIdSala(){
  return idSala;
}
int DtSala::getCapacidad(){
  return capacidad;
}

void DtSala::agregarDtFuncionHorario(DtFuncionHorario* dt){
    horaFunciones.push_back(dt);
}

list<DtFuncionHorario*> DtSala::obtenerDtFuncionHorario(){
    return horaFunciones;
}

ostream& operator<<(ostream& salida, const DtSala& dts){
    cout<<"Id: " << dts.idSala<<endl;
    cout<<"Capacidad de asientos: " << dts.capacidad<<endl;
    return salida;
}
