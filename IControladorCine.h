#ifndef ICONTROLADORCINE_H
#define ICONTROLADORCINE_H
#include <iostream>
#include "DtCine.h"
#include "DtSala.h"
#include "DtFuncion.h"

using namespace std;

class IControladorCine{
    public:
        // Operaciones
        virtual void cargarCines()=0;
        virtual DtCine* altaCine()=0;
        virtual void agregarSala(DtSala*,int)=0;
        virtual void ingresarDirecionCine(string)=0;
        virtual list<DtSala*> getSalas(int)=0;
        virtual list<DtFuncion*> getFuncionesSala(int,int)=0;
};
#endif
