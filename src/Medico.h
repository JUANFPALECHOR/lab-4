#ifndef MEDICO_H
#define MEDICO_H

#include "Persona.h"
#include <string>

class Medico : public Persona {
private:
    std::string especialidad;

public:
    Medico(const std::string& nombre, const std::string& identificacion, int edad, const std::string& especialidad);
    ~Medico();

    
    std::string getEspecialidad() const;
    void setEspecialidad(const std::string& especialidad);

    void mostrarInformacion() const override;
};

#endif 
