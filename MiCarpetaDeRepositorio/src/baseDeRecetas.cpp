// baseDeRecetas.cpp
#include "baseDeRecetas.h"

void BaseDeRecetas::agregarReceta(const Receta& receta) {
    recetas.push_back(receta);
}

std::vector<Receta> BaseDeRecetas::buscarRecetas(const std::vector<Ingrediente>& ingredientesUsuario, const std::string& tipoPreferencia) const {
    std::vector<Receta> recetasDisponibles;

    for (const auto& receta : recetas) {
        if (receta.getTipo() == tipoPreferencia || tipoPreferencia == "todos") {
            bool tieneTodosLosIngredientes = true;

            for (const auto& ingrediente : receta.getIngredientes()) {
                bool encontrado = false;
                for (const auto& ingredienteUsuario : ingredientesUsuario) {
                    if (ingredienteUsuario.getNombre() == ingrediente.getNombre()) {
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    tieneTodosLosIngredientes = false;
                    break;
                }
            }

            if (tieneTodosLosIngredientes) {
                recetasDisponibles.push_back(receta);
            }
        }
    }

    return recetasDisponibles;
}