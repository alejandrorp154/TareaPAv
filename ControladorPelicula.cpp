#include "ControladorPelicula.h"

ControladorPelicula::ControladorPelicula():IControladorPelicula(){};
ControladorPelicula::~ControladorPelicula(){};

void ControladorPelicula::cargarPeliculas(){
    ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
                          //titulo,poster,sinopsis,puntajePromedio
    Pelicula* p1=new Pelicula("La monja y el bombero 4","+18","BBC");
    Pelicula* p7=new Pelicula("Annabelle 3","Viene a casa","Un miedo de novela.");
    Pelicula* p2=new Pelicula("Make Love, Not Warcraft","Southpark.","WOW");
    Pelicula* p3=new Pelicula("Chernobyl","Ukrania","Accidente nuclear.");
    Pelicula* p4=new Pelicula("Caperucita roja","Poster de la caperucita y el lobo","El lobo se come a todos.");
    Pelicula* p5=new Pelicula("Harry Potter","El peluca sabeeeeee!","JARRY APURATE Q LA NEGRA NOS HACE 2X1");
    Pelicula* p6=new Pelicula("Hola","Chau","¿Cómo andas?");
    mp->agregarPelicula(p1);
    mp->agregarPelicula(p2);
    mp->agregarPelicula(p3);
    mp->agregarPelicula(p4);
    mp->agregarPelicula(p5);
    mp->agregarPelicula(p6);
    mp->agregarPelicula(p7);
}

void ControladorPelicula::SetearCinesPeliculas(){
    ManejadorCine* mc = ManejadorCine::getInstancia();
    ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
    map<string,Pelicula*> pelis;
    pelis = mp->obtenerPelis();
    map<int,Cine*> cines = mc->getCines();
    for(map<int,Cine*>::iterator i=cines.begin(); i!=cines.end(); ++i){
      for(map<string,Pelicula*>::iterator u=pelis.begin(); u!=pelis.end(); u++)
        u->second->agregarCine(i->second);
    }
}
map<string,DtPelicula*> ControladorPelicula::listarPeliculas(){
  ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
  return mp->listaPeliculas();
}

list<string> ControladorPelicula::listaTitulosPeliculas(){
    ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
    return mp->getTitulos();
}

map<int,DtSala*> ControladorPelicula::seleccionarCine(int idCine){
    ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
    ManejadorCine* mc=ManejadorCine::getInstancia();
    Pelicula* p=mp->obtenerPelicula(this->titulo);
    map<int,DtSala*> auxDt;
    Cine* cine=mc->obtenerCine(idCine);
    this->idCine=idCine;
    if(cine!=NULL){
        auxDt = cine->obtenerDtSala();
        cout<<"Entra.. "<<auxDt.size()<<endl;
    }
    return auxDt;
}

DtPeliculaInfo* ControladorPelicula::seleccionarPelicula(string titulo){
  ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
  if(mp->obtenerPelicula(titulo)!=NULL){
    string sinopsis=mp->obtenerPelicula(titulo)->getSinopsis();
    string poster=mp->obtenerPelicula(titulo)->getPoster();
    DtPeliculaInfo* dtp=new DtPeliculaInfo(sinopsis,poster);
    return dtp;
  }else{
    return NULL;
  }
}

map<int,DtCine*> ControladorPelicula::listaCines(Pelicula* p){
    map<int,DtCine*> dtcines;
    map<int,Cine*> mc = p->obtenerCines();
    for (map<int,Cine*>::iterator k=mc.begin(); k!=mc.end(); ++k){
      DtCine* dtc = new DtCine(k->second->getIdCine(),k->second->getDireccion());
      dtcines.insert(std::pair<int,DtCine*>(dtc->getIdCine(),dtc));
    }
    return dtcines;
}

DtCine* ControladorPelicula::CrearDt(Cine* c){
    DtCine* dtc = new DtCine(c->getIdCine(),c->getDireccion());
    return dtc;
  };

