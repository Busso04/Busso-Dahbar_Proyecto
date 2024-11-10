#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Persona
{
protected:
    string nombre;
    int DNI;

public:
    Persona(string nombre, int DNI);
    string getNombre() const;
    int getDNI() const;
};

#endif