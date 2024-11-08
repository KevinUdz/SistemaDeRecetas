#ifndef ALIMENTO_H
#define ALIMENTO_H

#include <string>

class Alimento {
public:
    std::string nombre;
    std::string tipo; // Este tipo puede ser "omnivoro", "vegetariano", "vegano", "keto", "sin gluten"

    Alimento(std::string n, std::string t);
};

#endif // ALIMENTO_H