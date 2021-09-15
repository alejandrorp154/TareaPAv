#include "DtDebito.h"

DtDebito::DtDebito(){}
DtDebito::DtDebito(int cantEntradas, float costo, string banco):DtReserva(cantEntradas, costo){
    this->banco = banco;
}
DtDebito::~DtDebito(){}

string DtDebito::getBanco(){
    return this->banco;
}