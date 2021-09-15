#include "DtFuncion.h"

DtFuncion::DtFuncion(){}
DtFuncion::DtFuncion(int idFuncion, FechaHora horario){
    this->idFuncion = idFuncion;
    this->horario = horario;
}
DtFuncion::~DtFuncion(){}

int DtFuncion::getIdFuncion(){
    return this->idFuncion;
}
FechaHora DtFuncion::getHorario(){
    return this->horario;
}
