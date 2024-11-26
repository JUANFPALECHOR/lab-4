#include "PacienteAmbulatorio.h"
#include <iostream>

using namespace std;

PacienteAmbulatorio::PacienteAmbulatorio(const string& nombre, const string& identificacion, int edad, const string& numeroHistoriaClinica)
    : Paciente(nombre, identificacion, edad, numeroHistoriaClinica) {}

PacienteAmbulatorio::~PacienteAmbulatorio() {}

double PacienteAmbulatorio::calcularCostoConsulta() const {
    return 50.0;
}

void PacienteAmbulatorio::mostrarInformacion() const {
    Paciente::mostrarInformacion();
    cout << "Tipo de Paciente: Ambulatorio" << endl;
    cout << "Costo de Consulta: $" << calcularCostoConsulta() << endl;
}
