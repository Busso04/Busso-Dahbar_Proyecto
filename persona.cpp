#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "persona.h"

using namespace std;

Persona::Persona(string nombre, int DNI) {
    this->nombre = nombre;
    this->DNI = DNI;
}

string Persona::getNombre() const {
    return nombre;
}

int Persona::getDNI() const {
    return DNI;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

void Persona::setDNI(int DNI) {
    this->DNI = DNI;
}