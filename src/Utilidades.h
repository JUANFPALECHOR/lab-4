#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>
#include <vector>
#include "Paciente.h"

namespace Utilidades {
    void ordenarPacientesPorNombre(std::vector<Paciente*>& pacientes);
    void agruparPacientesPorTipo(const std::vector<Paciente*>& pacientes);
}

#endif 
