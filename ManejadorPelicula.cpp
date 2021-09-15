#include "ManejadorPelicula.h"

ManejadorPelicula* ManejadorPelicula::instancia=NULL;

ManejadorPelicula::ManejadorPelicula(){}
ManejadorPelicula::~ManejadorPelicula(){}

ManejadorPelicula* ManejadorPelicula::getInstancia(){
    if (instancia==NULL)
        instancia = new ManejadorPelicula();
    return instancia;
}
void ManejadorPelicula::agregarPelicula(Pelicula* p){
    ColeccionPeliculas.insert(std::pair<string,Pelicula*>(p->getTitulo(),p));
}

Pelicula* ManejadorPelicula::obtenerPelicula(string titulo){
    map<string,Pelicula*>::iterator it=this->ColeccionPeliculas.find(titulo);
    if(it!=this->ColeccionPeliculas.end()){
        return it->second;
    }else{
      return NULL;
    }
}

map<string,Pelicula*> ManejadorPelicula::obtenerPelis(){
    return this->ColeccionPeliculas;
}

DtPelicula* ManejadorPelicula::CrearDt(Pelicula* p){
  DtPelicula* dtp = new DtPelicula(p->getTitulo(),p->getPoster(),p->getSinopsis());
  return dtp;
};

map<string,DtPelicula*> ManejadorPelicula::listaPeliculas(){
  map<string,DtPelicula*> pelis;
  DtPelicula* dtp = new DtPelicula();
  for (map<string,Pelicula*>::iterator it=this->ColeccionPeliculas.begin(); it!=this->ColeccionPeliculas.end(); ++it){
  //for (map<string,Pelicula*>::iterator it=this->ColeccionPeliculas.begin(); it!=this->ColeccionPeliculas.end(); ++it){
    dtp = CrearDt(it->second);
    pelis.insert(std::pair<string,DtPelicula*>(dtp->getTitulo(),dtp));
  }
  //for (map<string,DtPelicula*>::iterator it=map->begin(); it!=map.end(); ++it)
  //  cout << it->second->getTitulo() << endl << "Sinopsis: " << it->second->getSinopsis() << endl << it->second->getPoster() << "avg " << it->second->getPuntajePromedio() << endl;
  return pelis;
};

void ManejadorPelicula::borrarPelicula(string titulo){
    map<string,Pelicula*>::iterator it=this->ColeccionPeliculas.find(titulo);
    this->ColeccionPeliculas.erase(it);
}
list<string> ManejadorPelicula::getTitulos(){
    list<string> listaTitulos;
    for (map<string,Pelicula*>::iterator it=this->ColeccionPeliculas.begin(); it!=ColeccionPeliculas.end(); ++it){
        listaTitulos.push_back(it->second->getTitulo());
    }
    return listaTitulos;
}

list<DtPeliculaPoster*> ManejadorPelicula::getListaDtPeliculaPoster(){
    list<DtPeliculaPoster*> listaDtPeliculaPoster;
    for (map<string,Pelicula*>::iterator it=this->ColeccionPeliculas.begin(); it!=this->ColeccionPeliculas.end(); ++it){
        DtPeliculaPoster* dt= new DtPeliculaPoster(it->second->getTitulo(), it->second->getPoster());
        listaDtPeliculaPoster.push_back(dt);
    }
    return listaDtPeliculaPoster;
}
