#ifndef DTFUNCIONHORARIO_H
#define DTFUNCIONHORARIO_H

#include "FechaHora.h"

class DtFuncionHorario{
  private:
    FechaHora horario;
  public:
    // Constructores y Destructores
    DtFuncionHorario();
    DtFuncionHorario(FechaHora);
    ~DtFuncionHorario();
    // Getters
    FechaHora getHorario();
};

#endif
