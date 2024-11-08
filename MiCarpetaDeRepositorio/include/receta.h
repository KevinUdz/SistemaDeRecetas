// receta.h
#ifndef RECETA_H
#define RECETA_H

#include <vector>
#include <string>
#include "ingrediente.h"

class Receta {
private:
    std::string nombre;
    std::vector<Ingrediente> ingredientes;
    std::string tipo;  // omnivoro, vegetariano, vegano, etc.

public:
    Receta(const std::string& nombre, const std::vector<Ingrediente>& ingredientes, const std::string& tipo);
    std::string getNombre() const;
    std::string getTipo() const;
    const std::vector<Ingrediente>& getIngredientes() const;
    void mostrarReceta() const;
};

#endif // RECETA_H