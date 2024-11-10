#include <iostream>
#include <string>
#include <vector>
#include "noticia.h"
#include "autor.h"

using namespace std;

Noticia::Noticia(string Titulo, string Cuerpo, Autor autor)
{
  this->Titulo = Titulo;
  this->Cuerpo = Cuerpo;
  this->autor = autor;
}

void Noticia::mostrarDatos()
{
  cout << "Titulo: " << Titulo << endl;
  cout << "Cuerpo: " << Cuerpo << endl;
  cout << "Autor: " << autor.getNombre() << endl;
}
