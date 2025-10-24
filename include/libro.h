#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string ISBN;
    bool disponible;

public:
    Libro(const std::string& titulo, const std::string& autor, const std::string& ISBN);
    
    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getISBN() const;
    bool estaDisponible() const;
    
    void setDisponible(bool estado);
    void mostrarInformacion() const;
};

#endif