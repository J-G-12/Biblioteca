#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"
#include <vector>
#include <string>

class Biblioteca {
private:
    std::vector<Libro> libros;

public:
    void agregarLibro(const Libro& libro);
    bool eliminarLibro(const std::string& ISBN);
    void buscarPorTitulo(const std::string& titulo) const;
    void buscarPorAutor(const std::string& autor) const;
    void mostrarLibrosDisponibles() const;
    void mostrarTodosLosLibros() const;
    bool prestarLibro(const std::string& ISBN);
    bool devolverLibro(const std::string& ISBN);
    Libro* buscarLibroPorISBN(const std::string& ISBN);
};

#endif