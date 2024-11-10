#ifndef CLASES_H
#define CLASES_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Sistema
{
private:
    vector<Autor> autores;
    vector<Usuario> usuarios;
    vector<Noticia> noticias;

public:
    // Métodos de registro
    void registrarAutor(const Autor &autor)
    {
        autores.push_back(autor);
    }

    void registrarUsuario(const Usuario &usuario)
    {
        usuarios.push_back(usuario);
    }

    void registrarNoticia(const Noticia &noticia)
    {
        noticias.push_back(noticia);
    }
};

class Persona
{
private:
    string nombre;
    int DNI;

public:
    Persona(string, int);
    void mostrarDatos();
};

class Usuario : public Persona
{
private:
    int Edad;

public:
    Usuario(string, int, int);
    void mostrarDatos();
};

class Autor : public Persona
{
private:
    string Medio;

public:
    Autor(string, int, string);
    void mostrarDatos();
};

class Noticia
{
private:
    string Titulo;
    string Cuerpo;
    Autor autor;

public:
    Noticia(string, string, Autor);
    void mostrarDatos();
};

class Comentario
{
private:
    string comentario;
    Usuario usuario;

public:
    Comentario(string, Usuario);
    void mostrarDatos();
};

#endif