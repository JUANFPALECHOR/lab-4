#ifndef PACIENTE_H
#define PACIENTE_H

#include "Persona.h"
#include <string>

class Paciente : public Persona {
protected:
    std::string numeroHistoriaClinica;

public:
    Paciente(const std::string& nombre, const std::string& identificacion, int edad, const std::string& numeroHistoriaClinica);
    virtual ~Paciente();

    
    std::string getNumeroHistoriaClinica() const;
    void setNumeroHistoriaClinica(const std::string& numeroHistoriaClinica);

    virtual double calcularCostoConsulta() const = 0; // Aqui un Método polimórfico profe
    virtual void mostrarInformacion() const override;
};

#endif 
