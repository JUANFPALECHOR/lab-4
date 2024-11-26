#include "PacienteAmbulatorio.h"
#include <iostream>

PacienteAmbulatorio::PacienteAmbulatorio(const std::string& nombre, const std::string& identificacion, int edad, const std::string& numeroHistoriaClinica)
    : Paciente(nombre, identificacion, edad, numeroHistoriaClinica) {}

PacienteAmbulatorio::~PacienteAmbulatorio() {}

double PacienteAmbulatorio::calcularCostoConsulta() const {
    
    return 50.0;
}

void PacienteAmbulatorio::mostrarInformacion() const {
    Paciente::mostrarInformacion();
    std::cout << "Tipo de Paciente: Ambulatorio" << std::endl;
    std::cout << "Costo de Consulta: $" << calcularCostoConsulta() << std::endl;
}
