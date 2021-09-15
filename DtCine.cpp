#include "DtCine.h"

DtCine::DtCine(){}
DtCine::DtCine(int idCine, string direccion){
    this->idCine = idCine;
    this->direccion = direccion;
}
DtCine::~DtCine(){}

int DtCine::getIdCine(){
    return this->idCine;
}
string DtCine::getDireccion(){
    return this->direccion;
}
ostream& operator<<(ostream& salida, const DtCine& dtc){
    cout<<"Id: " << dtc.idCine<<endl;
    cout<<"Direccion: " << dtc.direccion<<endl;
    return salida;
}
