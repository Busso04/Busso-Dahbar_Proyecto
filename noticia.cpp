#include <iostream>
#include <string>
#include <vector>
#include "noticia.h"
#include "autor.h"
#include "comentario.h"

using namespace std;

Noticia::Noticia(string Titulo, string Cuerpo, Autor autor, int Dia, int Mes, int Año)
    : Titulo(Titulo), Cuerpo(Cuerpo), autor(autor), Dia(Dia), Mes(Mes), Año(Año)
{
}

void Noticia::mostrarDatos() const
{
  cout << "Titulo: " << Titulo << endl;
  cout << "Cuerpo: " << Cuerpo << endl;
  cout << "Autor: " << autor.getNombre() << endl;
  cout << "Fecha: " << Dia << "/" << Mes << "/" << Año << endl;
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

void Noticia::agregarComentario(const Comentario &comentario)
{
  comentarios.push_back(comentario);
}

void Noticia::obtenerComentarios() const
{
  for (const auto &comentario : comentarios)
  {
    comentario.mostrarDatos();
  }
}

string Noticia::toString() const
{
  return Titulo + " " + Cuerpo + " " + autor.toString() + " " + to_string(Dia) + " " + to_string(Mes) + " " + to_string(Año);
}