#ifndef AUTOR_H
#define AUTOR_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "persona.h"
#include "persona.cpp"

using namespace std;

class Autor : public Persona
{
private:
    string Medio;

public:
    Autor(string nombre, int DNI, string Medio);
    string getNombre() const;
    int getDNI() const;
    string getMedio() const;
};

#endif