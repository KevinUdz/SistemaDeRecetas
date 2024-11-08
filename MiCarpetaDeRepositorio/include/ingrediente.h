// ingrediente.h
#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <string>

class Ingrediente {
private:
    std::string nombre;
public:
    Ingrediente(const std::string& nombre);
    std::string getNombre() const;
};

#endif // INGREDIENTE_H