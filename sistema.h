#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "autor.h"
#include "autor.cpp"
#include "persona.h"
#include "persona.cpp"
#include "usuario.h"
#include "usuario.cpp"
#include "noticia.h"
#include "noticia.cpp"

using namespace std;

enum TipoRegistro
{
    AUTOR,
    USUARIO
};

class Sistema
{
private:
    Noticia noticias[100];
    Autor autores[100];
    Usuario usuarios[100];
    int cantidadAutores;
    int cantidadUsuarios;
    int cantidadNoticias;
    int cantidadComentarios;
    void guardarAutores();
    void guardarUsuarios();
    void guardarNoticias();
    void guardarComentarios();
    void mostrarAutores();
    void mostrarUsuarios();
    void mostrarNoticias();
    void mostrarComentarios();

public:
    // Métodos de registro
    void registrar(TipoRegistro tipo, string nombre, int DNI, string Medio = "", int Edad = 0);

    void registrarNoticias(string Titulo, string Cuerpo, Autor autor, int dia, int mes, int año, int dniAutor);

    void registrarComentarios(string Comentario, Noticia noticia);

    void mostrarAutores();

    void ordenarAutores();

    void ordenarNoticias();

    void mostrarNoticias();

    void mostrarComentarios();

    void interfaz();
};

#endif