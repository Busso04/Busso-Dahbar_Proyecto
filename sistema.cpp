#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "sistema.h"

using namespace std;

Sistema::Sistema()
{
    cargarUsuarios();
    cargarAutores();
}

void Sistema::registrar(TipoRegistro tipo, string nombre, int DNI, string Medio, int Edad)
{
    if (tipo == AUTOR)
    {
        autores.push_back(Autor(nombre, DNI, Medio));
        guardarAutores(); // Guardar autores inmediatamente después de crearlos
    }
    else
    {
        usuarios.push_back(Usuario(nombre, DNI, Edad));
        guardarUsuarios(); // Guardar usuarios inmediatamente después de crearlos
    }
}

void Sistema::registrarNoticias(string Titulo, string Cuerpo, Autor autor, int dia, int mes, int año)
{
    noticias.push_back(Noticia(Titulo, Cuerpo, autor, dia, mes, año));
    guardarNoticias();
}

void Sistema::registrarComentarios(string comentarioTexto, Noticia &noticia)
{
    if (usuarioActual != nullptr)
    {
        Comentario comentario(comentarios.size() + 1, comentarioTexto, *usuarioActual);
        comentarios.push_back(comentario);
        noticia.agregarComentario(comentario);
        guardarComentarios();
    }
    else
    {
        cout << "No hay usuarios registrados para comentar." << endl;
    }
}

void Sistema::mostrarAutores()
{
    cargarAutores();

    for (const auto &autor : autores)
    {
        cout << autor.toString() << endl;
    }
}

void Sistema::ordenarNoticias()
{
    sort(noticias.begin(), noticias.end(), [](const Noticia &a, const Noticia &b)
         { return a.getAño() < b.getAño(); });
}

void Sistema::mostrarNoticias()
{

    int opcion;
    cout << "1. Mostrar todas las noticias" << endl;
    cout << "2. Filtrar por autor" << endl;
    cout << "3. Ordenar por fecha" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        for (const auto &noticia : noticias)
        {
            noticia.mostrarDatos();
        }
        break;
    case 2:
    {
        string nombreAutor;
        cout << "Ingrese el nombre del autor: ";
        cin.ignore();
        getline(cin, nombreAutor);
        mostrarNoticiasPorAutor(nombreAutor);
        break;
    }
    case 3:
        ordenarNoticias();
        for (const auto &noticia : noticias)
        {
            noticia.mostrarDatos();
        }
        break;
    default:
        cout << "Opcion invalida." << endl;
        break;
    }
}

void Sistema::mostrarNoticiasPorAutor(const string &nombreAutor)
{
    for (const auto &noticia : noticias)
    {
        if (noticia.getAutor().getNombre() == nombreAutor)
        {
            noticia.mostrarDatos();
        }
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
    cargarUsuarios();
    string nombre;
    int DNI;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "DNI: ";
    cin >> DNI;
    while (DNI < 1000000 || DNI > 99999999)
    {
        cout << "DNI no válido. Ingrese un número entre 1,000,000 y 99,999,999: ";
        cin >> DNI;
    }
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
    cargarAutores();
    string nombre;
    int DNI;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "DNI: ";
    cin >> DNI;
    while (DNI < 1000000 || DNI > 99999999)
    {
        cout << "DNI no válido. Ingrese un número entre 1,000,000 y 99,999,999: ";
        cin >> DNI;
    }
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
    cargarnoticia();
    string comentarioTexto;
    int noticiaIndex;
    cout << "Ingrese el indice de la noticia a comentar: ";
    cin >> noticiaIndex;
    if (noticiaIndex < 0 || noticiaIndex >= static_cast<int>(noticias.size()))
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
    while (dia < 1 || dia > 31)
    {
        cout << "Dia no valido. Intente nuevamente(1-31) ";
        cin >> dia;
    }
    cout << "Ingrese el mes: ";
    cin >> mes;
    while (mes < 1 || mes > 12)
    {
        cout << "Mes no valido. Intente nuevamente(1-12) ";
        cin >> mes;
    }
    cout << "Ingrese el año: ";
    cin >> año;
    while (año < 1900 || año > 2100)
    {
        cout << "Dia no valido. Intente nuevamente(1900-2100) ";
        cin >> año;
    }
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
        cout << "7. Mostrar noticias" << endl;
        cout << "8. Ordenar noticias" << endl;
        cout << "9. Mostrar comentarios" << endl;
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
            while (tipo < 1 || tipo > 2)
            {
                cout << "Tipo no valido. Intente nuevamente(1-2) ";
                cin >> tipo;
            }
            cout << "Nombre: ";
            cin >> nombre;
            cout << "DNI: ";
            cin >> DNI;
            while (DNI < 1000000 || DNI > 99999999)
            {
                cout << "DNI no válido. Ingrese un número entre 1,000,000 y 99,999,999: ";
                cin >> DNI;
            }
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
            mostrarNoticias();
            break;
        case 8:
            ordenarNoticias();
            break;
        case 9:
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
        archivo << usuario.getDNI() << " " << usuario.getNombre() << " " << usuario.getEdad() << endl;
    }
    archivo.close();
}

void Sistema::guardarAutores()
{
    ofstream archivo("autores.txt");
    for (const auto &autor : autores)
    {
        archivo << autor.getDNI() << " " << autor.getNombre() << " " << autor.getMedio() << endl;
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

void Sistema::cargarUsuarios()
{
    ifstream archivo("usuarios.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo de usuarios." << endl;
        return;
    }

    string nombre;
    int DNI, Edad;
    while (archivo >> DNI >> nombre >> Edad)
    {
        usuarios.push_back(Usuario(nombre, DNI, Edad));
    }
    archivo.close();
}

void Sistema::cargarAutores()
{
    ifstream archivo("autores.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo de autores." << endl;
        return;
    }

    string nombre, Medio;
    int DNI;
    while (archivo >> nombre >> DNI >> Medio)
    {
        autores.push_back(Autor(nombre, DNI, Medio));
    }
    archivo.close();
}

void Sistema::cargarnoticia()
{
    ifstream archivo("noticias.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo de noticias." << endl;
        return;
    }

    string Titulo, Cuerpo;
    string autorNombre, autorMedio;
    int autorDNI, Dia, Mes, Año;
    while (archivo >> Titulo >> Cuerpo >> autorNombre >> autorDNI >> autorMedio >> Dia >> Mes >> Año)
    {
        Autor autor(autorNombre, autorDNI, autorMedio);
        noticias.push_back(Noticia(Titulo, Cuerpo, autor, Dia, Mes, Año));
    }
    archivo.close();
}

void Sistema::cargarComentario()
{
    ifstream archivo("comentarios.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo de comentarios." << endl;
        return;
    }

    int numero, usuarioDNI, usuarioEdad;
    string comentario, usuarioNombre;
    while (archivo >> numero >> comentario >> usuarioNombre >> usuarioDNI >> usuarioEdad)
    {
        Usuario usuario(usuarioNombre, usuarioDNI, usuarioEdad);
        comentarios.push_back(Comentario(numero, comentario, usuario));
    }
    archivo.close();
}
