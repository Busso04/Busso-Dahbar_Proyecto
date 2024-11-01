#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "sistema.h"

using namespace std;

void Sistema::guardarAutores() {
    ofstream ("archivoAutores.txt");
   for (int i = 0; i < cantidadAutores; i++) {
        archivo << autores[i].toString() << endl;
    }