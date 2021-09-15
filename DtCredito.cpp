#include "DtCredito.h"

DtCredito::DtCredito(){}
DtCredito::DtCredito(int cantEntradas, float costo, string financiera, float porcentajeDescuento):DtReserva(cantEntradas, costo){
    this->financiera = financiera;
    this->porcentajeDescuento = porcentajeDescuento;
}
DtCredito::~DtCredito(){}

string DtCredito::getFinanciera(){
    return this->financiera;
}
float DtCredito::getPorcentajeDescuento(){
    return this->porcentajeDescuento;
}