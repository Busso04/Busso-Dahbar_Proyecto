#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "persona.h"
#include "persona.cpp"

using namespace std;

class Autor : public Persona {
    private:
        string Medio;
    public:
        Autor(string, int, string);
        void mostrarDatos();
};