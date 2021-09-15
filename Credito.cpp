#include "Credito.h"

Credito::Credito(){}
Credito::Credito(string financiera,int cantEntradas, float costo):Reserva(cantEntradas,costo){
    this->financiera = financiera;
}
Credito::~Credito(){}

string Credito::getFinanciera(){
    return this->financiera;
}
void Credito::setFinanciera(string f){
    financiera = f;
}
