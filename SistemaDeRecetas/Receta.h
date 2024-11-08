#ifndef RECETA_H
#define RECETA_H

#include <string>
#include <vector>
#include "Alimento.h"

class Receta {
public:
    std::string nombre;
    std::vector<std::string> ingredientes;
    std::string tipo; // Tipo de dieta

    Receta(std::string n, std::vector<std::string> ing, std::string t);
    bool esCompatible(const std::vector<Alimento>& alimentos);
};

#endif // RECETA_H