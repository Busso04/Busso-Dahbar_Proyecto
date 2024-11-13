#include <iostream>
#include <string>
#include <vector>
#include "noticia.h"
#include "autor.h"

using namespace std;

Noticia::Noticia(string Titulo, string Cuerpo, Autor autor, int Dia, int Mes, int Año)
    : Titulo(Titulo), Cuerpo(Cuerpo), autor(autor), Dia(Dia), Mes(Mes), Año(Año)
{
}

void Noticia::mostrarDatos()
{
  cout << "Titulo: " << Titulo << endl;
  cout << "Cuerpo: " << Cuerpo << endl;
  cout << "Autor: " << autor.getNombre() << endl;
}

string Noticia::getTitulo() const
{
  return Titulo;
}

string Noticia::getCuerpo() const
{
  return Cuerpo;
}

Autor Noticia::getAutor() const
{
  return autor;
}

int Noticia::getDia() const
{
  return Dia;
}

int Noticia::getMes() const
{
  return Mes;
}

int Noticia::getAño() const
{
  return Año;
}

void Noticia::agregarComentario()
{
  cout << "Comentario agregado" << endl;
}

void Noticia::obtenerComentarios()
{
  cout << "Comentarios obtenidos" << endl;
}