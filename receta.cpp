// receta.cpp
#include "receta.h"
#include <iostream>

Receta::Receta(const std::string& nombre, const std::vector<Ingrediente>& ingredientes, const std::string& tipo)
    : nombre(nombre), ingredientes(ingredientes), tipo(tipo) {}

std::string Receta::getNombre() const {
    return nombre;
}

std::string Receta::getTipo() const {
    return tipo;
}

const std::vector<Ingrediente>& Receta::getIngredientes() const {
    return ingredientes;
}

void Receta::mostrarReceta() const {
    std::cout << "Receta: " << nombre << "\nTipo: " << tipo << "\nIngredientes:\n";
    for (const auto& ingrediente : ingredientes) {
        std::cout << "- " << ingrediente.getNombre() << "\n";
    }
}