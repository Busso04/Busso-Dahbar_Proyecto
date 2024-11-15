#include <iostream>
#include <string>
#include "usuario.h"

using namespace std;

Usuario::Usuario(string nombre, int DNI, int Edad) : Persona(nombre, DNI)
{
    this->Edad = Edad;
}

string Usuario::getNombre() const
{
    return nombre;
}

int Usuario::getDNI() const
{
    return DNI;
}

int Usuario::getEdad() const
{
    return Edad;
}

void Usuario::guardarUsuario(ofstream &archivo) const
{
    archivo << DNI << "|" << nombre << "|" << Edad << endl;
}

string Usuario::toString() const
{
    return to_string(DNI) + " " + nombre + " " + to_string(Edad);
}
