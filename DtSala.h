#ifndef DTSALA_H
#define DTSALA_H
#include "DtFuncionHorario.h"
#include <iostream>
#include <list>

using namespace std;

class DtSala{
  private:
    int idSala;
    int capacidad;
    list<DtFuncionHorario*> horaFunciones;
  public:
    // Constructores y Destructores
    DtSala();
    DtSala(int,int);
    ~DtSala();
    // Getters
    int getIdSala();
    int getCapacidad();
    void agregarDtFuncionHorario(DtFuncionHorario* dt);
    list<DtFuncionHorario*> obtenerDtFuncionHorario();
    friend ostream& operator<<(ostream&, const DtSala&);
};
#endif
