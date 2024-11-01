#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "usuario.h"
#include "usuario.cpp"
using namespace std;

class Comentario {
    private:
        string comentario;
        Usuario usuario;
    public:
        Comentario(string, Usuario);
        void mostrarDatos();
};
