#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Persona {
    protected:
        string nombre;
        int DNI;
    public:
        Persona(string, int);
        void mostrarDatos();
};
