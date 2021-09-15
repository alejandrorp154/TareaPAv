#ifndef CONTROLADORPELICULA_H
#define CONTROLADORPELICULA_H

#include <iostream>
#include <list>
#include <map>

#include "Pelicula.h"
#include "Cine.h"
#include "Sala.h"
#include "FechaHora.h"
#include "Sesion.h"
#include "Funcion.h"

#include "DtPelicula.h"
#include "DtPeliculaInfo.h"
#include "DtPeliculaPoster.h"
#include "Financiera.h"
#include "TipoPago.h"
#include "Debito.h"
#include "Credito.h"

#include "IControladorPelicula.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorFuncion.h"
#include "ManejadorUsuario.h"

using namespace std;

class ControladorPelicula : public IControladorPelicula{
    private:
        string titulo;
        int idCine;
        int idSala;
        int idFuncion;
        list<Financiera*> financieras;
    public:
        ControladorPelicula();
        ~ControladorPelicula();
        // Operaciones
        void cargarFinancieras();
        void cargarPeliculas();
        void SetearCinesPeliculas();
        map<string,DtPelicula*> listarPeliculas();
      // void seleccionarPelicula(string titulo);
        map<int,DtSala*> seleccionarCine(int);
        //list<string> listaTitulosPeliculas();
        DtPeliculaInfo* seleccionarPelicula(string);
        map<int,DtCine*> seleccionarPeliculaCine(string);
        DtCine* CrearDt(Cine*);
      //  map<string,DtPeliculaInfo*> seleccionarPelicula(string titulo);
        map<int,DtCine*> listaCines(Pelicula*);
        map<int,DtFuncion*> seleccionarCineFuncion(int,string);
        list<string> listaTitulosPeliculas();
        list<string> listaComentarios();
        void responderComentario(int, string);
        void crearComentario(string);
        list <DtPeliculaPoster*> obtenerDtPeliculaPoster();
        void seleccionarSala(int);
        void altaFuncion(FechaHora);
        list<DtFuncion*> funcionesDespuesDeFecha(int,FechaHora,string);
        void seleccionarPeliculaTitulo(string);
        void eliminarPelicula();
        float mostrarPrecio(TipoPago,int,string);
        float obtenerDescuento(string);
        //void verPrecioTotal();
        void crearReserva(TipoPago,int,float,string);
        void seleccionarFuncion(int);
};
#endif
