#ifndef DTPUNTAJE_H
#define DTPUNTAJE_H
#include <iostream>

using namespace std;

class DtPuntaje{
    private:
        string nickname;
        float puntos;
    public:
        DtPuntaje();
        DtPuntaje(string, float);
        ~DtPuntaje();
        string getNickname();
        float getPuntos();
};
#endif
