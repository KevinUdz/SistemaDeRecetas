#ifndef ALIMENTO_H  // Directiva de preprocesador para evitar múltiples inclusiones del mismo header
#define ALIMENTO_H

#include <string> //libreria para manejo de cadenas
#include <iostream> //libreria para entrada/salida de datos

// Creo la clase llamada "Alimento" 
class Alimento {
protected: //este es un modificador de acceso que permitira a las clases derivadas lograr acceder a esos atributos
    std::string nombre; //este sera el nombre del alimento
    int calorias; //esta sera el número de calorias del alimento seleccionado

public:
    Alimento() : nombre(""), calorias(0) {}
    // hago el constructor parametrizado: me va a permitircrear un aliemtno con propiedades como el "nombre" y  sus "calorias" especificas
    Alimento(std::string n, int cal) : nombre(n), calorias(cal) {}

// este sera mi primer getter para obtener el nombre del alimento
    virtual std::string getNombre() const { return nombre; }
    // defino mi segundo getter para obtener las calorias del alimento
    virtual int getCalorias() const { return calorias; }
    // este sera mi primer setter para lograr estableceer el nombre con su respectiva validacion para evitar nombres vacios
    virtual void setNombre(const std::string& n) { 
        if (!n.empty()) nombre = n; 
    }
    
    // defino mi segundo setter para establecer las calorias con su validacion para evitar valores negativos
    virtual void setCalorias(int cal) { 
        if (cal >= 0) calorias = cal; 
    }

    // aqui muestro la informacion basica del alimento
    virtual void mostrarInformacion() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Calorías: " << calorias << std::endl;
    }
};

#endif