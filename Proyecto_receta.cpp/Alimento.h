#ifndef ALIMENTO_H
#define ALIMENTO_H

#include <string>
#include <iostream>

class Alimento {
protected:
    std::string nombre;
    int calorias;

public:
    Alimento() : nombre(""), calorias(0) {}
    Alimento(std::string n, int cal) : nombre(n), calorias(cal) {}

    virtual std::string getNombre() const { return nombre; }
    virtual int getCalorias() const { return calorias; }
    
    virtual void setNombre(const std::string& n) { 
        if (!n.empty()) nombre = n; 
    }
    
    virtual void setCalorias(int cal) { 
        if (cal >= 0) calorias = cal; 
    }

    virtual void mostrarInformacion() const {
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Calorías: " << calorias << std::endl;
    }
};

#endif