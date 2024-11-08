#include <iostream>
#include <vector>
#include <string>
#include "Alimento.h"
#include "Receta.h"
#include "Usuario.h"

int main() {
    // Crear algunas recetas
    std::vector<Receta> recetas = {
        Receta("Ensalada de Quinoa", {"quinoa", "tomate", "pepino"}, "vegetariano"),
        Receta("Sopa de Lentejas", {"lentejas", "zanahoria", "apio"}, "vegano"),
        Receta("Tacos de Pollo", {"pollo", "tortilla", "lechuga"}, "omnivoro"),
        Receta("Pizza Keto", {"masa de coliflor", "queso", "pepperoni"}, "keto"),
        Receta("Galletas Sin Gluten", {"harina de almendra", "huevo", "mantequilla"}, "sin gluten")
    };

    return 0;
}