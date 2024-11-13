#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "autor.h"
#include "persona.h"
#include "usuario.h"
#include "noticia.h"
#include "comentario.h"

using namespace std;

enum TipoRegistro
{
    AUTOR,
    USUARIO
};

class Sistema
{
private:
    vector<Autor> autores;
    vector<Usuario> usuarios;
    vector<Noticia> noticias;
    vector<Comentario> comentarios;
    Usuario *usuarioActual = nullptr; // Usuario que ha iniciado sesión
    Autor *autorActual = nullptr;     // Autor que ha iniciado sesión

public:
    // Métodos de registro
    void registrar(TipoRegistro tipo, string nombre, int DNI, string Medio = "", int Edad = 0);

    void guardarUsuarios();

    void guardarAutores();

    void guardarNoticias();

    void guardarComentarios();

    void registrarNoticias(string Titulo, string Cuerpo, Autor autor, int dia, int mes, int año);

    void registrarComentarios(string Comentario, Noticia noticia);

    void mostrarAutores();

    void ordenarAutores();

    void ordenarNoticias();

    void mostrarNoticias();

    void mostrarComentarios();

    void iniciarSesion();

    void iniciarSesionAutor();

    void subirComentario();

    void crearNoticia();

    void interfaz();
};

#endif