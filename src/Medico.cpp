#include "Medico.h"
#include <iostream>

Medico::Medico(const std::string& nombre, const std::string& identificacion, int edad, const std::string& especialidad)
    : Persona(nombre, identificacion, edad), especialidad(especialidad) {}

Medico::~Medico() {}

std::string Medico::getEspecialidad() const {
    return especialidad;
}

void Medico::setEspecialidad(const std::string& especialidad) {
    this->especialidad = especialidad;
}

void Medico::mostrarInformacion() const {
    Persona::mostrarInformacion();
    std::cout << "Especialidad: " << especialidad << std::endl;
}
