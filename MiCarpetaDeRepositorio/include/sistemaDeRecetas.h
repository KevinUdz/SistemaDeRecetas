// sistemaDeRecetas.h
#ifndef SISTEMA_DE_RECETAS_H
#define SISTEMA_DE_RECETAS_H

#include "baseDeRecetas.h"
#include "usuario.h"

class SistemaDeRecetas {
private:
    BaseDeRecetas baseDeRecetas;
    Usuario usuario;

public:
    SistemaDeRecetas(const Usuario& usuario);
    void agregarReceta(const Receta& receta);
    void sugerirRecetas();
};

#endif // SISTEMA_DE_RECETAS_H