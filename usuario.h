#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "persona.h"
#include "persona.cpp"

using namespace std;

class Usuario : public Persona
{
private:
    int Edad;

public:
    Usuario(string nombre, int DNI, int Edad);
    string getNombre() const;
    int getDNI() const;
    int getEdad() const;
};

#endif