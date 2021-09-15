#ifndef DTPELICULAPOSTER_H
#define DTPELICULAPOSTER_H
#include <iostream>

using namespace std;

class DtPeliculaPoster{
    private:
        string titulo;
        string poster;
    public:
        //Constructores
        DtPeliculaPoster();
        DtPeliculaPoster(string,string);
        ~DtPeliculaPoster();
        //Getters
        string getTitulo();
        string getPoster();
};
#endif
