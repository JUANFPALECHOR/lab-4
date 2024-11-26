cmake_minimum_required(VERSION 3.10)
project(ProyectoHospital)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProyectoHospital
    src/main.cpp
    src/Persona.cpp
    src/Medico.cpp
    src/Paciente.cpp
    src/PacienteAmbulatorio.cpp
    src/PacienteHospitalizado.cpp
    src/CitaMedica.cpp
    src/HistoriaClinica.cpp
    src/Utilidades.cpp
)
