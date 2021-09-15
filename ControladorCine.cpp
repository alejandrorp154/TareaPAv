#include "ControladorCine.h"

ControladorCine::ControladorCine(){}
ControladorCine::~ControladorCine(){}

void ControladorCine::cargarCines(){
    ManejadorCine* mc = ManejadorCine::getInstancia();
    ManejadorFuncion* mf= ManejadorFuncion::getInstancia();
    Cine* c1 = new Cine("AVITALIA 5775");
    Cine* c2 = new Cine("ROOSVELT y P7");
    Cine* c3 = new Cine("JAPON");
    Cine* c4 = new Cine("CHINA");
    Cine* c5 = new Cine("EL CINE DE MANECO");
    mc->agregarCine(c1);
    mc->agregarCine(c2);
    mc->agregarCine(c3);
    //mc->agregarCine(c4);
    //mc->agregarCine(c5);
    //idSala, Capcidad Sala
    Sala* s0 = new Sala(100);
    Sala* s1 = new Sala(300);
    Sala* s2 = new Sala(400);
    Sala* s3 = new Sala(300);
    Sala* s4 = new Sala(800);
    Sala* s5 = new Sala(1000);
    Sala* s6 = new Sala(3000);
    Sala* s7 = new Sala(2000);
    // SALAS CINE 1
    c1->agregarSalaCine(s0);
    c1->agregarSalaCine(s1);
    c1->agregarSalaCine(s3);
    // SALAS CINE 2
    c2->agregarSalaCine(s4);
    c2->agregarSalaCine(s2);

    // SALAS CINE 3
    c3->agregarSalaCine(s5);
    c3->agregarSalaCine(s6);
    c3->agregarSalaCine(s7);
    // SALAS CINE 4
    // SALAS CINE 5

    FechaHora fecha1 = FechaHora(14,6,2018,16,40);
    FechaHora fecha2 = FechaHora(15,6,2018,17,35);
    FechaHora fecha4 = FechaHora(18,6,2018,20,10);
    FechaHora fecha3 = FechaHora(17,6,2018,19,20);
    FechaHora fecha5 = FechaHora(19,6,2018,21,05);
    FechaHora fecha6 = FechaHora(16,6,2018,18,30);

    // cargar Funciones para pelicula Hola en las salas de los distintos cines
    ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
    Pelicula* p = mp->obtenerPelicula("Hola");
    Funcion* f0 = new Funcion(fecha1,p);
    Funcion* f1 = new Funcion(fecha2,p);
    Funcion* f2 = new Funcion(fecha3,p);
    Funcion* f3 = new Funcion(fecha4,p);
    Funcion* f4 = new Funcion(fecha5,p);
    Funcion* f5 = new Funcion(fecha6,p);


    s0->agregarFuncion(f0);
    s0->agregarFuncion(f1);
    s0->agregarFuncion(f2);
    s1->agregarFuncion(f3);
    s2->agregarFuncion(f4);
    s3->agregarFuncion(f5);

    mf->agregarFuncion(f0);
    mf->agregarFuncion(f1);
    mf->agregarFuncion(f2);
    mf->agregarFuncion(f3);
    mf->agregarFuncion(f4);
    mf->agregarFuncion(f5);

/*
    map<int,Sala*> salas;
    map<int,Funcion*> funciones;
    salas = c1->obtenerSalas();
    for(map<int,Sala*>::iterator i=salas.begin(); i!=salas.end(); ++i){
      funciones = i->second->obtenerFunciones();
      for(map<int,Funcion*>::iterator y=funciones.begin(); y!=funciones.end(); ++y){
        cout << y->first << " funcion " << endl;
      }
    }


    //mostrar CINES y SALAS

    map<int,Cine*> cine2;

    cine2 = mc->getCines();
    for(map<int,Cine*>::iterator i=cine2.begin(); i!=cine2.end(); ++i){
      salas = i->second->obtenerSalas();
      cout << "CINE: " << i->first << endl <<"DIRECCION: " << i->second->getDireccion()<<endl;

          //cout << salas.size();
      for(map<int,Sala*>::iterator u=salas.begin(); u!=salas.end(); ++u){
        cout<< "SALA: " << u->first << " CAPACIDAD: " << u->second->getCapacidad() << endl;
      }
    }
*/
}

void ControladorCine::ingresarDirecionCine(string direccion){
    dirCine=direccion;
}
DtCine* ControladorCine::altaCine(){
    Cine* c= new Cine(dirCine);
    DtCine* dtc= new DtCine(c->getIdCine(),dirCine);
    ManejadorCine* mc=ManejadorCine::getInstancia();
    mc->agregarCine(c);
    return dtc;
}
void ControladorCine::agregarSala(DtSala* dts, int idCine){
    ManejadorCine* mc=ManejadorCine::getInstancia();
    Cine* c= mc->obtenerCine(idCine);
    c->agregarSala(dts);
}

list<DtSala*> ControladorCine::getSalas(int idCine){
    list<DtSala*> listaDtSalas;
    ManejadorCine* mc=ManejadorCine::getInstancia();
    Cine* c=mc->obtenerCine(idCine);
    map<int,Sala*> salasObtenidas=c->obtenerSalas();
    for (map<int,Sala*>::iterator it=salasObtenidas.begin(); it!=salasObtenidas.end(); ++it){
        DtSala* dts= new DtSala(it->second->getIdSala(), it->second->getCapacidad());
        listaDtSalas.push_back(dts);
    }
    return listaDtSalas;
}
list<DtFuncion*> ControladorCine::getFuncionesSala(int idSala, int idCine){
    list<DtFuncion*> listaFunciones;
    ManejadorCine* mc=ManejadorCine::getInstancia();
    Cine* c=mc->obtenerCine(idCine);
    Sala* s=c->obtenerSala(idSala);
    map<int,Funcion*> funciones=s->obtenerFunciones();
    for(map<int,Funcion*>::iterator it=funciones.begin();it!=funciones.end();++it){
        DtFuncion* dtf= new DtFuncion(it->first,it->second->getHorario());
        listaFunciones.push_back(dtf);
    }
    return listaFunciones;
}
