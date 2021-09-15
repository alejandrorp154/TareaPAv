#include "DtReserva.h"

DtReserva::DtReserva(){}
DtReserva::DtReserva(int cantEntradas, float costo){
    this->cantEntradas = cantEntradas;
    this->costo = costo;
}
DtReserva::~DtReserva(){}

int DtReserva::getCantEntradas(){
    return this->cantEntradas;
}
float DtReserva::getCosto(){
    return this->costo;
}
