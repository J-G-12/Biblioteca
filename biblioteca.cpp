#include "Biblioteca.h"
#include <iostream>
#include <algorithm>

void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
    std::cout << "Libro agregado: " << libro.getTitulo() << std::endl;
}

bool Biblioteca::eliminarLibro(const std::string& ISBN) {
    auto it = std::remove_if(libros.begin(), libros.end(),
        [&ISBN](const Libro& libro) { return libro.getISBN() == ISBN; });
    
    if (it != libros.end()) {
        libros.erase(it, libros.end());
        std::cout << "Libro eliminado: " << ISBN << std::endl;
        return true;
    }
    
    std::cout << "No se encontró el libro: " << ISBN << std::endl;
    return false;
}

void Biblioteca::buscarPorTitulo(const std::string& titulo) const {
    std::cout << "Buscando: '" << titulo << "'" << std::endl;
    bool encontrado = false;
    
    for (const auto& libro : libros) {
        if (libro.getTitulo().find(titulo) != std::string::npos) {
            libro.mostrarInformacion();
            encontrado = true;
        }
    }
    
    if (!encontrado) std::cout << "No encontrado." << std::endl;
}

void Biblioteca::buscarPorAutor(const std::string& autor) const {
    std::cout << "Buscando autor: '" << autor << "'" << std::endl;
    bool encontrado = false;
    
    for (const auto& libro : libros) {
        if (libro.getAutor().find(autor) != std::string::npos) {
            libro.mostrarInformacion();
            encontrado = true;
        }
    }
    
    if (!encontrado) std::cout << "No encontrado." << std::endl;
}

void Biblioteca::mostrarLibrosDisponibles() const {
    std::cout << "=== LIBROS DISPONIBLES ===" << std::endl;
    for (const auto& libro : libros) {
        if (libro.estaDisponible()) libro.mostrarInformacion();
    }
}

void Biblioteca::mostrarTodosLosLibros() const {
    std::cout << "=== TODOS LOS LIBROS ===" << std::endl;
    for (const auto& libro : libros) libro.mostrarInformacion();
}

bool Biblioteca::prestarLibro(const std::string& ISBN) {
    Libro* libro = buscarLibroPorISBN(ISBN);
    if (libro && libro->estaDisponible()) {
        libro->setDisponible(false);
        std::cout << "Prestado: " << libro->getTitulo() << std::endl;
        return true;
    }
    std::cout << "No disponible: " << ISBN << std::endl;
    return false;
}

bool Biblioteca::devolverLibro(const std::string& ISBN) {
    Libro* libro = buscarLibroPorISBN(ISBN);
    if (libro && !libro->estaDisponible()) {
        libro->setDisponible(true);
        std::cout << "Devuelto: " << libro->getTitulo() << std::endl;
        return true;
    }
    std::cout << "No se puede devolver: " << ISBN << std::endl;
    return false;
}

Libro* Biblioteca::buscarLibroPorISBN(const std::string& ISBN) {
    for (auto& libro : libros) {
        if (libro.getISBN() == ISBN) return &libro;
    }
    return nullptr;
}