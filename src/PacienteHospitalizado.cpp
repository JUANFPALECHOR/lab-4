#include "PacienteHospitalizado.h"
#include <iostream>

using namespace std;

PacienteHospitalizado::PacienteHospitalizado(const string& nombre, const string& identificacion, int edad, const string& numeroHistoriaClinica, int numeroCama, int diasHospitalizacion)
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
    cout << "Tipo de Paciente: Hospitalizado" << endl;
    cout << "Numero de Cama: " << numeroCama << endl;
    cout << "Dias de Hospitalizacion: " << diasHospitalizacion << endl;
    cout << "Costo de Consulta: $" << calcularCostoConsulta() << endl;
}
