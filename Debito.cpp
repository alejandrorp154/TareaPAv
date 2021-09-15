#include "Debito.h"

Debito::Debito(){}
Debito::Debito(int cantEntradas, float costo, string banco):Reserva(cantEntradas,costo){
    this->banco = banco;
}
Debito::~Debito(){}

string Debito::getBanco(){
    return this->banco;
}
void Debito::setBanco(string b){
    banco = b;
}
