#ifndef DTPELICULATITULO_H
#define DTPELICULATITULO_H
#include <iostream>

using namespace std;

class DtPeliculaTitulo{
    private:
        string titulo;
        string sinopsis;
    public:
        //Constructores
        DtPeliculaTitulo();
        DtPeliculaTitulo(string,string);
        ~DtPeliculaTitulo();
        //Getters
        string getTitulo();
        string getSinopsis();
};
#endif
