#include "DtPeliculaTitulo.h"

DtPeliculaTitulo::DtPeliculaTitulo(){}
DtPeliculaTitulo::DtPeliculaTitulo(string titulo, string sinopsis){
    this->titulo = titulo;
    this->sinopsis = sinopsis;
}
DtPeliculaTitulo::~DtPeliculaTitulo(){}

string DtPeliculaTitulo::getTitulo(){
    return this->titulo;
}
string DtPeliculaTitulo::getSinopsis(){
    return this->sinopsis;
}
