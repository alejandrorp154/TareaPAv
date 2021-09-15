#ifndef ICONTROLADORPUNTAJECOMENTARIO_H
#define ICONTROLADORPUNTAJECOMENTARIO_H
#include <iostream>
#include <list>
#include <map>
#include "DtPeliculaPoster.h"
#include "DtPeliculaPuntajeComentario.h"
#include "DtPeliculaInfo.h"
#include "DtCine.h"
#include "DtFuncion.h"
#include "Usuario.h"

using namespace std;

class IControladorPuntajeComentario{
	public:
		virtual void cargarPuntajeComentario()=0;
		//virtual list<string> listaTitulosPeliculas() = 0;
	 	virtual void seleccionarPeliculaTitulo(string) = 0;
	 	virtual float verPuntajeUsuario(Usuario*) = 0;
	 	virtual void ingresarPuntaje(bool,float) = 0;
		virtual list<DtPeliculaPoster*> listaPeliculas() = 0;
		virtual DtPeliculaPuntajeComentario* mostrarComentariosYPuntajes() = 0;
		virtual DtPeliculaInfo* seleccionarPelicula(string) = 0;
		virtual list<DtCine*> listaCines() = 0;
		virtual list<DtFuncion*> seleccionarCine(int) = 0;
		virtual bool seleccionarPeliculaPuntaje(string)=0;
		virtual float verPuntajeUsuario(string)=0;
		virtual void crearComentario(string texto)=0;
		virtual void crearRespuesta(string,int)=0;
};
#endif
