#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Alimento.h"
#include "Receta.h"

class Usuario {
public:
    std::vector<Alimento> alimentos;
    std::string preferencia;

    void agregarAlimento(const Alimento& alimento);
    void establecerPreferencia(const std::string& p);
    void mostrarRecetasPorAlimentos(const std::vector<Receta>& recetas);
    void mostrarRecetasPorPreferencia(const std::vector<Receta>& recetas);
};

#endif // USUARIO_H