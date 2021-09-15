#include "Comentario.h"

int Comentario::idComentarioG=0;
Comentario::Comentario(){}
Comentario::Comentario(string texto){
    this->idComentario = idComentarioG;
    idComentarioG++;
    this->texto = texto;
}
Comentario::~Comentario(){
  if(respuesta.size()!=0){
    for(map<int,Comentario*>::iterator it=respuesta.begin();it!=respuesta.end();++it){
      Comentario* c=it->second;
      cout << "Comentario Respuesta " << it->second->getTexto() << endl;
      delete c;
    }
    respuesta.clear();
  }
}

int Comentario::getIdComentario(){
    return this->idComentario;
}
string Comentario::getTexto(){
    return this->texto;
}
void Comentario::setIdComentario(int idC){
    idComentario = idC;
}
void Comentario::setTexto(string t){
    texto = t;
}

void Comentario::agregarUsuario(Usuario* u){
    usuario=u;
}
void Comentario::agregarRespuesta(Comentario* c){
    respuesta.insert(pair<int,Comentario*>(c->getIdComentario(),c));
}
Usuario* Comentario::obtenerUsuario(){
    return usuario;
}
map<int,Comentario*>Comentario::obtenerRespuestas(){
    return respuesta;
}
DtComentario* Comentario::retornarDtComentario(){
    DtComentario* dtc;
    dtc= new DtComentario(texto,usuario->getNickname(),this->idComentario);
    if(!respuesta.empty()){
        for(map<int,Comentario*>::iterator it=respuesta.begin();it!=respuesta.end();++it){
            DtComentario* DtRespuesta;
            DtRespuesta= new DtComentario(texto,it->second->obtenerUsuario()->getNickname(),it->second->getIdComentario());
            dtc->agregarRespuesta(it->second->retornarDtComentario());
        }
    }
    return dtc;
}
Comentario* Comentario::buscarRespuestaComentario(int id){
    Comentario* aux;
    for(map<int,Comentario*>::iterator it=respuesta.begin();it!=respuesta.end();++it){
        if(it->first==id){
            aux= it->second;
            return aux;
        }
        else if(it->second->obtenerRespuestas().size()!=0){
            aux= it->second->buscarRespuestaComentario(id);
        }else{
            aux= NULL;
        }
    }
    return aux;
}
