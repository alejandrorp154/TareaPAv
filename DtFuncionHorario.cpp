#include "DtFuncionHorario.h"
// Constructores y Destructores
DtFuncionHorario::DtFuncionHorario(){}
DtFuncionHorario::DtFuncionHorario(FechaHora h){
  horario=h;
}
DtFuncionHorario::~DtFuncionHorario(){}

FechaHora DtFuncionHorario::getHorario(){
    return this->horario;
}
