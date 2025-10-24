#include <iostream>
#include "Biblioteca.h"

void mostrarMenu() {
    std::cout << "\n=== BIBLIOTECA ===" << std::endl;
    std::cout << "1. Agregar libro" << std::endl;
    std::cout << "2. Eliminar libro" << std::endl;
    std::cout << "3. Buscar por título" << std::endl;
    std::cout << "4. Buscar por autor" << std::endl;
    std::cout << "5. Mostrar disponibles" << std::endl;
    std::cout << "6. Mostrar todos" << std::endl;
    std::cout << "7. Prestar libro" << std::endl;
    std::cout << "8. Devolver libro" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Opción: ";
}

int main() {
    Biblioteca biblioteca;
    int opcion;
    
    biblioteca.agregarLibro(Libro("Cien años de soledad", "Gabriel García Márquez", "978-8437604947"));
    biblioteca.agregarLibro(Libro("1984", "George Orwell", "978-0451524935"));
    
    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore();
        
        switch (opcion) {
            case 1: {
                std::string titulo, autor, ISBN;
                std::cout << "Título: "; std::getline(std::cin, titulo);
                std::cout << "Autor: "; std::getline(std::cin, autor);
                std::cout << "ISBN: "; std::getline(std::cin, ISBN);
                biblioteca.agregarLibro(Libro(titulo, autor, ISBN));
                break;
            }
            case 2: {
                std::string ISBN;
                std::cout << "ISBN a eliminar: "; std::getline(std::cin, ISBN);
                biblioteca.eliminarLibro(ISBN);
                break;
            }
            case 3: {
                std::string titulo;
                std::cout << "Título a buscar: "; std::getline(std::cin, titulo);
                biblioteca.buscarPorTitulo(titulo);
                break;
            }
            case 4: {
                std::string autor;
                std::cout << "Autor a buscar: "; std::getline(std::cin, autor);
                biblioteca.buscarPorAutor(autor);
                break;
            }
            case 5: biblioteca.mostrarLibrosDisponibles(); break;
            case 6: biblioteca.mostrarTodosLosLibros(); break;
            case 7: {
                std::string ISBN;
                std::cout << "ISBN a prestar: "; std::getline(std::cin, ISBN);
                biblioteca.prestarLibro(ISBN);
                break;
            }
            case 8: {
                std::string ISBN;
                std::cout << "ISBN a devolver: "; std::getline(std::cin, ISBN);
                biblioteca.devolverLibro(ISBN);
                break;
            }
            case 0: std::cout << "¡Adiós!" << std::endl; break;
            default: std::cout << "Opción inválida" << std::endl;
        }
    } while (opcion != 0);
    
    return 0;
}