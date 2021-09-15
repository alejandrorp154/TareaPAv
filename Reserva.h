#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include "Usuario.h"
#include "TipoPago.h"

using namespace std;

class Reserva{
  private:
    int cantEntradas;
    float costo;
    Usuario* usuario;
  public:
    // Constructores y Destructores
    Reserva();
    Reserva(int,float);
    virtual~Reserva();
    // Getters y Setters
    int getCantEntradas();
    float getCosto();
    void setCantEntradas(int);
    void setCosto(float);
    // Operaciones
    void agregarUsuario(Usuario*);
};
#endif