map<int,DtCine*> ControladorPelicula::seleccionarPeliculaCine(string titulo){
  this->titulo=titulo;
  map<int,Cine*> cines;
  map<int,DtCine*> auxDt;
  ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
  Pelicula* p = mp->obtenerPelicula(titulo);
  cines = p->obtenerCines();
  for (map<int,Cine*>::iterator it=cines.begin(); it!=cines.end(); ++it){
      DtCine* dtc = new DtCine(it->second->getIdCine(),it->second->getDireccion());
      auxDt.insert(std::pair<int,DtCine*>(dtc->getIdCine(),dtc));
    }
  return auxDt;

}

list <DtPeliculaPoster*> ControladorPelicula::obtenerDtPeliculaPoster(){
    ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
    return mp->getListaDtPeliculaPoster();
}

void ControladorPelicula::seleccionarSala(int idSala){
    this->idSala=idSala;
}

void ControladorPelicula:: altaFuncion(FechaHora f){
  ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
  ManejadorCine* mc=ManejadorCine::getInstancia();
  ManejadorFuncion* mf=ManejadorFuncion::getInstancia();
  Pelicula* p = mp->obtenerPelicula(this->titulo);
  Cine* c = mc->obtenerCine(this->idCine);
  Sala* s = c->obtenerSala(idSala);
  if(s==NULL){
    cout<<"No se encontro la sala "<<endl;
  }else{
      Funcion* fun = new Funcion(f, p);
      s->agregarFuncion(fun);
      mf->agregarFuncion(fun);
      /*
      map<int,Funcion*> ColeccionFunciones=  s->obtenerFunciones();
      cout<<"id de la sala: "<<s->getIdSala()<<endl;

      cout<<"funciones :"<<endl;
      for(map<int,Funcion*>::iterator i=ColeccionFunciones.begin(); i!=ColeccionFunciones.end(); ++i){
          cout<<"id funcion= "<<i->second->getIdFuncion()<<endl;
          FechaHora f= i->second->getHorario();
          cout<<"a la hora "<<f.getHora()<<endl;
          cout<<"en el dia "<<f.getDia()<<endl;
      }
      */
  }
}

map<int,DtFuncion*> ControladorPelicula::seleccionarCineFuncion(int idC, string t){
  this->idCine=idC;
  this->titulo=t;
  map<int,Cine*> cines;
  map<int,Sala*> salas;
  map<int,Funcion*> funciones;
  map<int,DtFuncion*> dtfunciones;
  ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
  Pelicula* p = mp->obtenerPelicula(t);
  cines = p->obtenerCines();
  for (map<int,Cine*>::iterator i=cines.begin(); i!=cines.end(); ++i){
    salas = i->second->obtenerSalas();
    for (map<int,Sala*>::iterator u=salas.begin(); u!=salas.end(); ++u){
      funciones = u->second->obtenerFunciones();
      for (map<int,Funcion*>::iterator k=funciones.begin(); k!=funciones.end(); ++k){
        DtFuncion* dtf = new DtFuncion(k->first,k->second->getHorario());
        dtfunciones.insert(::pair<int,DtFuncion*>(dtf->getIdFuncion(),dtf));
      }
    }
  }
  return dtfunciones;
}

