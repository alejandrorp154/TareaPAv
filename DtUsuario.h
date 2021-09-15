#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include <iostream>

using namespace std;

class DtUsuario{
    private:
        string nickname;
        string password;
        string imagen;
        bool admin;
    public:
        //Constructores y Destructores
        DtUsuario();
        DtUsuario(string,string,string);
        ~DtUsuario();
        //Getters y setters
        string getNickname();
        string getPassword();
        string getImagen();
        bool getAdmin();
};
#endif
