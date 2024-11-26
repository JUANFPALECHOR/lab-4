#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
protected:
    std::string nombre;
    std::string identificacion;
    int edad;

public:
    Persona(const std::string& nombre, const std::string& identificacion, int edad);
    virtual ~Persona();

    
    std::string getNombre() const;
    std::string getIdentificacion() const;
    int getEdad() const;

    
    void setNombre(const std::string& nombre);
    void setIdentificacion(const std::string& identificacion);
    void setEdad(int edad);

    
    virtual void mostrarInformacion() const;
};

#endif 
