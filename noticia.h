#ifndef NOTICIA_H
#define NOTICIA_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "autor.cpp"
#include "autor.h"

using namespace std;

class Noticia
{
private:
    string Titulo;
    string Cuerpo;
    Autor autor;
    Dia dia;
    Mes mes;
    Año año;

public:
    Noticia(string, string, Autor);
    void mostrarDatos();
};

#endif