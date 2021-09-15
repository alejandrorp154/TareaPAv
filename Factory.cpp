#include "Factory.h"
Factory* Factory::instancia = NULL;

Factory::Factory(){}

Factory* Factory::getInstancia(){
    if (instancia == NULL)
        instancia = new Factory();
    return instancia;
}

IControladorUsuario* Factory::getIControladorUsuario(){
    return new ControladorUsuario();
}
IControladorPuntajeComentario* Factory::getIControladorPuntajeComentario(){
    return new ControladorPuntajeComentario();
}
IControladorCine* Factory::getIControladorCine(){
    return new ControladorCine();
}
/*IControladorReserva* Factory::getIControladorReserva(){
    return new ControladorReserva();
}
*/
IControladorPelicula* Factory::getIControladorPelicula(){
    return new ControladorPelicula();
}

Factory::~Factory(){}
