#include "Fecha.h"

Fecha::Fecha(){}
Fecha::Fecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}
Fecha::~Fecha(){}

int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}
void Fecha::setDia(int d){
    this->dia = d;
}
void Fecha::setMes(int m){
    this->mes = m;
}
void Fecha::setAnio(int a){
    this->anio = a;
}

ostream& operator<<(ostream& salida, const Fecha& f){
    cout << "Dia " << f.dia << "/" << f.mes << "/" << f.anio <<endl;
    return salida;
}
