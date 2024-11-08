// usuario.h
#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include "ingrediente.h"

class Usuario {
private:
    std::vector<Ingrediente> ingredientesDisponibles;
    std::string tipoPreferencia;  // omnivoro, vegetariano, vegano, etc.

public:
    Usuario(const std::string& tipoPreferencia);
    void agregarIngrediente(const Ingrediente& ingrediente);
    const std::vector<Ingrediente>& getIngredientesDisponibles() const;
    std::string getTipoPreferencia() const;
};

#endif // USUARIO_H