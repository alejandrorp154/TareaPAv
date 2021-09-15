#ifndef DTFUNCION_H
#define DTFUNCION_H
#include <iostream>
#include "FechaHora.h"

class DtFuncion{
    private:
        int idFuncion;
        FechaHora horario;
    public:
        // Constructores
        DtFuncion();
        DtFuncion(int, FechaHora);
        ~DtFuncion();
        //Getters
        int getIdFuncion();
        FechaHora getHorario();
};
#endif
