#ifndef ICONTROLADORPELICULA_H
#define ICONTROLADORPELICULA_H
#include <iostream>

#include "DtCine.h"
#include "DtSala.h"
#include "Pelicula.h"
#include "DtPeliculaInfo.h"
#include "DtFuncion.h"
#include "DtSala.h"
#include "DtPelicula.h"
#include "DtPeliculaPoster.h"
#include "FechaHora.h"
#include "TipoPago.h"

using namespace std;

class IControladorPelicula{
  public:
    // Operaciones
    virtual void cargarPeliculas()=0;
    virtual void cargarFinancieras()=0;
    virtual void SetearCinesPeliculas()=0;
    virtual map<string,DtPelicula*> listarPeliculas()=0;
    virtual map<int,DtSala*> seleccionarCine(int)=0;
    virtual DtPeliculaInfo* seleccionarPelicula(string)=0;
    virtual list<string> listaTitulosPeliculas()=0;
  //  virtual map<string,DtPeliculaInfo*> seleccionarPelicula(string)=0;
    virtual map<int,DtCine*> listaCines(Pelicula*)=0;
    virtual map<int,DtCine*> seleccionarPeliculaCine(string)=0;
    virtual DtCine* CrearDt(Cine*)=0;
    virtual list <DtPeliculaPoster*> obtenerDtPeliculaPoster()=0;
    virtual void seleccionarSala(int)=0;
    virtual void altaFuncion(FechaHora)=0;
    virtual map<int,DtFuncion*> seleccionarCineFuncion(int,string)=0;
    virtual list<DtFuncion*> funcionesDespuesDeFecha(int,FechaHora,string)=0;
    virtual void seleccionarPeliculaTitulo(string)=0;
    virtual void eliminarPelicula()=0;
    virtual float mostrarPrecio(TipoPago,int,string)=0;
    virtual float obtenerDescuento(string)=0;
    virtual void seleccionarFuncion(int)=0;
    //virtual void verPrecioTotal()=0;
    virtual void crearReserva(TipoPago,int,float,string)=0;
};
#endif
