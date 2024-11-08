// sistemaDeRecetas.cpp
#include "sistemaDeRecetas.h"
#include <iostream>

SistemaDeRecetas::SistemaDeRecetas(const Usuario& usuario) : usuario(usuario) {}

void SistemaDeRecetas::agregarReceta(const Receta& receta) {
    baseDeRecetas.agregarReceta(receta);
}

void SistemaDeRecetas::sugerirRecetas() {
    std::vector<Receta> recetasDisponibles = baseDeRecetas.buscarRecetas(usuario.getIngredientesDisponibles(), usuario.getTipoPreferencia());

    if (recetasDisponibles.empty()) {
        std::cout << "No hay recetas disponibles con los ingredientes que tienes.\n";
    } else {
        std::cout << "Recetas sugeridas:\n";
        for (const auto& receta : recetasDisponibles) {
            receta.mostrarReceta();
            std::cout << "\n";
        }
    }
}