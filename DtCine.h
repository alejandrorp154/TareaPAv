#ifndef DTCINE_H
#define DTCINE_H
#include <iostream>

using namespace std;

class DtCine{
    private:
        int idCine;
        string direccion;
    public:
        // Constructores
        DtCine();
        DtCine(int,string);
        ~DtCine();
        // Getters
        int getIdCine();
        string getDireccion();
        friend ostream& operator<<(ostream&,const DtCine&);
};
#endif
