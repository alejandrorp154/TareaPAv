#ifndef DTPELICULAINFO_H
#define DTPELICULAINFO_H
#include <iostream>

using namespace std;

class DtPeliculaInfo{
    private:
        string sinopsis;
        string poster;
    public:
        //Constructores
        DtPeliculaInfo();
        DtPeliculaInfo(string,string);
        ~DtPeliculaInfo();
        //Getters
        string getSinopsis();
        string getPoster();
};
#endif
