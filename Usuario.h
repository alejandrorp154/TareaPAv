#ifndef USUARIO_H
#define USUARIO_H
#include <map>
#include <iostream>

using namespace std;

class Usuario{
  private:
    string nickname;
    string password;
    string imagen;
    bool admin;
  public:
    //Constructores y Destructores
      Usuario();
      Usuario(string,string,string, bool);
      ~Usuario();
    //Getters y setters
      string getNickname();
      string getPassword();
      string getImagen();
      bool getAdmin();
      void setNickname(string);
      void setPassword(string);
      void setImagen(string);
      void setAdmin(bool);
};
#endif
