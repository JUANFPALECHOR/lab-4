#include "Persona.h"
#include <iostream>

Persona::Persona(const std::string& nombre, const std::string& identificacion, int edad)
    : nombre(nombre), identificacion(identificacion), edad(edad) {}

Persona::~Persona() {}

std::string Persona::getNombre() const {
    return nombre;
}

std::string Persona::getIdentificacion() const {
    return identificacion;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Persona::setIdentificacion(const std::string& identificacion) {
    this->identificacion = identificacion;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::mostrarInformacion() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Identificacion: " << identificacion << std::endl;
    std::cout << "Edad: " << edad << std::endl;
}
