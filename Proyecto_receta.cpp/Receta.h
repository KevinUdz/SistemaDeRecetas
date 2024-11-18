#ifndef RECETA_H
#define RECETA_H

#include "alimento.h"
#include <vector>
#include <algorithm>

class Receta : public Alimento {
private:
    std::string tipo_dieta;
    int tiempo_preparacion;
    std::vector<std::string> ingredientes;
    bool disponible;

public:
    Receta() : Alimento(), tipo_dieta(""), tiempo_preparacion(0), disponible(true) {}
    
    Receta(std::string nom, int cal, std::string dieta, int tiempo) 
        : Alimento(nom, cal), tipo_dieta(dieta), tiempo_preparacion(tiempo), disponible(true) {}

    std::string getTipoDieta() const { return tipo_dieta; }
    int getTiempoPreparacion() const { return tiempo_preparacion; }
    bool getDisponibilidad() const { return disponible; }
    std::vector<std::string> getIngredientes() const { return ingredientes; }

    void setTipoDieta(const std::string& dieta) {
        const std::vector<std::string> dietas_validas = {"vegetariana", "vegana", "normal"};
        if (std::find(dietas_validas.begin(), dietas_validas.end(), dieta) != dietas_validas.end()) {
            tipo_dieta = dieta;
        }
    }

    void setTiempoPreparacion(int tiempo) {
        if (tiempo > 0 && tiempo < 240) {
            tiempo_preparacion = tiempo;
        }
    }

    void agregarIngrediente(const std::string& ingrediente) {
        ingredientes.push_back(ingrediente);
    }

    void mostrarInformacion() const override {
        Alimento::mostrarInformacion();
        std::cout << "Tipo de dieta: " << tipo_dieta << std::endl;
        std::cout << "Tiempo preparación: " << tiempo_preparacion << " min" << std::endl;
        
        std::cout << "Ingredientes: ";
        for(const auto& ingrediente : ingredientes) {
            std::cout << ingrediente << ", ";
        }
        std::cout << std::endl;
    }
};

#endif