#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include "Usuario.h"
#include "Reloj.h"
#include "FechaHora.h"
#include <iostream>
#include <map>

using namespace std;

class ManejadorUsuario{
    private:
        map<string,Usuario*> ColeccionUsuarios;
        static ManejadorUsuario* instancia;
        FechaHora f;
        ManejadorUsuario();

    public:
        virtual ~ManejadorUsuario();
        static ManejadorUsuario* getInstancia();
        void agregarUsuario(Usuario*);
        Usuario* obtenerUsuario(string);
        void ModificarFechaHoraSistema(FechaHora);
        FechaHora ConsultarFechaHoraSistema();
};
#endif
