// usuario.cpp
#include "usuario.h"

Usuario::Usuario(const std::string& tipoPreferencia) : tipoPreferencia(tipoPreferencia) {}

void Usuario::agregarIngrediente(const Ingrediente& ingrediente) {
    ingredientesDisponibles.push_back(ingrediente);
}

const std::vector<Ingrediente>& Usuario::getIngredientesDisponibles() const {
    return ingredientesDisponibles;
}

std::string Usuario::getTipoPreferencia() const {
    return tipoPreferencia;
}