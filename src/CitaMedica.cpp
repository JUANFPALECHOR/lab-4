#include "CitaMedica.h"
#include <iostream>

CitaMedica::CitaMedica(Paciente* paciente, Medico* medico, const std::string& fecha, const std::string& hora)
    : paciente(paciente), medico(medico), fecha(fecha), hora(hora) {}

CitaMedica::~CitaMedica() {}

Paciente* CitaMedica::getPaciente() const {
    return paciente;
}

Medico* CitaMedica::getMedico() const {
    return medico;
}

std::string CitaMedica::getFecha() const {
    return fecha;
}

std::string CitaMedica::getHora() const {
    return hora;
}

void CitaMedica::mostrarInformacion() const {
    std::cout << "Fecha: " << fecha << ", Hora: " << hora << std::endl;
    std::cout << "Medico: " << medico->getNombre() << std::endl;
    std::cout << "Paciente: " << paciente->getNombre() << std::endl;
}
