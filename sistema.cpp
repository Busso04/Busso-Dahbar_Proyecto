#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "sistema.h"

using namespace std;

void Sistema::registrar(TipoRegistro tipo, string nombre, int DNI, string Medio, int Edad)
{
    if (tipo == AUTOR)
    {
        autores.push_back(Autor(nombre, DNI, Medio));
    }
    else
    {
        usuarios.push_back(Usuario(nombre, DNI, Edad));
    }
}

void Sistema::registrarNoticias(string Titulo, string Cuerpo, Autor autor, int dia, int mes, int año)
{
    noticias.push_back(Noticia(Titulo, Cuerpo, autor, dia, mes, año));
}

void Sistema::registrarComentarios(string comentarioTexto, Noticia noticia)
{
    if (!usuarios.empty())
    {
        comentarios.push_back(Comentario(comentarios.size() + 1, comentarioTexto, usuarios[0])); // Assuming the first user is the one commenting
    }
    else
    {
        cout << "No hay usuarios registrados para comentar." << endl;
    }
}

void Sistema::mostrarAutores()
{
    for (const auto &autor : autores)
    {
        cout << autor.toString() << endl;
    }
}

void Sistema::ordenarAutores()
{
    sort(autores.begin(), autores.end(), [](const Autor &a, const Autor &b)
         { return a.getDNI() < b.getDNI(); });
}

void Sistema::ordenarNoticias()
{
    sort(noticias.begin(), noticias.end(), [](const Noticia &a, const Noticia &b)
         { return a.getAño() < b.getAño(); });
}

void Sistema::mostrarNoticias()
{
    for (const auto &noticia : noticias)
    {
        noticia.mostrarDatos();
    }
}

void Sistema::mostrarComentarios()
{
    for (const auto &comentario : comentarios)
    {
        comentario.mostrarDatos();
    }
}

void Sistema::iniciarSesion()
{
    string nombre;
    int DNI;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "DNI: ";
    cin >> DNI;
    for (auto &usuario : usuarios)
    {
        if (usuario.getNombre() == nombre && usuario.getDNI() == DNI)
        {
            cout << "Sesion iniciada" << endl;
            usuarioActual = &usuario;
            return;
        }
    }
    cout << "Usuario no encontrado" << endl;
}

void Sistema::iniciarSesionAutor()
{
    string nombre;
    int DNI;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "DNI: ";
    cin >> DNI;
    for (auto &autor : autores)
    {
        if (autor.getNombre() == nombre && autor.getDNI() == DNI)
        {
            cout << "Sesion iniciada" << endl;
            autorActual = &autor;
            return;
        }
    }
    cout << "Autor no encontrado" << endl;
}

void Sistema::subirComentario()
{
    if (usuarioActual == nullptr)
    {
        cout << "Debe iniciar sesion como usuario para subir un comentario." << endl;
        return;
    }

    string comentarioTexto;
    int noticiaIndex;
    cout << "Ingrese el indice de la noticia a comentar: ";
    cin >> noticiaIndex;
    if (noticiaIndex < 0 || noticiaIndex >= noticias.size())
    {
        cout << "Indice de noticia invalido." << endl;
        return;
    }
    cout << "Ingrese el comentario: ";
    cin.ignore();
    getline(cin, comentarioTexto);
    registrarComentarios(comentarioTexto, noticias[noticiaIndex]);
}

void Sistema::crearNoticia()
{
    if (autorActual == nullptr)
    {
        cout << "Debe iniciar sesion como autor para crear una noticia." << endl;
        return;
    }

    string titulo, cuerpo;
    int dia, mes, año;
    cout << "Ingrese el titulo de la noticia: ";
    cin.ignore();
    getline(cin, titulo);
    cout << "Ingrese el cuerpo de la noticia: ";
    getline(cin, cuerpo);
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el año: ";
    cin >> año;
    registrarNoticias(titulo, cuerpo, *autorActual, dia, mes, año);
}

void Sistema::interfaz()
{
    int opcion;
    do
    {
        cout << "1. Registrar" << endl;
        cout << "2. Iniciar sesion" << endl;
        cout << "3. Iniciar sesion como autor" << endl;
        cout << "4. Subir comentario" << endl;
        cout << "5. Crear noticia" << endl;
        cout << "6. Mostrar autores" << endl;
        cout << "7. Ordenar autores" << endl;
        cout << "8. Mostrar noticias" << endl;
        cout << "9. Ordenar noticias" << endl;
        cout << "10. Mostrar comentarios" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            int tipo;
            string nombre;
            int DNI;
            string Medio;
            int Edad;
            cout << "Tipo (1. Autor, 2. Usuario): ";
            cin >> tipo;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "DNI: ";
            cin >> DNI;
            if (tipo == 1)
            {
                cout << "Medio: ";
                cin >> Medio;
                registrar(AUTOR, nombre, DNI, Medio);
            }
            else
            {
                cout << "Edad: ";
                cin >> Edad;
                registrar(USUARIO, nombre, DNI, "", Edad);
            }
            break;
        }
        case 2:
            iniciarSesion();
            break;
        case 3:
            iniciarSesionAutor();
            break;
        case 4:
            subirComentario();
            break;
        case 5:
            crearNoticia();
            break;
        case 6:
            mostrarAutores();
            break;
        case 7:
            ordenarAutores();
            break;
        case 8:
            mostrarNoticias();
            break;
        case 9:
            ordenarNoticias();
            break;
        case 10:
            mostrarComentarios();
            break;
        }
    } while (opcion != 0);
}

void Sistema::guardarUsuarios()
{
    ofstream archivo("usuarios.txt");
    for (const auto &usuario : usuarios)
    {
        archivo << usuario.toString() << endl;
    }
    archivo.close();
}

void Sistema::guardarAutores()
{
    ofstream archivo("autores.txt");
    for (const auto &autor : autores)
    {
        archivo << autor.toString() << endl;
    }
    archivo.close();
}

void Sistema::guardarNoticias()
{
    ofstream archivo("noticias.txt");
    for (const auto &noticia : noticias)
    {
        archivo << noticia.toString() << endl;
    }
    archivo.close();
}

void Sistema::guardarComentarios()
{
    ofstream archivo("comentarios.txt");
    for (const auto &comentario : comentarios)
    {
        archivo << comentario.toString() << endl;
    }
    archivo.close();
}