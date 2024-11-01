#include <iostream>
#include <string>
#include "usuario.h"

using namespace std;

Usuario::Usuario(string nombre, int DNI, int Edad) : Persona(nombre, DNI) {
    this->Edad = Edad;
}

string Usuario::getNombre() const {
    return nombre;
}

int Usuario::getDNI() const {
    return DNI;
}

int Usuario::getEdad() const {
    return Edad;
}

