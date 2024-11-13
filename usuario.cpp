#include <iostream>
#include <string>
#include "usuario.h"

using namespace std;

// Constructor de Usuario
Usuario::Usuario(string nombre, int DNI, int Edad) : Persona(nombre, DNI)
{
    this->Edad = Edad;
}

// Getters
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

// Guardar los datos del usuario en un archivo de texto
void Usuario::guardarUsuario(ofstream &archivo) const
{
    archivo << DNI << "|" << nombre << "|" << Edad << endl;
}

// Convertir el usuario a string
string Usuario::toString() const
{
    return to_string(DNI) + " " + nombre + " " + to_string(Edad);
}
