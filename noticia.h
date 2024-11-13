#ifndef NOTICIA_H
#define NOTICIA_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "autor.h"
#include "comentario.h"

using namespace std;

class Noticia
{
private:
    string Titulo;
    string Cuerpo;
    Autor autor;
    int Dia;
    int Mes;
    int Año;

public:
    Noticia(string Titulo, string Cuerpo, Autor autor, int Dia, int Mes, int Año);
    void mostrarDatos() const;
    string getTitulo() const;
    string getCuerpo() const;
    Autor getAutor() const;
    int getDia() const;
    int getMes() const;
    int getAño() const;
    void agregarComentario(const Comentario &comentario);
    void obtenerComentarios();
    string toString() const;
};

#endif