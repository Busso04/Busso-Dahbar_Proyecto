#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "usuario.h"

using namespace std;

class Comentario
{
private:
    int numero;        // Número de comentario
    string comentario; // Texto del comentario
    Usuario usuario;   // Usuario que realizó el comentario

public:
    // Constructor con número de comentario, texto y usuario
    Comentario(int numero, const string &comentario, const Usuario &usuario);
    // Getters
    int getNumero() const;
    string getComentario() const;
    Usuario getUsuario() const;
    void mostrarDatos() const;
    string toString() const;
};

#endif