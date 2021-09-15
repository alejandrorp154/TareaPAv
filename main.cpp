// #include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <stdio.h>
#include <time.h>
#include <list>
#include <map>

#include "Factory.h"
#include "IControladorUsuario.h"
#include "IControladorCine.h"
#include "IControladorPelicula.h"
#include "IControladorPuntajeComentario.h"

#include "DtUsuario.h"
#include "DtCine.h"
#include "DtSala.h"
#include "DtComentario.h"
#include "DtCredito.h"
#include "DtDebito.h"
#include "DtFuncion.h"
#include "DtFuncionHorario.h"
#include "DtPelicula.h"
#include "DtPeliculaInfo.h"
#include "DtPeliculaPoster.h"
#include "DtPeliculaTitulo.h"
#include "DtPeliculaPuntajeComentario.h"
#include "DtPeliculaTitulo.h"
#include "DtReserva.h"
#include "TipoPago.h"
#include "FechaHora.h"
#include "DtPuntaje.h"
#include "ManejadorUsuario.h"
#include "ManejadorCine.h"
#include "ManejadorPelicula.h"
#include "Reloj.h"

using namespace std;

Factory* Factory;
IControladorUsuario* ICU=Factory->getIControladorUsuario();
IControladorCine* ICC=Factory->getIControladorCine();
IControladorPelicula* ICP=Factory->getIControladorPelicula();
IControladorPuntajeComentario* ICPC=Factory->getIControladorPuntajeComentario();
Reloj* Reloj=Reloj::getInstancia();

void mostrarPelicula(){
    list<string> listaTitulos;
    listaTitulos=ICP->listaTitulosPeliculas();
    cout<<"Titulos de las peliculas: "<<endl;
    for(list<string>::iterator it=listaTitulos.begin();it!=listaTitulos.end();++it){
      //cout<<*it<<endl;
      cout << "=============================" <<
      endl << "=                           =" <<
      endl << "  " << *it <<
      endl << "=                           =" <<
      endl << "============================="<<
      endl;
      cout << endl;
    }
}

void mostrarSalas(int idCine){
    list<DtSala*> listaDtSalas=ICC->getSalas(idCine);
    for (list<DtSala*>::iterator it=listaDtSalas.begin(); it!=listaDtSalas.end(); ++it){
        cout<<"--------------------------------"<<endl;
        cout<<"Sala: "<<(*it)->getIdSala()<<endl;
        cout<<"Capacidad: "<<(*it)->getCapacidad()<<endl;
        list<DtFuncion*> listaFunciones=ICC->getFuncionesSala((*it)->getIdSala(),idCine);
        for (list<DtFuncion*>::iterator it=listaFunciones.begin();it!=listaFunciones.end();++it){
          cout<<endl<<"Funcion: "<<(*it)->getIdFuncion()<<endl;
          cout<<(*it)->getHorario();
        }
    }
}

void mostrarCine(map<int,DtCine*> cines){
     for (map<int, DtCine*>::iterator it=cines.begin(); it!=cines.end(); ++it){
        cout << "Cine: " << it->second->getIdCine() << endl;
        cout << "Direccion: " <<  it->second->getDireccion() << endl;
     }
}

void mostrarDtPeliculaPoster(){
    list<DtPeliculaPoster*> listaDt;
    listaDt = ICP->obtenerDtPeliculaPoster();
    for (list<DtPeliculaPoster*>::iterator it=listaDt.begin(); it!=listaDt.end(); ++it){
        cout<<">____________________________________________________________<"<<endl;
        cout<<"->Titulo: "<<(*it)->getTitulo()<<endl;
        cout<<"->Poster: "<<(*it)->getPoster()<<endl;
        cout<<">____________________________________________________________<"<<endl;
    }
}

void mostrarPosterSinopsis(string titulo){
    map<string,DtPelicula*> pelis;
    pelis = ICP->listarPeliculas();
    map<string,DtPelicula*>::iterator it=pelis.find(titulo);
    cout<<">____________________________________________________________<"<<endl;
    cout<<"->Poster: "<< it->second->getPoster()<<endl;
    cout<<"->Sinopsis: "<< it->second->getSinopsis()<<endl;
    cout<<">____________________________________________________________<"<<endl;
}


