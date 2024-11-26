#include "Persona.h"
#include <iostream>

using namespace std;

Persona::Persona(const string& nombre, const string& identificacion, int edad)
    : nombre(nombre), identificacion(identificacion), edad(edad) {}

Persona::~Persona() {}

string Persona::getNombre() const {
    return nombre;
}

string Persona::getIdentificacion() const {
    return identificacion;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void Persona::setIdentificacion(const string& identificacion) {
    this->identificacion = identificacion;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::mostrarInformacion() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Identificacion: " << identificacion << endl;
    cout << "Edad: " << edad << endl;
}
