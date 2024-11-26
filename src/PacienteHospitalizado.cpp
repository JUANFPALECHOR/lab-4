#include "PacienteHospitalizado.h"
#include <iostream>

PacienteHospitalizado::PacienteHospitalizado(const std::string& nombre, const std::string& identificacion, int edad, const std::string& numeroHistoriaClinica, int numeroCama, int diasHospitalizacion)
    : Paciente(nombre, identificacion, edad, numeroHistoriaClinica), numeroCama(numeroCama), diasHospitalizacion(diasHospitalizacion) {}

PacienteHospitalizado::~PacienteHospitalizado() {}

int PacienteHospitalizado::getNumeroCama() const {
    return numeroCama;
}

void PacienteHospitalizado::setNumeroCama(int numeroCama) {
    this->numeroCama = numeroCama;
}

int PacienteHospitalizado::getDiasHospitalizacion() const {
    return diasHospitalizacion;
}

void PacienteHospitalizado::setDiasHospitalizacion(int dias) {
    this->diasHospitalizacion = dias;
}

double PacienteHospitalizado::calcularCostoConsulta() const {
    
    return 100.0 * diasHospitalizacion;
}

void PacienteHospitalizado::mostrarInformacion() const {
    Paciente::mostrarInformacion();
    std::cout << "Tipo de Paciente: Hospitalizado" << std::endl;
    std::cout << "Numero de Cama: " << numeroCama << std::endl;
    std::cout << "Dias de Hospitalizacion: " << diasHospitalizacion << std::endl;
    std::cout << "Costo de Consulta: $" << calcularCostoConsulta() << std::endl;
}
