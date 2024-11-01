#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "autor.h"
#include "autor.cpp"
#include "persona.h"
#include "persona.cpp"
#include "usuario.h"
#include "usuario.cpp"
#include "noticia.h"
#include "noticia.cpp"

using namespace std;

class Sistema {
    private:
    vector<Autor> autores;
    vector<Usuario> usuarios;
    vector<Noticia> noticias;

public:
    // Métodos de registro
    void registrarAutor(const Autor& autor) {
        autores.push_back(autor);
    }
    
    void registrarUsuario(const Usuario& usuario) {
        usuarios.push_back(usuario);
    }

    void registrarNoticia(const Noticia& noticia) {
        noticias.push_back(noticia);
    }

};