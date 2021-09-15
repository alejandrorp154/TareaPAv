#ifndef SESION_H
#define SESION_H
#include <iostream>

using namespace std;

class Sesion{
    private:
        string nickname;
        bool admin;
        static Sesion* instancia;
        Sesion();
    public:
        //Constructores
        Sesion(string, bool);
        virtual ~Sesion();
        // Getters y Setters
        static Sesion* getInstancia();
        string getNickname();
        bool getAdmin();
        void setNickname(string);
        void setAdmin(bool);
        
};
#endif
