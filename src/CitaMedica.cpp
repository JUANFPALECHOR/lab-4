#include "CitaMedica.h"
#include <iostream>

using namespace std;

CitaMedica::CitaMedica(Paciente* paciente, Medico* medico, const string& fecha, const string& hora)
    : paciente(paciente), medico(medico), fecha(fecha), hora(hora) {}

CitaMedica::~CitaMedica() {}

Paciente* CitaMedica::getPaciente() const {
    return paciente;
}

Medico* CitaMedica::getMedico() const {
    return medico;
}

string CitaMedica::getFecha() const {
    return fecha;
}

string CitaMedica::getHora() const {
    return hora;
}

void CitaMedica::mostrarInformacion() const {
    cout << "Fecha: " << fecha << ", Hora: " << hora << endl;
    cout << "Medico: " << medico->getNombre() << endl;
    cout << "Paciente: " << paciente->getNombre() << endl;
}
