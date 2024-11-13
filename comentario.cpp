#include "comentario.h"

// Constructor de Comentario
Comentario::Comentario(int numero, string comentario, Usuario usuario) :
    numero(numero), comentario(comentario), usuario(usuario) {}

// Mostrar los datos del comentario
void Comentario::mostrarDatos() const {
    cout << "Comentario #" << numero << ": " << comentario << endl;
    cout << "Usuario: " << usuario.getNombre() << " (DNI: " << usuario.getDNI() << ")" << endl;
}

// Guardar el comentario en un archivo de texto
void Comentario::guardarComentario(ofstream &archivo) const {
    archivo << numero << "|" << comentario << "|" << usuario.getDNI() << endl;
}

// Getters
int Comentario::getNumero() const { return numero; }
string Comentario::getComentario() const { return comentario; }
Usuario Comentario::getUsuario() const { return usuario; }
