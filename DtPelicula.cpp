#include "DtPelicula.h"

DtPelicula::DtPelicula(){}
DtPelicula::DtPelicula(string titulo, string poster, string sinopsis){
    this->titulo = titulo;
    this->poster = poster;
    this->sinopsis = sinopsis;
}
DtPelicula::~DtPelicula(){}

string DtPelicula::getTitulo(){
    return this->titulo;
}
string DtPelicula::getPoster(){
    return this->titulo;
}
string DtPelicula::getSinopsis(){
    return this->sinopsis;
}
float DtPelicula::getPuntajePromedio(){
    return this->puntajePromedio;
}
map<int,DtCine*> DtPelicula::obtenerCines(){
  return cines;
}
