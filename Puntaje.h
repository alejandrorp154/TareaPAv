#ifndef PUNTAJE_H
#define PUNTAJE_H
#include <iostream>
#include "Usuario.h"

using namespace std;

class Puntaje{
    private:
        float puntos;
        Usuario* usuario;
    public:
        //Constructores
        Puntaje();
        Puntaje(float);
        ~Puntaje();
        //Getters y Setters
        float getPuntos();
        void setPuntos(float);
        void agregarUsuario(Usuario*);
        // Operaciones
        string getNicknameUsuario();
};
#endif
