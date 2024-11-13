#include <iostream>
#include <string>
#include "autor.h"

using namespace std;

Autor::Autor(string nombre, int DNI, string Medio) : Persona(nombre, DNI)
{
    this->Medio = Medio;
}

string Autor::getNombre() const
{
    return nombre;
}

int Autor::getDNI() const
{
    return DNI;
}

string Autor::getMedio() const
{
    return Medio;
}

void Autor::publicarNoticia()
{
    cout << "Noticia publicada" << endl;
}

void Autor::obtenerNoticias()
{
    cout << "Noticias obtenidas" << endl;
}
