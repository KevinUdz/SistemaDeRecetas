#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "receta.h"

class Usuario {
private:
    std::string nombre;
    std::string email;
    std::vector<Receta> recetas_publicadas;

public:
    Usuario() : nombre(""), email("") {}
    Usuario(std::string nom, std::string correo) : nombre(nom), email(correo) {}

    std::string getNombre() const { return nombre; }
    std::string getEmail() const { return email; }
    
    void setNombre(const std::string& nom) {
        if (!nom.empty()) nombre = nom;
    }
    
    void setEmail(const std::string& correo) {
        if (correo.find('@') != std::string::npos) {
            email = correo;
        }
    }

    void publicarReceta(const Receta& receta) {
        recetas_publicadas.push_back(receta);
    }

    std::vector<Receta> getRecetasPublicadas() const { 
        return recetas_publicadas; 
    }
};

#endif