#include "comentario.h"


Comentario::Comentario(int num, const string &comentario, const Usuario &usuario) : numero(num), comentario(comentario), usuario(usuario) {}


int Comentario::getNumero() const { return numero; }
string Comentario::getComentario() const { return comentario; }
Usuario Comentario::getUsuario() const { return usuario; }


void Comentario::mostrarDatos() const
{
    cout << "Comentario #" << numero << ": " << comentario << endl;
    cout << "Autor: " << usuario.getNombre() << endl;
}

string Comentario::toString() const
{
    return to_string(numero) + " " + comentario + " " + usuario.toString();
}