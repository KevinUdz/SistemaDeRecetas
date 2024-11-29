#ifndef RECETA_H  // Directiva de preprocesador para evitar múltiples inclusiones
#define RECETA_H

#include "alimento.h"  //incluyo la definicion de la clase Alimento.h
#include <string>
#include <iostream>
#include <algorithm> //incluyo funciones algoritmicas

// La clase "Receta" heredara a "Alimento" y representara una receta especifica
class Receta : public Alimento { //esta sera su herencia publica de "Alimento"
private:
    static const int MAX_INGREDIENTES = 10;  // Número máximo de ingredientes

    std::string tipo_dieta; //Este sera el tipo de dieta de la receta (vegetariana, vegana, normal)
    int tiempo_preparacion; //Defino el tiempo necesario para su preparacion
    std::string ingredientes[MAX_INGREDIENTES];  // Arreglo de ingredientes
    int num_ingredientes;  // Contador de ingredientes
    bool disponible; //el bool me servira para indicar si la receta esta disponible o no

public:
    // Constructor por defecto que iniciara una receta vacia
    Receta() : Alimento(), tipo_dieta(""), tiempo_preparacion(0), num_ingredientes(0), disponible(true) {}
    
    // Constructor con parámetros el cual creara una receta con datos especificos
    Receta(std::string nom, int cal, std::string dieta, int tiempo) 
        : Alimento(nom, cal), tipo_dieta(dieta), tiempo_preparacion(tiempo), 
          num_ingredientes(0), disponible(true) {}

    // Empiezo a implementar los getters para obtener los diferentes atributos de la receta
    std::string getTipoDieta() const { return tipo_dieta; }
    int getTiempoPreparacion() const { return tiempo_preparacion; }
    bool getDisponibilidad() const { return disponible; }

    // Método para obtener los ingredientes en un arreglo externo
    void getIngredientes(std::string arr[], int& cant) const {
        for(int i = 0; i < num_ingredientes; i++) {
            arr[i] = ingredientes[i];
        }
        cant = num_ingredientes;
    }

    // Defino los Setters para establecer el tipo de dieta con su validación
    void setTipoDieta(const std::string& dieta) {
        const std::string dietas_validas[] = {"vegetariana", "vegana", "normal"};
        const int tam = 3;
        
        for(int i = 0; i < tam; i++) {
            if (dieta == dietas_validas[i]) {
                tipo_dieta = dieta;
                return;
            }
        }
    }

    // Setter para tiempo de preparación
    void setTiempoPreparacion(int tiempo) {
        if (tiempo > 0 && tiempo < 240) {
            tiempo_preparacion = tiempo;
        }
    }

    // Método para agregar ingrediente
    void agregarIngrediente(const std::string& ingrediente) {
        if (num_ingredientes < MAX_INGREDIENTES) {
            ingredientes[num_ingredientes] = ingrediente;
            num_ingredientes++;
        } else {
            std::cout << "Límite de ingredientes alcanzado." << std::endl;
        }
    }

    // Sobreescritura del método para mostrar información
    void mostrarInformacion() const override {
        Alimento::mostrarInformacion(); //este llama al metodo de la clase padre
        std::cout << "Tipo de dieta: " << tipo_dieta << std::endl;
        std::cout << "Tiempo preparación: " << tiempo_preparacion << " min" << std::endl;
        
        std::cout << "Ingredientes: ";
        for(int i = 0; i < num_ingredientes; i++) {
            std::cout << ingredientes[i];
            if (i < num_ingredientes - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
};

#endif