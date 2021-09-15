#include "ControladorPuntajeComentario.h"

ControladorPuntajeComentario::ControladorPuntajeComentario():IControladorPuntajeComentario(){}
ControladorPuntajeComentario::~ControladorPuntajeComentario(){}

void ControladorPuntajeComentario::cargarPuntajeComentario(){
		ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
		ManejadorUsuario* mu=ManejadorUsuario::getInstancia();
		Pelicula* p1=mp->obtenerPelicula("Hola");
		// -----------------------------------------------------------
		Puntaje* punt=new Puntaje(5);
		Usuario* u1=mu->obtenerUsuario("a");
		punt->agregarUsuario(u1);
		p1->agregarPuntaje(punt);
		// -----------------------------------------------------------
		Puntaje* punt2=new Puntaje(8);
		Usuario* u2=mu->obtenerUsuario("Nemo");
		punt2->agregarUsuario(u2);
		p1->agregarPuntaje(punt2);
		// --------------------------------------------------------------
		Comentario* com1= new Comentario("Muy buena peli, me gusta la parte que se saludan");
		com1->agregarUsuario(u2);
		p1->agregarComentario(com1);
		// -----------------------------------------------------------------
		Comentario* com2= new Comentario("Esta mas o menos, al final muere mucha gente y no se saludan");
		com2->agregarUsuario(u1);
		p1->agregarComentario(com2);
		// --------------------------------------------------------------------
		Comentario* com3= new Comentario("Es una mierda, me vuelvo a California uauauauaua");
		com3->agregarUsuario(u2);
		com2->agregarRespuesta(com3);

		Comentario* com4= new Comentario("Mataron a Kenny");
		com4->agregarUsuario(u1);
		com3->agregarRespuesta(com4);

		Comentario* com5= new Comentario("Hijos de puta!!");
		com5->agregarUsuario(u2);
		p1->agregarComentario(com5);
}
/*list<string> ControladorPuntajeComentario::listaTitulosPeliculas(){
	list<string> listaTitulos;
	ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
	//Pelicula* p = mp->getTitulos();
	for(map<string,DtPelicula*>::iterator it=this->ColeccionPeliculas.begin();it!=this->ColeccionPeliculas.end();++it){
		listaTitulos.push_back(it->second->getTitulo());
	}
	return listaTitulos;
}*/
void ControladorPuntajeComentario::seleccionarPeliculaTitulo(string t){
	this->titulo = t;
}
float ControladorPuntajeComentario::verPuntajeUsuario(Usuario* u){
	/*float puntajeUsuario;
	ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
	*/
}
void ControladorPuntajeComentario::ingresarPuntaje(bool puntuo, float pts){
	this->puntos = pts;
	ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
	ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
	Pelicula* p = mp->obtenerPelicula(this->titulo);
	Sesion* s = Sesion::getInstancia();
	Usuario* u = mu->obtenerUsuario(s->getNickname());

	if(puntuo){
		p->modificarPuntaje(pts,u->getNickname());

	}
	else{
		Puntaje* punt = new Puntaje(pts);
		punt->agregarUsuario(u);
		p->agregarPuntaje(punt);
	}
}
list<DtPeliculaPoster*> ControladorPuntajeComentario::listaPeliculas(){
	list<DtPeliculaPoster*> listaDtPeliPoster;
	ManejadorPelicula* mp = ManejadorPelicula::getInstancia();

	for(map<string,Pelicula*>::iterator it=mp->obtenerPelis().begin();it!=mp->obtenerPelis().end();++it){
		DtPeliculaPoster* dtpp = new DtPeliculaPoster(it->second->getTitulo(),it->second->getPoster());
		listaDtPeliPoster.push_back(dtpp);
	}
	return listaDtPeliPoster;
}
DtPeliculaPuntajeComentario* ControladorPuntajeComentario::mostrarComentariosYPuntajes(){

	ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
	Pelicula* p=mp->obtenerPelicula(titulo);
	DtPeliculaPuntajeComentario* dt = new DtPeliculaPuntajeComentario (p->getTitulo(),p->getPuntajePromedio());
	//AGREGO LOS PUNTAJES DE LA PELICULA AL DTPELICULAPUNTAJECOMENTARIO
	list<DtPuntaje*>listaPuntajes = p->obtenerPuntajes();
	if(!listaPuntajes.empty()){
		for(list<DtPuntaje*>::iterator it=listaPuntajes.begin();it!=listaPuntajes.end();++it){
			dt->agregarPuntaje((*it));
		}
	}
	//AGREGO LOS COMENTARIOS DE LA PELICULA AL DTPELICULAPUNTAJECOMENTARIO
	list<DtComentario*>listaComentarios=p->crearDtComentarios();
	if(!listaComentarios.empty()){
		for(list<DtComentario*>::iterator it=listaComentarios.begin();it!=listaComentarios.end();++it){
			dt->agregarComentario((*it));
		}
	}
	return dt;
}