void imprimirComentarios(DtComentario* dtc ,int tab){
    for(int i=0;i<tab;i++){
        cout<<"\t";
    }
    cout<<dtc->getNickname() <<": "<<"<"<<dtc->getIdComentario()<<">"<<dtc->getTexto()<<endl;
    list<DtComentario*> listaresp=dtc->obtenerRespuestas();
    if(!listaresp.empty()){
        for(list<DtComentario*>::iterator it=listaresp.begin();it!=listaresp.end();++it){
            imprimirComentarios((*it),tab+1);
        }
    }
}
void imprimirComentariosYPuntajes(DtPeliculaPuntajeComentario* dt){
    cout<<"<"<<dt->getTitulo()<<">"<<endl;
    cout<<"Puntaje promedio: "<<"<"<<dt->getPuntajePromedio()<<">";
    list<DtPuntaje*> listaDtPuntaje=dt->obtenerPuntajes();
    cout << " (" << listaDtPuntaje.size() << " usuarios)" << endl;

    cout<<"Comentarios:"<<endl;
    list<DtComentario*>listaDtComentario=dt->obtenerComentarios();
    for(list<DtComentario*>::iterator it=listaDtComentario.begin();it!=listaDtComentario.end();++it){
        if(!listaDtComentario.empty())
            imprimirComentarios((*it),0);
    }
    cout<< endl <<"Puntajes:"<<endl;
    for(list<DtPuntaje*>::iterator it=listaDtPuntaje.begin();it!=listaDtPuntaje.end();++it){
        cout<<(*it)->getNickname()<<": "<<(*it)->getPuntos()<<endl;
    }
}

int mostrarFunciones(int idC, string t){
    FechaHora f = Reloj->obtenerFecha();
    list<DtFuncion*> listafunciones = ICP->funcionesDespuesDeFecha(idC,f,t);
    if (listafunciones.size() == 0)
      cout << "Proximamente...\n\nNo hay funciones disponibles a la fecha de esta película." << endl;
    else{
      cout << "¡Funciones disponibles para tu pelicula!" << endl;
      for(list<DtFuncion*>::iterator i=listafunciones.begin(); i!=listafunciones.end(); ++i){
        cout << "Función: " << (*i)->getIdFuncion() << endl;
        FechaHora fh = (*i)->getHorario();
        cout << fh << endl;
      }
    }
  return listafunciones.size();
}

void menu();

int main(){
    //Reloj->modificarFecha(01,01,1991,15,15);
    ICU->cargarUsuarios();
    ICP->cargarPeliculas();
    ICC->cargarCines();
    ICP->SetearCinesPeliculas();
    ICPC->cargarPuntajeComentario();
    ICP->cargarFinancieras();
    menu();
  return 0;
}

