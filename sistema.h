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

const int Maximo_Autores = 100;
const int Maximo_Usuarios = 100;
const int Maximo_Noticias = 100;
const int Maximo_Comentarios = 100;


class Sistema {
    private:

    Noticia noticias[Maximo_Noticias];
    Autor autores[Maximo_Autores];
    Usuario usuarios[Maximo_Usuarios];
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
   void registrarAutores(string nombre, int DNI, string Medio);

    void registrarUsuarios(string nombre, int DNI, int Edad);

    void registrarNoticias(string Titulo, string Cuerpo, Autor autor,int dia, int mes, int año, int dniAutor);

    void registrarComentarios(string Comentario, Noticia noticia);

    void mostrarAutores();

    void ordenarAutores();

    void ordenarNoticias();

    void mostrarNoticias();

    void mostrarComentarios();

    void interfaz();


};