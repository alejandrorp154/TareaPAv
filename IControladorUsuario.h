#ifndef ICONTROLADORUSUARIO_H
#define ICONTROLADORUSUARIO_H
#include <iostream>
#include "FechaHora.h"

using namespace std;

class IControladorUsuario{
    public:
        virtual void cargarUsuarios() = 0;
        virtual bool ingresarNickname(string) = 0;
        virtual bool ingresarPassword(string) = 0;
        virtual void iniciarSesion() = 0;
        virtual bool esAdmin()=0;
        virtual void ModificarFechaHoraSistema(FechaHora)=0;
        virtual FechaHora ConsultarFechaHoraSistema()=0;
};
#endif
