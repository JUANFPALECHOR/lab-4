#include "Paciente.h"
#include <iostream>

Paciente::Paciente(const std::string& nombre, const std::string& identificacion, int edad, const std::string& numeroHistoriaClinica)
    : Persona(nombre, identificacion, edad), numeroHistoriaClinica(numeroHistoriaClinica) {}

Paciente::~Paciente() {}

std::string Paciente::getNumeroHistoriaClinica() const {
    return numeroHistoriaClinica;
}

void Paciente::setNumeroHistoriaClinica(const std::string& numeroHistoriaClinica) {
    this->numeroHistoriaClinica = numeroHistoriaClinica;
}

void Paciente::mostrarInformacion() const {
    Persona::mostrarInformacion();
    std::cout << "Numero de Historia Clinica: " << numeroHistoriaClinica << std::endl;
}
