#ifndef PACIENTEHOSPITALIZADO_H
#define PACIENTEHOSPITALIZADO_H

#include "Paciente.h"

class PacienteHospitalizado : public Paciente {
private:
    int numeroCama;
    int diasHospitalizacion;

public:
    PacienteHospitalizado(const std::string& nombre, const std::string& identificacion, int edad, const std::string& numeroHistoriaClinica, int numeroCama, int diasHospitalizacion);
    ~PacienteHospitalizado();

    
    int getNumeroCama() const;
    void setNumeroCama(int numeroCama);

    int getDiasHospitalizacion() const;
    void setDiasHospitalizacion(int dias);

    double calcularCostoConsulta() const override;
    void mostrarInformacion() const override;
};

#endif 
