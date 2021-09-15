#include "DtPeliculaPoster.h"

DtPeliculaPoster::DtPeliculaPoster(){}
DtPeliculaPoster::DtPeliculaPoster(string titulo, string poster){
    this->titulo = titulo;
    this->poster = poster;
}
DtPeliculaPoster::~DtPeliculaPoster(){}

string DtPeliculaPoster::getTitulo(){
    return this->titulo;
}
string DtPeliculaPoster::getPoster(){
    return this->poster;
}