list<DtFuncion*> ControladorPelicula::funcionesDespuesDeFecha(int idCine,FechaHora f,string titulo){
  list<DtFuncion*> funcionesDespuesDeFecha;
  //ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
  ManejadorCine* mc=ManejadorCine::getInstancia();
  Cine* cine=mc->obtenerCine(idCine);
  map<int,Sala*> salas;
  salas=cine->obtenerSalas();
  map<int,Funcion*> funciones;
  for(map<int,Sala*>::iterator i=salas.begin(); i!=salas.end(); ++i){
      funciones = i->second->obtenerFunciones();
        for(map<int,Funcion*>::iterator y=funciones.begin(); y!=funciones.end(); ++y){
            string titu;
            Funcion* funci;
            FechaHora fechaFuncion;
            funci=y->second;
            fechaFuncion=funci->getHorario();
            titu=funci->getTituloPelicula();
            bool agregar=false;
            if(titulo==titu){
                  if(fechaFuncion.getAnio()>f.getAnio()){
                    agregar=true;
                  }else if((fechaFuncion.getAnio()==f.getAnio()) and (fechaFuncion.getMes()>f.getMes())){
                    agregar=true;
                  }else if((fechaFuncion.getMes()==f.getMes()) and (fechaFuncion.getDia()>f.getDia()) and (fechaFuncion.getAnio()==f.getAnio())){
                      agregar=true;
                  }else if( (fechaFuncion.getAnio()==f.getAnio()) and (fechaFuncion.getDia()==f.getDia()) and (fechaFuncion.getHora()>f.getHora()) and (fechaFuncion.getMes()==f.getMes())){
                        agregar=true;
                      agregar=true;
                  }
            if(agregar==true){
              DtFuncion* dtf= new DtFuncion(y->second->getIdFuncion(),y->second->getHorario());
              funcionesDespuesDeFecha.push_back(dtf);
            }
          }
        }
    }
      return funcionesDespuesDeFecha;
}

void ControladorPelicula::seleccionarPeliculaTitulo(string titulo){
  this->titulo=titulo;
}

void ControladorPelicula::eliminarPelicula(){
    ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
    Pelicula* p = mp->obtenerPelicula(this->titulo);
    p->eliminarFunciones(this->titulo);
    p->eliminarComentariosPuntajes();
    mp->borrarPelicula(this->titulo);
    delete p;
}

float ControladorPelicula::mostrarPrecio(TipoPago tp, int asientos, string nombreBF){
    float precio=0,desc;
    int precioAsiento=700;
    precio = (asientos)*(precioAsiento);
    if (tp == debito){
        precio = (asientos)*(precioAsiento);
        return precio;
    }else{
        for(list<Financiera*>::iterator w=financieras.begin(); w!=financieras.end(); ++w){
            if ((*w)->getNombre() == nombreBF){
                desc = ((precio)*((*w)->getDescuento()))/100;
                precio = precio - desc;
                cout<<"Descuento en ICP: "<< desc<<"\nPrecio en ICP: "<<precio<<endl;
                return precio;
            }
        }
    }
}

void ControladorPelicula::cargarFinancieras(){
    string o = "OCA";
    string i = "ITAU";
    string b = "BBVA";

    float d1 = 15.05;
    float d2 = 25.08;
    float d3 = 0.1;

    Financiera* f1 = new Financiera(o,d1);
    Financiera* f2 = new Financiera(i,d2);
    Financiera* f3 = new Financiera(b,d3);

    financieras.push_back(f1);
    financieras.push_back(f2);
    financieras.push_back(f3);
}

float ControladorPelicula::obtenerDescuento(string f){
    for(list<Financiera*>::iterator p=this->financieras.begin(); p!=this->financieras.end(); ++p){
        if(p!=financieras.end()){
            if ((*p)->getNombre() == f)
                return (*p)->getDescuento();
        }else
            return 0;
    }
}
void ControladorPelicula::crearReserva(TipoPago pago,int cantEntradas,float pTotal,string entidad){
    ManejadorCine* mc= ManejadorCine::getInstancia();
    ManejadorUsuario* mu=ManejadorUsuario::getInstancia();
    ManejadorFuncion* mf=ManejadorFuncion::getInstancia();
    Funcion* f=mf->obtenerFuncion(idFuncion);
    Sesion* s=Sesion::getInstancia();
    Usuario* u=mu->obtenerUsuario(s->getNickname());
    Cine* c= mc->obtenerCine(idCine);
    if(pago==debito){
        Debito* deb= new Debito(cantEntradas,pTotal,entidad);
        deb->agregarUsuario(u);
        f->crearReserva(deb);
    }else{
        Credito* cre= new Credito(entidad,cantEntradas,pTotal);
        cre->agregarUsuario(u);
        f->crearReserva(cre);
    }
}
void ControladorPelicula::seleccionarFuncion(int idf){
    idFuncion=idf;
}
