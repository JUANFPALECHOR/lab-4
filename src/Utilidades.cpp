#include "Utilidades.h"
#include "PacienteAmbulatorio.h"
#include "PacienteHospitalizado.h"
#include <algorithm>
#include <iostream>

using namespace std;

void Utilidades::ordenarPacientesPorNombre(vector<Paciente*>& pacientes) {
    sort(pacientes.begin(), pacientes.end(), [](Paciente* a, Paciente* b) {
        return a->getNombre() < b->getNombre();
    });
}

void Utilidades::agruparPacientesPorTipo(const vector<Paciente*>& pacientes) {
    cout << "\nPacientes Ambulatorios:" << endl;
    for (auto paciente : pacientes) {
        if (dynamic_cast<PacienteAmbulatorio*>(paciente)) {
            paciente->mostrarInformacion();
            cout << "-------------------------" << endl;
        }
    }

    cout << "\nPacientes Hospitalizados:" << endl;
    for (auto paciente : pacientes) {
        if (dynamic_cast<PacienteHospitalizado*>(paciente)) {
            paciente->mostrarInformacion();
            cout << "-------------------------" << endl;
        }
    }
}
