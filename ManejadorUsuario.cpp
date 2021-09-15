#include "ManejadorUsuario.h"

ManejadorUsuario* ManejadorUsuario::instancia=NULL;

ManejadorUsuario::ManejadorUsuario(){}
ManejadorUsuario::~ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if (instancia==NULL)
        instancia = new ManejadorUsuario();
    return instancia;
}
void ManejadorUsuario::agregarUsuario(Usuario* u){
    ColeccionUsuarios.insert(std::pair<string,Usuario*>(u->getNickname(),u));
}
Usuario* ManejadorUsuario::obtenerUsuario(string nick){
    //map<string,Usuario*>::iterator it=this->ColeccionUsuarios.find(nick);
    for(map<string,Usuario*>::iterator it=this->ColeccionUsuarios.begin();it!=this->ColeccionUsuarios.end();++it){
        if(it->first==nick){
            return it->second;
        }
    }
    return NULL;
}
void ManejadorUsuario::ModificarFechaHoraSistema(FechaHora f){
  this->f=f;
  Reloj* R = Reloj::getInstancia();
  R->modificarFecha(f);
}

FechaHora ManejadorUsuario::ConsultarFechaHoraSistema(){
  return this->f;
}
