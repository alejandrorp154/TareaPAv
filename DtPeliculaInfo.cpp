#include "DtPeliculaInfo.h"

DtPeliculaInfo::DtPeliculaInfo(){}
DtPeliculaInfo::DtPeliculaInfo(string sinopsis, string poster){
    this->sinopsis = sinopsis;
    this->poster = poster;
}
DtPeliculaInfo::~DtPeliculaInfo(){}

string DtPeliculaInfo::getSinopsis(){
    return this->sinopsis;
}
string DtPeliculaInfo::getPoster(){
    return this->poster;
}
