#include "Paciente.h"
#include <iostream>

using namespace std;

Paciente::Paciente(const string& nombre, const string& identificacion, int edad, const string& numeroHistoriaClinica)
    : Persona(nombre, identificacion, edad), numeroHistoriaClinica(numeroHistoriaClinica) {}

Paciente::~Paciente() {}

string Paciente::getNumeroHistoriaClinica() const {
    return numeroHistoriaClinica;
}

void Paciente::setNumeroHistoriaClinica(const string& numeroHistoriaClinica) {
    this->numeroHistoriaClinica = numeroHistoriaClinica;
}

void Paciente::mostrarInformacion() const {
    Persona::mostrarInformacion();
    cout << "Numero de Historia Clinica: " << numeroHistoriaClinica << endl;
}
