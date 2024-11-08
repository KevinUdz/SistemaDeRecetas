#include "Usuario.h"
#include "Receta.h" 
#include <iostream>

void Usuario::agregarAlimento(const Alimento& alimento) {
    alimentos.push_back(alimento);
}

void Usuario::establecerPreferencia(const std::string& p) {
    preferencia = p;
}

void Usuario::mostrarRecetasPorAlimentos(const std::vector<Receta>& recetas) {
    std::cout << "Recetas disponibles con los alimentos que tienes:\n";
    for (const auto& receta : recetas) {
        if (receta.esCompatible(alimentos)) { // Asegúrate de que esto sea correcto
            std::cout << "- " << receta.nombre << "\n";
        }
    }
}

void Usuario::mostrarRecetasPorPreferencia(const std::vector<Receta>& recetas) {
    std::cout << "Recetas disponibles para " << preferencia << ":\n";
    for (const auto& receta : recetas) {
        if (receta.tipo == preferencia) {
            std::cout << "- " << receta.nombre << "\n";
        }
    }
}