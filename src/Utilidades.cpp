#include "Utilidades.h"
#include "PacienteAmbulatorio.h"
#include "PacienteHospitalizado.h"
#include <algorithm>
#include <iostream>

void Utilidades::ordenarPacientesPorNombre(std::vector<Paciente*>& pacientes) {
    std::sort(pacientes.begin(), pacientes.end(), [](Paciente* a, Paciente* b) {
        return a->getNombre() < b->getNombre();
    });
}

void Utilidades::agruparPacientesPorTipo(const std::vector<Paciente*>& pacientes) {
    std::cout << "\nPacientes Ambulatorios:" << std::endl;
    for (auto paciente : pacientes) {
        if (dynamic_cast<PacienteAmbulatorio*>(paciente)) {
            paciente->mostrarInformacion();
            std::cout << "-------------------------" << std::endl;
        }
    }

    std::cout << "\nPacientes Hospitalizados:" << std::endl;
    for (auto paciente : pacientes) {
        if (dynamic_cast<PacienteHospitalizado*>(paciente)) {
            paciente->mostrarInformacion();
            std::cout << "-------------------------" << std::endl;
        }
    }
}
