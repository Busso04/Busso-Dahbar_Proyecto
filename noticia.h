#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "autor.cpp"
#include "autor.h"

using namespace std;

class Noticia {
    private:
        string Titulo;
        string Cuerpo;
        Autor autor;
    public:
        Noticia(string, string, Autor);
        void mostrarDatos();
};