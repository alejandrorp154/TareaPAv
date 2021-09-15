ejec: Usuario.o Puntaje.o Pelicula.o Cine.o TipoPago.h Reserva.o Funcion.o Fecha.o FechaHora.o Sala.o Credito.o Debito.o Puntaje.o Comentario.o DtFuncion.o DtPeliculaPoster.o DtPeliculaTitulo.o DtPeliculaInfo.o DtPuntaje.o DtSala.o DtComentario.o DtPelicula.o DtFuncionHorario.o DtPeliculaPuntajeComentario.o DtCine.o DtUsuario.o DtReserva.o DtDebito.o DtCredito.o Sesion.o Factory.o ManejadorUsuario.o ControladorUsuario.o IControladorUsuario.h IControladorCine.h ManejadorPelicula.o IControladorPelicula.h ManejadorCine.o  ControladorCine.o ControladorPelicula.o ControladorPuntajeComentario.o ManejadorFuncion.o Reloj.o Financiera.o main.o
	g++ -Wall -Werror -o ejec Usuario.o Pelicula.o Cine.o TipoPago.h Reserva.o Funcion.o Fecha.o FechaHora.o Credito.o Debito.o Puntaje.o Sala.o Comentario.o DtFuncion.o DtPeliculaPoster.o DtPeliculaTitulo.o DtPeliculaInfo.o DtPuntaje.o DtSala.o DtComentario.o DtPelicula.o DtFuncionHorario.o DtPeliculaPuntajeComentario.o DtCine.o DtUsuario.o DtReserva.o DtDebito.o DtCredito.o Sesion.o Factory.o ManejadorUsuario.o ControladorUsuario.o IControladorUsuario.h IControladorCine.h ManejadorPelicula.o IControladorPelicula.h ControladorPelicula.o ManejadorCine.o  ControladorCine.o ControladorPuntajeComentario.o IControladorPuntajeComentario.h ManejadorFuncion.o Reloj.o Financiera.o main.o

main.o: main.cpp

Puntaje.o: Puntaje.cpp

Comentario.o: Comentario.cpp

Pelicula.o: Pelicula.cpp

Credito.o: Credito.cpp

Debito.o: Debito.cpp

Reserva.o: Reserva.cpp

Funcion.o: Funcion.cpp

Sala.o: Sala.cpp

Cine.o: Cine.cpp

Usuario.o: Usuario.cpp

FechaHora.o: FechaHora.cpp

Fecha.o: Fecha.cpp

DtFuncion.o: DtFuncion.cpp

DtPeliculaPoster.o: DtPeliculaPoster.cpp

DtPeliculaTitulo.o: DtPeliculaTitulo.cpp

DtPeliculaInfo.o: DtPeliculaInfo.cpp

DtPuntaje.o: DtPuntaje.cpp

DtSala.o: DtSala.cpp

DtComentario.o: DtComentario.cpp

DtPelicula.o: DtPelicula.cpp

DtFuncionHorario.o: DtFuncionHorario.cpp

DtPeliculaPuntajeComentario.o: DtPeliculaPuntajeComentario.cpp

DtCine.o: DtCine.cpp

DtUsuario.o: DtUsuario.cpp

DtReserva.o: DtReserva.cpp

DtDebito.o: DtDebito.cpp

DtCredito.o: DtCredito.cpp

Sesion.o: Sesion.cpp

Factory.o: Factory.cpp

ManejadorUsuario.o: ManejadorUsuario.cpp

ManejadorPelicula.o: ManejadorPelicula.cpp

ManejadorCine.o: ManejadorCine.cpp

ManejadorFuncion.o: ManejadorFuncion.cpp

ControladorUsuario.o: ControladorUsuario.cpp

ControladorCine.o: ControladorCine.cpp

ControladorPelicula.o: ControladorPelicula.cpp

ControladorPuntajeComentario.o: ControladorPuntajeComentario.cpp

Reloj.o: Reloj.cpp

Financiera.o: Financiera.cpp

clean:
		rm -f *.o
		rm -f ejec
