#include "FechaHora.h"

FechaHora::FechaHora(){}
FechaHora::FechaHora(int dia,int mes,int anio,int hora,int minuto):Fecha(dia,mes,anio){
    this->hora = hora;
    this->minuto = minuto;
}
FechaHora::~FechaHora(){}

int FechaHora::getHora(){
    return this->hora;
}
int FechaHora::getMinuto(){
    return this->minuto;
}
void FechaHora::setHora(int h){
    this->hora = h;
}
void FechaHora::setMinuto(int m){
    this->minuto = m;
}
ostream& operator<<(ostream& salida,const FechaHora& fh){
    cout<<(Fecha) fh;
    cout << "Hora " << fh.hora << ":" << fh.minuto << endl;
    return salida;
 }
