#include <iostream>
#include <vector>
#include <limits>
#include "receta.h"
#include "usuario.h"

void mostrarMenu() {
    std::cout << "\n--- MENÚ PRINCIPAL ---\n";
    std::cout << "1. Agregar Receta\n";
    std::cout << "2. Ver Recetas\n";
    std::cout << "3. Buscar Recetas por Tipo de Dieta\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opción: ";
}

void agregarIngredientesReceta(Receta& receta) {
    // Método para agregar ingredientes a una receta
    std::string ingrediente;
    char continuar;
    
    do {
        std::cout << "Ingrese un ingrediente (o presione Enter para terminar): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, ingrediente);
        
        if (!ingrediente.empty()) {
            receta.agregarIngrediente(ingrediente);
        }
        
        std::cout << "¿Desea agregar otro ingrediente? (s/n): ";
        std::cin >> continuar;
    } while (continuar == 's' || continuar == 'S');
}

int main() {
    std::vector<Receta> recetas;
    Usuario usuario("Admin", "admin@cocina.com");

    // Recetas por defecto
    Receta ensaladaVegetariana("Ensalada Verde", 150, "vegetariana", 15);
    ensaladaVegetariana.agregarIngrediente("Lechuga");
    ensaladaVegetariana.agregarIngrediente("Tomate");
    ensaladaVegetariana.agregarIngrediente("Pepino");
    recetas.push_back(ensaladaVegetariana);
    usuario.publicarReceta(ensaladaVegetariana);

    Receta polloVegano("Pollo de Proteína Vegetal", 250, "vegana", 30);
    polloVegano.agregarIngrediente("Tofu");
    polloVegano.agregarIngrediente("Salsa de soya");
    polloVegano.agregarIngrediente("Especias");
    recetas.push_back(polloVegano);
    usuario.publicarReceta(polloVegano);

    Receta pastaCarbonaraTradicional("Pasta Carbonara", 450, "normal", 25);
    pastaCarbonaraTradicional.agregarIngrediente("Pasta");
    pastaCarbonaraTradicional.agregarIngrediente("Huevo");
    pastaCarbonaraTradicional.agregarIngrediente("Panceta");
    pastaCarbonaraTradicional.agregarIngrediente("Queso parmesano");
    recetas.push_back(pastaCarbonaraTradicional);
    usuario.publicarReceta(pastaCarbonaraTradicional);

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch(opcion) {
            case 1: {
                std::string nombre, tipo_dieta;
                int calorias, tiempo;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                std::cout << "Nombre de la receta: ";
                std::getline(std::cin, nombre);
                
                std::cout << "Calorías: ";
                std::cin >> calorias;
                
                std::cout << "Tipo de dieta (vegetariana/vegana/normal): ";
                std::cin >> tipo_dieta;
                
                std::cout << "Tiempo de preparación (minutos): ";
                std::cin >> tiempo;

                Receta nueva_receta(nombre, calorias, tipo_dieta, tiempo);
                
                // Agregar ingredientes a la nueva receta
                agregarIngredientesReceta(nueva_receta);

                recetas.push_back(nueva_receta);
                usuario.publicarReceta(nueva_receta);
                
                std::cout << "Receta agregada exitosamente.\n";
                break;
            }
            case 2: {
                std::cout << "Total de recetas: " << recetas.size() << std::endl;
                for (const auto& receta : recetas) {
                    receta.mostrarInformacion();
                    std::cout << "------------------------\n";
                }
                break;
            }
            case 3: {
                std::string tipo_dieta;
                std::cout << "Ingrese tipo de dieta: ";
                std::cin >> tipo_dieta;

                bool encontrada = false;
                for (const auto& receta : recetas) {
                    if (receta.getTipoDieta() == tipo_dieta) {
                        receta.mostrarInformacion();
                        std::cout << "------------------------\n";
                        encontrada = true;
                    }
                }
                
                if (!encontrada) {
                    std::cout << "No se encontraron recetas para este tipo de dieta.\n";
                }
                break;
            }
            case 4:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
        }
    } while (opcion != 4);

    return 0;
}