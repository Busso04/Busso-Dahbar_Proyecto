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
    int numero;  // Número de comentario
    string comentario;  // Texto del comentario
    Usuario usuario;  // Usuario que realizó el comentario

public:
    // Constructor con número de comentario, texto y usuario
    Comentario(int numero, string comentario, Usuario usuario);

    // Métodos para mostrar y guardar datos
    void mostrarDatos() const;
    void guardarComentario(ofstream &archivo) const;

    // Getters
    int getNumero() const;
    string getComentario() const;
    Usuario getUsuario() const;
};

#endif
