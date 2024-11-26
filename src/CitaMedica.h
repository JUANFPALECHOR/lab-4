#ifndef CITAMEDICA_H
#define CITAMEDICA_H

#include "Paciente.h"
#include "Medico.h"
#include <string>

class CitaMedica {
private:
    Paciente* paciente;
    Medico* medico;
    std::string fecha;
    std::string hora;

public:
    CitaMedica(Paciente* paciente, Medico* medico, const std::string& fecha, const std::string& hora);
    ~CitaMedica();

    
    Paciente* getPaciente() const;
    Medico* getMedico() const;
    std::string getFecha() const;
    std::string getHora() const;

    void mostrarInformacion() const;
};

#endif 
