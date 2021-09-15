#ifndef CONTROLADORPUNTAJECOMENTARIO_H
#define CONTROLADORPUNTAJECOMENTARIO_H
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include "Comentario.h"
#include "Puntaje.h"
#include "Usuario.h"
#include "DtFuncion.h"
#include "DtCine.h"
#include "Pelicula.h"
#include "DtPeliculaPoster.h"
#include "DtPeliculaInfo.h"
#include "DtPeliculaPuntajeComentario.h"
#include "IControladorPuntajeComentario.h"
#include "ManejadorPelicula.h"
#include "ManejadorCine.h"
#include "ManejadorUsuario.h"
#include "Sesion.h"


using namespace std;

class ControladorPuntajeComentario:public IControladorPuntajeComentario{
	private:
		int idComentario;
		string texto;
		float puntos;
		string titulo;
	public:
		//Constructores
		ControladorPuntajeComentario();
		~ControladorPuntajeComentario();
		//Operaciones
		void cargarPuntajeComentario();
		//list<string> listaTitulosPeliculas();
	 	void seleccionarPeliculaTitulo(string);
	 	float verPuntajeUsuario(Usuario*);
	 	void ingresarPuntaje(bool,float);
		list<DtPeliculaPoster*> listaPeliculas();
		DtPeliculaPuntajeComentario* mostrarComentariosYPuntajes();
	 	DtPeliculaInfo* seleccionarPelicula(string);
		list<DtCine*> listaCines();
		list<DtFuncion*> seleccionarCine(int);
		bool seleccionarPeliculaPuntaje(string);
        float verPuntajeUsuario(string);
		void crearComentario(string);
		void crearRespuesta(string,int);
};
#endif
