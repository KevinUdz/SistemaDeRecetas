#ifndef USUARIO_H  // Directiva de preprocesador para evitar múltiples inclusiones
#define USUARIO_H

#include <string>
#include "receta.h"  // Incluye la definición de la clase Receta

// Clase que representa un usuario del sistema de recetas
class Usuario {
private:
    static const int MAX_RECETAS = 20;  // Constante que define el máximo de recetas por usuario

    std::string nombre;  // Nombre del usuario
    std::string email;  // Correo electrónico del usuario
    Receta recetas_publicadas[MAX_RECETAS];  // Arreglo de recetas publicadas por el usuario
    int num_recetas;  // Contador de recetas publicadas

public:
    // Constructor por defecto: inicializa un usuario vacío
    Usuario() : nombre(""), email(""), num_recetas(0) {}
    
    // Constructor parametrizado: crea un usuario con nombre y correo
    Usuario(std::string nom, std::string correo) 
        : nombre(nom), email(correo), num_recetas(0) {}

    // Métodos getter para obtener nombre y correo
    std::string getNombre() const { return nombre; }
    std::string getEmail() const { return email; }
    
    // Método setter para establecer nombre, con validación de no vacío
    void setNombre(const std::string& nom) {
        if (!nom.empty()) nombre = nom;
    }
    
    // Método setter para establecer email, con validación de formato de correo
    void setEmail(const std::string& correo) {
        if (correo.find('@') != std::string::npos) {
            email = correo;
        }
    }

    // Método para publicar una receta
    void publicarReceta(const Receta& receta) {
        if (num_recetas < MAX_RECETAS) {
            recetas_publicadas[num_recetas] = receta;
            num_recetas++;
        } else {
            std::cout << "Límite de recetas alcanzado." << std::endl;
        }
    }

    // Método para obtener las recetas publicadas en un arreglo externo
    void getRecetasPublicadas(Receta arr[], int& cant) const {
        for(int i = 0; i < num_recetas; i++) {
            arr[i] = recetas_publicadas[i];
        }
        cant = num_recetas;
    }

    // Método para obtener el número de recetas publicadas
    int getNumeroRecetas() const {
        return num_recetas;
    }
};

#endif