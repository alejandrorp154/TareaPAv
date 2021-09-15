#include "ControladorUsuario.h"

ControladorUsuario::ControladorUsuario():IControladorUsuario(){}
ControladorUsuario::~ControladorUsuario(){}

void ControladorUsuario::cargarUsuarios(){
    ManejadorUsuario* mu=ManejadorUsuario::getInstancia();
    Usuario* u=new Usuario("Mohammed", "Salah", "penege", true);
    Usuario* u2=new Usuario("Nemo", "Dori", "imagen2", true);
    Usuario* u3=new Usuario("Walt", "D", "imagen2", false);
    Usuario* u4=new Usuario("a", "b", "imagen2", true);
    mu->agregarUsuario(u);
    mu->agregarUsuario(u2);
    mu->agregarUsuario(u3);
    mu->agregarUsuario(u4);
}

bool ControladorUsuario::ingresarNickname(string n){

    ManejadorUsuario* mu=ManejadorUsuario::getInstancia();
    Usuario* u=mu->obtenerUsuario(n);
    if(u!=NULL){
        nickname=n;
        return true;
    }else{
        return false;
    }
}

bool ControladorUsuario::ingresarPassword(string p){
    ManejadorUsuario* mu=ManejadorUsuario::getInstancia();
    bool a=true;
    Usuario* u=mu->obtenerUsuario(nickname);
    if(p==u->getPassword()){
        passwordvalido=true;
        return true;
    }
    passwordvalido=false;
    return false;
}

void ControladorUsuario::iniciarSesion(){
    bool admin;
    bool a=true;
    if(passwordvalido){
        ManejadorUsuario* mu=ManejadorUsuario::getInstancia();
        Usuario* u=mu->obtenerUsuario(nickname);
        admin=u->getAdmin();
        Sesion* s=Sesion::getInstancia();
        s->setNickname(nickname);
        s->setAdmin(admin);
    }
}

bool ControladorUsuario::esAdmin(){
  bool admin=false;
  Sesion* s=Sesion::getInstancia();
  admin=s->getAdmin();


  return admin;
}
void ControladorUsuario::ModificarFechaHoraSistema(FechaHora f){
  ManejadorUsuario* mu=ManejadorUsuario::getInstancia();
  mu->ModificarFechaHoraSistema(f);
}
FechaHora ControladorUsuario::ConsultarFechaHoraSistema(){
  ManejadorUsuario* mu=ManejadorUsuario::getInstancia();
  FechaHora f=mu->ConsultarFechaHoraSistema();
  return f;
}
