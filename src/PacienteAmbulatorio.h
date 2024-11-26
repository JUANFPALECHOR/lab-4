#ifndef PACIENTEAMBULATORIO_H
#define PACIENTEAMBULATORIO_H

#include "Paciente.h"

class PacienteAmbulatorio : public Paciente {
public:
    PacienteAmbulatorio(const std::string& nombre, const std::string& identificacion, int edad, const std::string& numeroHistoriaClinica);
    ~PacienteAmbulatorio();

    double calcularCostoConsulta() const override;
    void mostrarInformacion() const override;
};

#endif 
