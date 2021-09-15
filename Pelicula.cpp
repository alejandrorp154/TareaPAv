#include "Pelicula.h"

Pelicula::Pelicula(){}
Pelicula::Pelicula(string titulo, string poster, string sinopsis){
    this->titulo = titulo;
    this->poster = poster;
    this->sinopsis = sinopsis;
}
Pelicula::~Pelicula(){}

string Pelicula::getTitulo(){
    return this->titulo;
}
string Pelicula::getPoster(){
    return this->poster;
}
string Pelicula::getSinopsis(){
    return this->sinopsis;
}
float Pelicula::getPuntajePromedio(){
    if (puntajes.size()!=0){
        float suma=0;
        for(list<Puntaje*>::iterator it=puntajes.begin();it!=puntajes.end();++it){
            suma+=(*it)->getPuntos();
        }
        return suma / puntajes.size();
    }else{
        return 0;
    }
}
void Pelicula::setTitulo(string t){
    titulo=t;
}
void Pelicula::setPoster(string p){
    poster=p;
}
void Pelicula::setSinopsis(string s){
    sinopsis=s;
}
void Pelicula::agregarPuntaje(Puntaje* punt){
    puntajes.push_back(punt);
}
void Pelicula::agregarCine(Cine* c){
  cines.insert(std::pair<int,Cine*>(c->getIdCine(),c));
}
map<int,Cine*> Pelicula::obtenerCines(){
  return cines;
}

list<DtPuntaje*> Pelicula::obtenerPuntajes(){
    list<DtPuntaje*> listDtPuntaje;
    for(list<Puntaje*>::iterator it=puntajes.begin();it!=puntajes.end();++it){
        DtPuntaje* dtpunt = new DtPuntaje((*it)->getNicknameUsuario(), (*it)->getPuntos());
        listDtPuntaje.push_back(dtpunt);
    }
    return listDtPuntaje;
}

list<DtComentario*> Pelicula::crearDtComentarios(){
    list<DtComentario*> listaDtComentarios;
    for(map<int,Comentario*>::iterator it=comentarios.begin();it!=comentarios.end();++it){
        DtComentario* dtc=it->second->retornarDtComentario();
        listaDtComentarios.push_back(dtc);
    }
    return listaDtComentarios;
}

void  Pelicula::agregarComentario(Comentario* c){
    comentarios.insert(pair<int,Comentario*>(c->getIdComentario(),c));
}

bool Pelicula::existePuntajeUsuario(string nickname){
    for(list<Puntaje*>::iterator it=puntajes.begin();it!=puntajes.end();++it){
        if ((*it)->getNicknameUsuario()==nickname){
            return true;
        }
    }
    return false;
}

float Pelicula::puntajeUsuario(string nickname){
    for(list<Puntaje*>::iterator it=puntajes.begin();it!=puntajes.end();++it){
        if ((*it)->getNicknameUsuario()==nickname){
            return (*it)->getPuntos();
        }
    }
}

void Pelicula::modificarPuntaje(float p, string nick){
    for(list<Puntaje*>::iterator it= puntajes.begin();it!=puntajes.end();++it){
        if((*it)->getNicknameUsuario()==nick){
            (*it)->setPuntos(p);
        }
    }
}

Comentario* Pelicula::obtenerComentario(int id){
    Comentario* aux;
    for(map<int,Comentario*>::iterator it=comentarios.begin();it!=comentarios.end();++it){
        if(it->first==id){
            aux= it->second;
            return aux;
        }
        else if(it->second->obtenerRespuestas().size()!=0){
          aux=it->second->buscarRespuestaComentario(id);
          if(aux!=NULL){
            if(aux->getIdComentario()==id){
              return aux;
            }
          }
        }else{
            aux=NULL;
        }
    }
    return aux;
}

void Pelicula::eliminarFunciones(string titulo){
    for(map<int,Cine*>::iterator it=cines.begin();it!=cines.end();++it){
        it->second->eliminarFunciones(titulo);
    }
}

void Pelicula::eliminarComentariosPuntajes(){
  for(list<Puntaje*>::iterator it=puntajes.begin();it!=puntajes.end();++it){
    Puntaje* p=(*it);
    delete p;
  }
  puntajes.clear();
  for(map<int,Comentario*>::iterator it=comentarios.begin();it!=comentarios.end();++it){
    Comentario* c=it->second;
    delete c;
  }
}

/*
seleccionarFuncion(string);
obtenerDtFuncion();
listaCines();
guardarFunciones();
eliminarPelicula();
listaCines();*/