void menu(){
    /*cout<< "\t\tBIENVENIDO A DISNEY PICTURES ENTERTAINMENT CINEMA"<<endl<<"\t\t---------------------------------------------"<<endl;
    sleep(2);
    system("clear");
    cout<< "TARARAAAAA TA TARAAA TARARAAAA TA TARA TATARARARAAAAAAAAAAAAAAAAAAAAAA TATATATAAAAAAAAAAAAAAAAAA"<<endl;
    sleep(2);
    system("clear");
    cout<< "By: Alejandro Rodriguez"<<endl;
    sleep(1);
    cout<<"Gaston Lopez"<<endl;
    sleep(1);
    cout<<"Walt Disney (congelado)"<<endl;
    sleep(1);
    cout<<"Javier Mata"<<endl;
    sleep(1);
    cout<<"Mathias Fernandez"<<endl;
    sleep(1);
    cout<<"Ignacio Rasetti"<<endl;
    system("clear");
    cout<< "\t\tBIENVENIDO A DISNEY PICTURES ENTERTAINMENT CINEMA"<<endl<<"\t\t---------------------------------------------"<<endl<<endl<<endl;*/
    bool salir=false,usuarioValido;
    bool sesionAbierta=false;
    int p=0;
    ManejadorUsuario* mu=ManejadorUsuario::getInstancia();
    ManejadorCine* mc=ManejadorCine::getInstancia();
    DtUsuario* dtu;
    DtCine* dtc;
    DtSala* dts;
    string nickname;
    string password;
    string direccion;
    string reintentar;
    string quiereSala;
    string optagregar;
    string titulo;
    string modificar;
    bool valida;
    int opcion;
    int capAsientos;
    int contadorSalas;
    cout << endl << "\t\tBIENVENIDO A DISNEY PICTURES ENTERTAINMENT CINEMA"<<endl<<"\t\t-------------------------------------------------"<<endl<<endl<<endl;
    while(!salir){
        cout << "___________________________________________ " << endl;
        cout << "|1) Iniciar sesion                         |" << endl;
        cout << "|2) Alta cine                              |" << endl;
        cout << "|3) Alta funcion                           |" << endl;
        cout << "|4) Crear reserva                          |" << endl;
        cout << "|5) Puntuar pelicula                       |" << endl;
        cout << "|6) Comentar pelicula                      |" << endl;
        cout << "|7) Eliminar pelicula                      |" << endl;
        cout << "|8) Ver informacion de pelicula            |" << endl;
        cout << "|9) Ver comentarios y puntajes de pelicula |" << endl;
        cout << "|10) Modificar Fecha Hora del sistema      |" << endl;
        cout << "|11) Consultar Fecha Hora del sistema      |" << endl;
        cout << "|0) Salir                                  |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "Choose your Destiny: ";
        cin >> opcion;
        switch (opcion){
            case 1:{ //Iniciar sesion
                cout << "Ingresar nickname: ";
                cin >> nickname;
                usuarioValido=ICU->ingresarNickname(nickname);
                while(!usuarioValido){
                    cout<<"Nickname incorrecto, ingreselo nuevamente: "<<endl;
                    cin>>nickname;
                    usuarioValido=ICU->ingresarNickname(nickname);
                }
                do{
                  cout << "Ingresar password: ";
                  cin >> password;
                  if(!ICU->ingresarPassword(password)){
                    cout << "Contraseña Erronea. ¿Quiere intentar nuevamente?: [S/N]";
                    cin>>reintentar;
                  }
                }while((!ICU->ingresarPassword(password))&&(reintentar=="S"||reintentar=="s"));
                if(ICU->ingresarPassword(password)){
                    ICU->iniciarSesion();
                    sesionAbierta=true;
                }
            break;
            }
            case 2:{ //Alta cine
                if(sesionAbierta){
                  if (ICU->esAdmin()){
                    cout<<"Es administrador..."<<endl;
                    cout << "Ingrese direccion: ";
                    getline (cin >> ws, direccion);
                    ICC->ingresarDirecionCine(direccion);
                    quiereSala="S";
                    list<DtSala*> auxSalas;
                    while(quiereSala=="S"||quiereSala=="s"){
                        cout<<"Para ingresar una sala:"<<endl;
                        cout<<"Ingrese la capacidad de asientos de la sala: ";
                        cin>>capAsientos;
                        dts=new DtSala(5,capAsientos);
                        auxSalas.push_back(dts);
                        cout<<"¿Quiere agregar otra sala?[S/N]: ";
                        cin>>quiereSala;
                    }
                    cout<<"¿Desea agregar el cine?[S/N]: ";
                    cin>>optagregar;
                    if(optagregar=="S" or optagregar=="s"){
                        dtc= ICC->altaCine();
                        for(list<DtSala*>::iterator it=auxSalas.begin();it!=auxSalas.end();++it){
                            ICC->agregarSala((*it),dtc->getIdCine());
                        }
                    }
                    auxSalas.clear();
                  }else{
                    cout<<"lo sentimos usted no es administrador"<<endl;
                  }
                }
                else{
                    cout<<"No hay sesion iniciada"<<endl;
                }
            break;
            }
            case 3:{ //Alta funcion
              if(sesionAbierta){//HAY QUE FIJARSE SI EL LOCO ES ADMINISTRADOR TAMBIEN
                if (ICU->esAdmin()){
                    cout<<"Es administrador.."<<endl;
    //listarPeliculas
                    mostrarPelicula();
    //seleccionarPelicula
                    cout << "Selecciona la pelicula que desea agregar una funcion: ";
                    string titulo;
                    getline(cin >> ws ,titulo);
                    map<int,DtCine*> cines;
                    DtPeliculaInfo* dtp2=ICP->seleccionarPelicula(titulo);
                      if(dtp2!=NULL){
                    cines = ICP->seleccionarPeliculaCine(titulo);
                    mostrarCine(cines);
    //seleccionarCine
                    int idCine;
                    cout << endl << "Selecciona el cine que deseas agregar una funcion: ";
                    cin >> idCine;
                    map<int,DtSala*> salas;
                    salas = ICP->seleccionarCine(idCine);
                    if(salas.size()!=0){
                        mostrarSalas(idCine);
//seleccionarSala
                        int idSala, dia, mes, anio, hora, minutos;
                        string opcion="s";
                        while(opcion=="S"||opcion=="s"){
                            cout << endl << "Selecciona la sala que deseas agregar una funcion: " ;
                            cin >> idSala;
                            ICP->seleccionarSala(idSala);
                            cout << "Ingresa dia: ";
                            cin >> dia;
                            cout << "Ingresa mes: ";
                            cin >> mes;
                            cout << "Ingresa año: ";
                            cin >> anio;
                            cout << "Ingresa hora: ";
                            cin >> hora;
                            cout << "Ingresa minutos: ";
                            cin >> minutos;
                            FechaHora f = FechaHora(dia, mes, anio, hora, minutos);
                            ICP->altaFuncion(f);
                            cout<<"¿Quiere agregar otra funcion? [S/N]: ";
                            cin >> opcion;
                        }
                    }else{
                        cout<<"No existe cine con ese id"<<endl;
                    }
                  }else{
                    cout<<"Titulo incorrecto"<<endl;
                  }
                  }else{
                    cout<<"Lo sentimos, usted no es administrador"<<endl;
                  }
                }
                else{
                    cout<<"No hay sesion iniciada"<<endl;
                }
                break;
            }
            case 4:{ //Crear reserva
              if(sesionAbierta){
                bool exit=false;
                string adicional,nuevo;
                int idCine;
                int hayFunciones;
                map<int,DtCine*> cines;
                map<int,DtFuncion*> funciones;
                bool continua = false;
                bool confirma = false;
                while (!exit){//MIENTRAS QUIERA SELECCIONAR OTRA PELICULA
                    cout << "Cartelera de peliculas:" << endl;
                    mostrarPelicula();
                    cout << "Seleccione la pelicula a la que desea reservar asientos. Para salir [0]: ";
                    string titulo;
                    getline(cin >> ws, titulo);
                    DtPeliculaInfo* dtp3=ICP->seleccionarPelicula(titulo);
                      if(dtp3!=NULL or titulo=="0"){
                      if (titulo != "0"){
                    //aca estoy ASDJKNASKJFASDN
                    ICP->seleccionarPeliculaTitulo(titulo);

                        mostrarPosterSinopsis(titulo);
                        cout << endl << "Presione [M] para informacion adicional. Para salir [0]: ";
                        cin >> adicional;
                        if (adicional == "M" || adicional=="m"){
                            cout << "Cines disponibles para la pelicula " << titulo << endl;
                            cines = ICP->seleccionarPeliculaCine(titulo);
                            mostrarCine(cines);
                            cout << endl << "Elija el cine de su preferencia. Para salir [0]: ";
                            cin >> idCine;
                            if (idCine != 0){
                                funciones = ICP->seleccionarCineFuncion(idCine,titulo);
                                hayFunciones = mostrarFunciones(idCine,titulo);
                                if (hayFunciones != 0){
                                  cout << "Para continuar con la reserva de la pelicula seleccionada ingrese [1] (Para anularla y realizar otra [0]): ";
                                  cin >> continua;
                                  if(continua)
                                      exit=true;
                                }else if (hayFunciones == 0 and !continua){
                                  cout << "Para realizar otra reserva ingrese 0: ";
                                  cin >> continua;
                                }
                          }else{//NO QUIERE CINE
                              cout << "Hasta la próxima." << endl;
                              continua=false;
                              exit = true;
                            }
                        }else{//NO QUIERE VER INFO ADICIONAL
                        cout << "Hasta la próxima." << endl;
                        continua=false;
                        exit = true;
                      }
                  }else{ //SALIR TITULO
                      cout << "Hasta la próxima." << endl;
                      continua=false;
                      exit = true;
                    }

                  }else{
                    cout << "titulo incorrecto" << endl;
                    continua=false;
                    exit = true;
                  }
                    //asdasdasdasdas
                }
                if (hayFunciones != 0 and continua){
                  int idFuncion, cantEntradas,descuento=0;
                  TipoPago pago;
                  float pTotal;
                  string entidad, p;
                  cout << "Ingrese la función deseada: ";
                  cin >> idFuncion;
                  ICP->seleccionarFuncion(idFuncion);
                  cout << endl << "¿Cuántos asientos quiere reservar? ";
                  cin >> cantEntradas;
                  cout << endl << "¿Cómo desea pagar su reserva? \n1 Débito \n0 Crédito\n-> ";
                  cin >> p;
                  if (p == "1")
                    pago=debito;
                  else if (p == "0")
                    pago=credito;
                  if (pago == debito){
                    cout << endl << "Ingrese el nombre del banco de su tarjeta de debito: ";
                    getline(cin>> ws,entidad);
                    pTotal = ICP->mostrarPrecio(pago,cantEntradas,entidad);
                    cout << "El precio es: " << pTotal << endl;
                  }else if (pago == credito){
                    cout << endl << "Ingrese el nombre de la financiera de su tarjeta de credito: ";
                    cin >> entidad;
                    pTotal = ICP->mostrarPrecio(pago,cantEntradas,entidad);
                    cout << endl << "Usted obtiene un descuento del " << ICP->obtenerDescuento(entidad) << "%" << endl;
                  }
                  cout<<"Precio total: "<<pTotal<<endl;
                  cout << "Para confirmar su compra ingrese 1, para cancelar ingrese 0." << endl;
                  cin >> confirma;
                  if (confirma){
                    ICP->crearReserva(pago,cantEntradas,pTotal,entidad);
                    cout << "Reserva creada, disfrute su película.";
                  }
                }else if (confirma)
                    cout<<"Hasta la próxima."<<endl;

              }else
                cout<<"No hay sesion iniciada."<<endl;
            break;
            }
            case 5:{ //Puntuar pelicula
                if(sesionAbierta){
                    string modificar;
                    float punt;
                    mostrarPelicula();
                    cout << endl << "Selecciona la pelicula que desea puntuar: ";
                    string titulo;
                    getline(cin >> ws ,titulo);
                    bool puntuo;
                    DtPeliculaInfo* dtp=ICP->seleccionarPelicula(titulo);
                    if(dtp!=NULL){
                        puntuo=ICPC->seleccionarPeliculaPuntaje(titulo);

                        if (puntuo==true){
                            cout << "Tu puntaje es: " << ICPC->verPuntajeUsuario(titulo)<<endl;
                            cout << "Desea modificar su puntaje? [S/N]: ";
                            cin >> modificar;
                            if(modificar=="S"||modificar=="s"){
                                cout<< "Ingrese puntaje: ";
                                cin >> punt;
                                ICPC->ingresarPuntaje(puntuo,punt);
                            }
                        }
                        else{
                            cout<< "Ingrese puntaje: ";
                            cin >> punt;
                            ICPC->ingresarPuntaje(puntuo,punt);
                        }
                        cout << endl;
                    }else{
                        cout<<"No existe película con ese título en el sistema"<<endl;
                    }
              }else{
                  cout<<"No hay sesion iniciada"<<endl;
              }
                break;
            }
            case 6:{ //Comentar pelicula
                if(sesionAbierta){
                mostrarPelicula();

                cout<<"Selecciona la pelicula: "<<endl;
                getline(cin>> ws,titulo);
                ICPC->seleccionarPeliculaTitulo(titulo);
                DtPeliculaInfo* dtp=ICP->seleccionarPelicula(titulo);
                if(dtp!=NULL){
                    string seguirComentando="s";
                    while(seguirComentando=="s"||seguirComentando=="S"){
                        DtPeliculaPuntajeComentario* dt = ICPC->mostrarComentariosYPuntajes();
                        imprimirComentariosYPuntajes(dt);
                        cout<<"1)Responder comentario"<<endl;
                        cout<<"2)Crear comentario "<<endl;
                        int opcion;
                        cin>>opcion;
                        if (opcion==1){
                            int idResp;
                            cout<<"¿A que texto desea responder? (Ingrese el id): ";
                            cin>>idResp;
                            string texto;
                            cout<<"Ingrese el comentario: ";
                            getline(cin>> ws,texto);
                            ICPC->crearRespuesta(texto, idResp);
                        }else{
                            string texto;
                            cout<<"Ingrese el comentario: ";
                            getline(cin>> ws,texto);
                            ICPC->crearComentario(texto);
                        }
                        cout<<"¿Desea seguir comentando?[S/N]";
                        cin>>seguirComentando;
                    }
                }else{
                    cout<<"No existe película con ese título en el sistema"<<endl;
                }
              }else{
                  cout<<"No hay sesion iniciada"<<endl;
              }
                break;
            }
            case 7:{ //Eliminar pelicula
              if(sesionAbierta){
                if (ICU->esAdmin()){
                    string titulo, eliminar;
                    mostrarPelicula();
                    cout << endl << "Selecciona la pelicula que desea eliminar del sistema: ";
                    getline(cin >> ws, titulo);
                    ICP->seleccionarPeliculaTitulo(titulo);
                    DtPeliculaInfo* dtp=ICP->seleccionarPelicula(titulo);
                    if(dtp!=NULL){
                      cout << endl << "¿De verdad desea eliminar la pelicula seleccionada? [S/N]: ";
                      cin >> eliminar;
                      if(eliminar=="S"||eliminar=="s"){
                          ICP->eliminarPelicula();
                          cout << endl << "La pelicula " << titulo << " se elimino del sistema." << endl;
                      }
                    }else{
                      cout<<"No existe película con ese título en el sistema"<<endl;
                    }
                }else{
                  cout<<"lo sentimos usted no es administrador"<<endl;
                }
              }else{
                  cout<<"No hay sesion iniciada"<<endl;
              }
                break;
            }
            case 8:{ //Ver informacion de pelicula
              //se listan las peliculas
                list<string> listaTitulos;
                listaTitulos=ICP->listaTitulosPeliculas();
                cout<<"Titulos de las peliculas: "<<endl;
                for(list<string>::iterator it=listaTitulos.begin();it!=listaTitulos.end();++it){
                    cout<<(*it)<<endl;
                }
                string cancelar="s";
                cout<<"¿Desea cancelar?[S/N]: ";
                cin>>cancelar;
                while(cancelar!="s"){
                    fflush(stdin);
                    string titulo;
                    cout<<"Elija un titulo: ";
                    getline(cin >> ws ,titulo);
                    //cin>>titulo;
                    DtPeliculaInfo* dtp=ICP->seleccionarPelicula(titulo);
                    if(dtp!=NULL){
                        cout<<"Poster: "<<dtp->getPoster()<<endl;
                        cout<<"Sinopsis: "<<dtp->getSinopsis()<<endl;
                        cout<<"¿Ver Informacion Adicional?[S/N]: ";
                        cin>>cancelar;
                        if (cancelar=="s"||cancelar=="S"){
                            cout<<"\tInformacion adicional"<<endl;
                            map<int,DtCine*> cines;
                            cines = ICP->seleccionarPeliculaCine(titulo);
                            cout << "La pelicula esta disponible en los siguientes cines:"<<endl;
                            for (map<int,DtCine*>::iterator i=cines.begin(); i!=cines.end(); ++i){
                                cout << "CINE: " << i->first <<endl;
                                cout << "DIRECCION: " << i->second->getDireccion() <<endl;
                            }
                            cout<< endl << "¿Ver Informacion Adicional?[S/N]: ";
                              cin>>cancelar;
                              if (cancelar=="s"||cancelar=="S"){
                            int idCine;
                            cout<<"Elija un cine: ";
                            cin>>idCine;
                            map<int,DtSala*> salas;
                            salas = ICP->seleccionarCine(idCine);
                            FechaHora f= ICU->ConsultarFechaHoraSistema();
                            list<DtFuncion*> funcionesDespuesDeFecha;
                            funcionesDespuesDeFecha=ICP->funcionesDespuesDeFecha(idCine,f,titulo);
                            for(list<DtFuncion*>::iterator it=funcionesDespuesDeFecha.begin();it!=funcionesDespuesDeFecha.end();++it){
                                cout<<"--------------------------------------------------"<<endl;
                                cout<<"id Funcion: "<<(*it)->getIdFuncion()<<endl;
                                cout<<"anio :"<<(*it)->getHorario().getAnio()<<endl;
                                cout<<"mes :"<<(*it)->getHorario().getMes()<<endl;
                                cout<<"dia:"<<(*it)->getHorario().getDia()<<endl;
                                cout<<"Hora:"<<(*it)->getHorario().getHora()<<endl;
                                cout<<"Minutos:"<<(*it)->getHorario().getMinuto()<<endl;
                                cout<<"--------------------------------------------------"<<endl;
                            }
                          }
                        }
                    }else{
                    cout<<"Titulo incorrecto..."<<endl;
                    }
                    cout<<"¿Desea cancelar?[S/N]: ";
                    getline(cin>> ws,cancelar);
                }
                break;
            }
            case 9:{ //Ver comentarios y puntajes de pelicula
                mostrarDtPeliculaPoster();
                cout<<"Seleccione el titulo de la pelicula: ";
                getline(cin>> ws,titulo);
                cout << endl;
                ICPC->seleccionarPeliculaTitulo(titulo);
                DtPeliculaPuntajeComentario* dt = ICPC->mostrarComentariosYPuntajes();
                imprimirComentariosYPuntajes(dt);
                cout << endl;
                break;
            }
            case 10:{ //Modificar FechaHora del sistema
              cout<<"Modificar Fecha hora del sistema"<< endl;
              int anio;
              cout<<"ingrese anio"<<endl;
              cin>>anio;
              int mes;
              cout<<"ingrese mes"<<endl;
              cin>>mes;
              cout<<"ingrese dia"<<endl;
              int dia;
              cin>>dia;
              cout<<"ingrese hora"<<endl;
              int hora;
              cin>>hora;
              cout<<"ingrese minutos"<<endl;
              int minutos;
              cin>>minutos;
              FechaHora f(dia,mes,anio,hora,minutos);
              ICU->ModificarFechaHoraSistema(f);
                break;
            }
            case 11:{ //Consultar FechaHora del sistema
              cout<<" Fecha y hora del sistema"<< endl;
              FechaHora f= Reloj->obtenerFecha();
              cout<<" Anio: "<<f.getAnio()<<endl;
              cout<<" Mes: "<<f.getMes()<<endl;
              cout<<" Dia: "<<f.getDia()<<endl;
              cout<<" Hora: "<<f.getHora()<<endl;
              cout<<" Minuto: "<<f.getMes()<<endl;
                break;
            }
            case 0:{ //Salir
                salir=true;
                break;
            }
            default:{
                break;
            }
        }
        if(sesionAbierta)
            cout << endl << "Bienvenido, "<<nickname<<endl<<endl;
        if(!salir)
            cout<< "\t\tBIENVENIDO A DISNEY PICTURES ENTERTAINMENT CINEMA"<<endl<<"\t\t-------------------------------------------------"<<endl<<endl<<endl;
    }
}
