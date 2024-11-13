#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "persona.h"

using namespace std;

Persona ::Persona(string nombre, int DNI) : nombre(nombre), DNI(DNI) {}

string Persona::getNombre() const
{
    return nombre;
}

int Persona::getDNI() const
{
    return DNI;
};