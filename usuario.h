#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "persona.h"
#include "persona.cpp"

using namespace std;

class Usuario : public Persona {
    private:
        int Edad;
    public:
        Usuario(string, int, int);
        void mostrarDatos();
};