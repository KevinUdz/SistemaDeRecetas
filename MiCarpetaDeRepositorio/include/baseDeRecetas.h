// baseDeRecetas.h
#ifndef BASEDERECETAS_H
#define BASEDERECETAS_H

#include <vector>
#include "receta.h"
#include "ingrediente.h"

class BaseDeRecetas {
private:
    std::vector<Receta> recetas;

public:
    void agregarReceta(const Receta& receta);
    std::vector<Receta> buscarRecetas(const std::vector<Ingrediente>& ingredientesUsuario, const std::string& tipoPreferencia) const;
};

#endif // BASEDERECETAS_H