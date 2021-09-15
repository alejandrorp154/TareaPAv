//CONTROLADOR Usuario

#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H
#include <iostream>
#include <list>
#include <map>
#include "Sesion.h"
#include "Usuario.h"
#include "ManejadorUsuario.h"
#include "IControladorUsuario.h"
#include "FechaHora.h"
using namespace std;

class ControladorUsuario:public IControladorUsuario{
    private:
        string nickname;
        bool passwordvalido;
    public:
        ControladorUsuario();
        ~ControladorUsuario();
        // Operaciones
        void cargarUsuarios();
        bool ingresarNickname(string);
        bool ingresarPassword(string);
        void iniciarSesion();
        bool esAdmin();
        void ModificarFechaHoraSistema(FechaHora);
        FechaHora ConsultarFechaHoraSistema();
};
#endif
