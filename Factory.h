#ifndef FACTORY_H
#define FACTORY_H
#include <iostream>
#include "IControladorUsuario.h"
#include "ControladorUsuario.h"
#include "IControladorPuntajeComentario.h"
#include "ControladorPuntajeComentario.h"
#include "IControladorCine.h"
#include "ControladorCine.h"
/*#include "IControladorReserva.h"
#include "ControladorReserva.h"
#include "IControladorPelicula.h"
#include "ControladorPelicula.h"*/
#include "IControladorPelicula.h"
#include "ControladorPelicula.h"
using namespace std;

class Factory{
    private:
        static Factory* instancia;
        Factory();
    public:
        static Factory* getInstancia();
        IControladorUsuario* getIControladorUsuario();
        IControladorPuntajeComentario* getIControladorPuntajeComentario();
        IControladorCine* getIControladorCine();
        IControladorPelicula* getIControladorPelicula();

        /*IControladorReserva* getIControladorReserva();
        IControladorPelicula* getIControladorPelicula();*/
        ~Factory();
};
#endif