DtPeliculaInfo* ControladorPuntajeComentario::seleccionarPelicula(string peli){
	ManejadorPelicula* mp = ManejadorPelicula::getInstancia();
	Pelicula* p = mp->obtenerPelicula(peli);
	DtPeliculaInfo* dtpi = new DtPeliculaInfo(p->getSinopsis(),p->getPoster());
	return dtpi;
}

list<DtCine*> ControladorPuntajeComentario::listaCines(){
	list<DtCine*> listaDtCines;
	ManejadorCine* mc = ManejadorCine::getInstancia();
	for(map<int,Cine*>::iterator it = mc->getCines().begin();it!=mc->getCines().end();++it){
		DtCine* dtc = new DtCine(it->second->getIdCine(),it->second->getDireccion());
		listaDtCines.push_back(dtc);
	}
	return listaDtCines;
}
list<DtFuncion*> ControladorPuntajeComentario::seleccionarCine(int idC){
	/*list<DtFuncion*> listDtF;
	ManejadorCine mc = ManejadorCine::getInstancia();
	Cine* c = mc->obtenerCine(idC);*/
}

bool ControladorPuntajeComentario::seleccionarPeliculaPuntaje(string titulo){
	this->titulo = titulo;
	ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
    Sesion* s=Sesion::getInstancia();
    Pelicula* p=mp->obtenerPelicula(titulo);
    string nickname = s->getNickname();
    return p->existePuntajeUsuario(nickname);
}
void ControladorPuntajeComentario::crearComentario(string texto){
	Comentario* c= new Comentario(texto);
	Sesion* s=Sesion::getInstancia();
	ManejadorUsuario* mu=ManejadorUsuario::getInstancia();
	ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
	Pelicula* p=mp->obtenerPelicula(titulo);
	Usuario* u=mu->obtenerUsuario(s->getNickname());
	c->agregarUsuario(u);
	p->agregarComentario(c);
}
void ControladorPuntajeComentario::crearRespuesta(string texto, int idresp){
	Sesion* s=Sesion::getInstancia();
	ManejadorUsuario* mu=ManejadorUsuario::getInstancia();
	ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
	Pelicula* p=mp->obtenerPelicula(titulo);
	Usuario* u=mu->obtenerUsuario(s->getNickname());
	Comentario* cresp= p->obtenerComentario(idresp);
	if(cresp!=NULL){
		Comentario* c= new Comentario(texto);
		c->agregarUsuario(u);
		cresp->agregarRespuesta(c);
	}
	else{
		cout<<"No hay comentarios con esa id"<< endl;
	}
}

float ControladorPuntajeComentario::verPuntajeUsuario(string titulo){
    ManejadorPelicula* mp=ManejadorPelicula::getInstancia();
    Sesion* s=Sesion::getInstancia();
    Pelicula* p=mp->obtenerPelicula(titulo);
    string nickname = s->getNickname();
    return p->puntajeUsuario(nickname);
}
