// main.cpp
#include "ingrediente.h"
#include "receta.h"
#include "baseDeRecetas.h"
#include "usuario.h"
#include "sistemaDeRecetas.h"
#include <iostream>

int main() {
    // Crear ingredientes
    Ingrediente tomate("Tomate");
    Ingrediente lechuga("Lechuga");
    Ingrediente pollo("Pollo");
    Ingrediente tofu("Tofu");

    // Crear recetas
    Receta ensalada("Ensalada", {lechuga, tomate}, "vegano");
    Receta polloALaPlancha("Pollo a la Plancha", {pollo, tomate}, "omnivoro");

    // Crear usuario
    Usuario usuario("vegano");
    usuario.agregarIngrediente(lechuga);
    usuario.agregarIngrediente(tomate);

    // Crear sistema de recetas
    SistemaDeRecetas sistema(usuario);
    sistema.agregarReceta(ensalada);
    sistema.agregarReceta(polloALaPlancha);

    // Sugerir recetas
    sistema.sugerirRecetas();

    return 0;
}