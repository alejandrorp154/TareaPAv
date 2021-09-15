#include "Financiera.h"

Financiera::Financiera(){}
Financiera::Financiera(string n,float d){
    nombre=n;
    descuento=d;
}
Financiera::~Financiera(){}
string Financiera::getNombre(){
    return this->nombre;
}
float Financiera::getDescuento(){
    return this->descuento;
}
