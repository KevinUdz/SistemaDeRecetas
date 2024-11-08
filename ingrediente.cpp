// ingrediente.cpp
#include "ingrediente.h"

Ingrediente::Ingrediente(const std::string& nombre) : nombre(nombre) {}

std::string Ingrediente::getNombre() const {
    return nombre;
}