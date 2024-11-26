#include <iostream>
#include <vector>
#include <map>
#include "Medico.h"
#include "PacienteAmbulatorio.h"
#include "PacienteHospitalizado.h"
#include "CitaMedica.h"
#include "HistoriaClinica.h"
#include "Utilidades.h"

void mostrarMenu() {
    std::cout << "\n--- Sistema de Gestion de Pacientes ---\n";
    std::cout << "1. Registrar Paciente\n";
    std::cout << "2. Registrar Medico\n";
    std::cout << "3. Agendar Cita Medica\n";
    std::cout << "4. Mostrar Pacientes Ordenados y Agrupados\n";
    std::cout << "5. Buscar Historia Clinica\n";
    std::cout << "6. Mostrar Cantidad de Citas Diarias por Tipo de Paciente\n";
    std::cout << "7. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int main() {
    std::vector<Paciente*> pacientes;
    std::vector<Medico*> medicos;
    std::vector<CitaMedica*> citas;
    std::map<std::string, HistoriaClinica*> historiasClinicas;

    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                // Registro de Pasient
                std::string nombre, identificacion, numeroHistoria;
                int edad, tipoPaciente;

                std::cout << "Ingrese nombree: ";
                std::cin >> nombre;
                std::cout << "Ingrese CC: ";
                std::cin >> identificacion;
                std::cout << "Ingrese edad: ";
                std::cin >> edad;
                std::cout << "Ingrese numero de historia clinica: ";
                std::cin >> numeroHistoria;
                std::cout << "Tipo de Paciente (1-Ambulatorio, 2-Hospitalizado): ";
                std::cin >> tipoPaciente;

                if (tipoPaciente == 1) {
                    PacienteAmbulatorio* pa = new PacienteAmbulatorio(nombre, identificacion, edad, numeroHistoria);
                    pacientes.push_back(pa);
                } else if (tipoPaciente == 2) {
                    int numeroCama, diasHospitalizacion;
                    std::cout << "Ingrese numero de cama: ";
                    std::cin >> numeroCama;
                    std::cout << "Ingrese dias de hospitalizacion: ";
                    std::cin >> diasHospitalizacion;

                    PacienteHospitalizado* ph = new PacienteHospitalizado(nombre, identificacion, edad, numeroHistoria, numeroCama, diasHospitalizacion);
                    pacientes.push_back(ph);
                } else {
                    std::cout << "Tipo de paciente invalido.\n";
                }

                // aqui creo la historia clinica
                historiasClinicas[numeroHistoria] = new HistoriaClinica(numeroHistoria);

                break;
            }
            case 2: {
                // Registro del doc
                std::string nombre, identificacion, especialidad;
                int edad;

                std::cout << "Ingrese nombre: ";
                std::cin >> nombre;
                std::cout << "Ingrese identificacion: ";
                std::cin >> identificacion;
                std::cout << "Ingrese edad: ";
                std::cin >> edad;
                std::cout << "Ingrese especialidad: ";
                std::cin >> especialidad;

                Medico* medico = new Medico(nombre, identificacion, edad, especialidad);
                medicos.push_back(medico);

                break;
            }
            case 3: {
                // Agendar Cita 
                std::string idPaciente, idMedico, fecha, hora;

                std::cout << "Ingrese identificacion del paciente: ";
                std::cin >> idPaciente;
                std::cout << "Ingrese identificacion del medico: ";
                std::cin >> idMedico;
                std::cout << "Ingrese fecha (DD/MM/AAAA): ";
                std::cin >> fecha;
                std::cout << "Ingrese hora (HH:MM): ";
                std::cin >> hora;

                Paciente* paciente = nullptr;
                Medico* medico = nullptr;

                for (auto p : pacientes) {
                    if (p->getIdentificacion() == idPaciente) {
                        paciente = p;
                        break;
                    }
                }

                for (auto m : medicos) {
                    if (m->getIdentificacion() == idMedico) {
                        medico = m;
                        break;
                    }
                }

                if (paciente && medico) {
                    CitaMedica* cita = new CitaMedica(paciente, medico, fecha, hora);
                    citas.push_back(cita);
                    std::cout << "Cita agendada exitosamene.\n";
                } else {
                    std::cout << "Paciente o Medico no encontrado.\n";
                }

                break;
            }
            case 4: {
                // Muestro los Pacientes 
                Utilidades::ordenarPacientesPorNombre(pacientes);
                Utilidades::agruparPacientesPorTipo(pacientes);
                break;
            }
            case 5: {
                // aqui busco la Historia clinica
                std::string numeroHistoria;
                std::cout << "Ingrese numero de historia clinica: ";
                std::cin >> numeroHistoria;

                if (historiasClinicas.find(numeroHistoria) != historiasClinicas.end()) {
                    historiasClinicas[numeroHistoria]->mostrarHistoria();
                } else {
                    std::cout << "Historia clinica no encontrada.\n";
                }

                break;
            }
            case 6: {
                // Mostrar Cantidad de Citas Diarias por Tipo de Paciente
                int contadorAmbulatorio = 0;
                int contadorHospitalizado = 0;

                for (auto cita : citas) {
                    if (dynamic_cast<PacienteAmbulatorio*>(cita->getPaciente())) {
                        contadorAmbulatorio++;
                    } else if (dynamic_cast<PacienteHospitalizado*>(cita->getPaciente())) {
                        contadorHospitalizado++;
                    }
                }

                std::cout << "Cantidad de citas para pacientes ambulatorios: " << contadorAmbulatorio << std::endl;
                std::cout << "Cantidad de citas para pacientes hospitalizados: " << contadorHospitalizado << std::endl;

                break;
            }
            case 7: {
                std::cout << "Saliendo del sistema...\n";
                break;
            }
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }

    } while (opcion != 7);

    // Libero la memoria
    for (auto p : pacientes) delete p;
    for (auto m : medicos) delete m;
    for (auto c : citas) delete c;
    for (auto& hc : historiasClinicas) delete hc.second;

    return 0;
}
