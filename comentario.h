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
    int numero;        
    string comentario; 
    Usuario usuario;   

public:
    Comentario(int numero, const string &comentario, const Usuario &usuario);
    int getNumero() const;
    string getComentario() const;
    Usuario getUsuario() const;
    void mostrarDatos() const;
    string toString() const;
};

#endif