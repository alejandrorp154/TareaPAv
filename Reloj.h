#ifndef RELOJ_H
#define	RELOJ_H

#include <iostream>
#include "FechaHora.h"

using namespace std;

class Reloj{
  private:
    FechaHora fh;
    static Reloj* instancia;
    Reloj();
  public:
    Reloj(FechaHora);
    virtual ~Reloj();
    static Reloj* getInstancia();
    void modificarFecha(FechaHora Hora);
    FechaHora obtenerFecha();

};

#endif
