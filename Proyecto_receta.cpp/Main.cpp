#include <iostream>
#include <string>
#include <limits>
#include "receta.h"
#include "usuario.h"
//Funcion que me mostrara el menu principal en la terminal
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
    // Cambio de vector a arreglo estático
    static const int MAX_RECETAS = 50;  // Máximo de recetas que puede tener el programa
    Receta recetas[MAX_RECETAS];
    int num_recetas = 0;

    Usuario usuario("Admin", "admin@cocina.com");

    // Implemento recetas que vienen por defecto en el programa
    Receta ensaladaVegetariana("Ensalada Verde", 150, "vegetariana", 15);
    ensaladaVegetariana.agregarIngrediente("Lechuga");
    ensaladaVegetariana.agregarIngrediente("Tomate");
    ensaladaVegetariana.agregarIngrediente("Pepino");
    recetas[num_recetas] = ensaladaVegetariana;
    num_recetas++;
    usuario.publicarReceta(ensaladaVegetariana);

    Receta polloVegano("Pollo de Proteína Vegetal", 250, "vegana", 30);
    polloVegano.agregarIngrediente("Tofu");
    polloVegano.agregarIngrediente("Salsa de soya");
    polloVegano.agregarIngrediente("Especias");
    recetas[num_recetas] = polloVegano;
    num_recetas++;
    usuario.publicarReceta(polloVegano);

    Receta pastaCarbonaraTradicional("Pasta Carbonara", 450, "normal", 25);
    pastaCarbonaraTradicional.agregarIngrediente("Pasta");
    pastaCarbonaraTradicional.agregarIngrediente("Huevo");
    pastaCarbonaraTradicional.agregarIngrediente("Panceta");
    pastaCarbonaraTradicional.agregarIngrediente("Queso parmesano");
    recetas[num_recetas] = pastaCarbonaraTradicional;
    num_recetas++;
    usuario.publicarReceta(pastaCarbonaraTradicional);

    Receta pastaAlfredo("Pasta Alfredo", 416, "normal", 40);
    pastaAlfredo.agregarIngrediente("Media barra de Mantequilla");
    pastaAlfredo.agregarIngrediente("1 Media crema");
    pastaAlfredo.agregarIngrediente("Queso Parmeso al gusto");
    pastaAlfredo.agregarIngrediente("1 pasta Fettucine Alfredo");
    pastaAlfredo.agregarIngrediente("1 diente de Ajo");
    pastaAlfredo.agregarIngrediente("1 cucharadita de Sal");
    recetas[num_recetas] = pastaAlfredo;
    num_recetas++;
    usuario.publicarReceta(pastaAlfredo);

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch(opcion) {
            case 1: {
                if (num_recetas >= MAX_RECETAS) {
                    std::cout << "Límite de recetas alcanzado.\n";
                    break;
                }

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
                
                agregarIngredientesReceta(nueva_receta);

                recetas[num_recetas] = nueva_receta;
                num_recetas++;
                usuario.publicarReceta(nueva_receta);
                
                std::cout << "Receta agregada exitosamente.\n";
                break;
            }
            case 2: {
                std::cout << "Total de recetas: " << num_recetas << std::endl;
                for (int i = 0; i < num_recetas; i++) {
                    recetas[i].mostrarInformacion();
                    std::cout << "------------------------\n";
                }
                break;
            }
            case 3: {
                std::string tipo_dieta;
                std::cout << "Ingrese tipo de dieta: (vegana, vegetariana, normal) ";
                std::cin >> tipo_dieta;

                bool encontrada = false;
                for (int i = 0; i < num_recetas; i++) {
                    if (recetas[i].getTipoDieta() == tipo_dieta) {
                        recetas[i].mostrarInformacion();
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