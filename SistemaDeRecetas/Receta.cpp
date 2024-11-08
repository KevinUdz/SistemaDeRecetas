#include "Receta.h"

Receta::Receta(std::string n, std::vector<std::string> ing, std::string t) 
    : nombre(n), ingredientes(ing), tipo(t) {}

bool Receta::esCompatible(const std::vector<Alimento>& alimentos) {
    for (const auto& ing : ingredientes) {
        bool encontrado = false;
        for (const auto& alimento : alimentos) {
            if (alimento.nombre == ing) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) return false;
    }
    return true;
}