#include "Libro.h"
#include <iostream>

Libro::Libro(const std::string& titulo, const std::string& autor, const std::string& ISBN)
    : titulo(titulo), autor(autor), ISBN(ISBN), disponible(true) {}

std::string Libro::getTitulo() const { return titulo; }
std::string Libro::getAutor() const { return autor; }
std::string Libro::getISBN() const { return ISBN; }
bool Libro::estaDisponible() const { return disponible; }

void Libro::setDisponible(bool estado) { disponible = estado; }

void Libro::mostrarInformacion() const {
    std::cout << "Título: " << titulo << std::endl;
    std::cout << "Autor: " << autor << std::endl;
    std::cout << "ISBN: " << ISBN << std::endl;
    std::cout << "Disponible: " << (disponible ? "Sí" : "No") << std::endl;
    std::cout << "------------------------" << std::endl;
}