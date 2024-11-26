#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include "Medico.h"
#include "PacienteAmbulatorio.h"
#include "PacienteHospitalizado.h"
#include "CitaMedica.h"
#include "HistoriaClinica.h"
#include "Utilidades.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::getline;
using std::numeric_limits;
using std::streamsize;

void mostrarMenu() {
    cout << "\n--- Sistema de Gestion de Pacientes ---\n";
    cout << "1. Registrar Paciente\n";
    cout << "2. Registrar Medico\n";
    cout << "3. Agendar Cita Medica\n";
    cout << "4. Mostrar Pacientes Ordenados y Agrupados\n";
    cout << "5. Buscar Historia Clinica\n";
    cout << "6. Mostrar Cantidad de Citas Diarias por Tipo de Paciente\n";
    cout << "7. Informe Medico\n";
    cout << "8. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    vector<Paciente*> pacientes;
    vector<Medico*> medicos;
    vector<CitaMedica*> citas;
    map<string, HistoriaClinica*> historiasClinicas;

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer

        switch (opcion) {
            case 1: {
                // Registro de Paciente
                string nombre, identificacion, numeroHistoria;
                int edad, tipoPaciente;

                cout << "Ingrese nombre: ";
                getline(cin, nombre);
                cout << "Ingrese identificacion: ";
                getline(cin, identificacion);
                cout << "Ingrese edad: ";
                cin >> edad;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Ingrese numero de historia clinica: ";
                getline(cin, numeroHistoria);
                cout << "Tipo de Paciente (1-Ambulatorio, 2-Hospitalizado): ";
                cin >> tipoPaciente;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

                if (tipoPaciente == 1) {
                    PacienteAmbulatorio* pa = new PacienteAmbulatorio(nombre, identificacion, edad, numeroHistoria);
                    pacientes.push_back(pa);
                } else if (tipoPaciente == 2) {
                    int numeroCama, diasHospitalizacion;
                    cout << "Ingrese numero de cama: ";
                    cin >> numeroCama;
                    cout << "Ingrese dias de hospitalizacion: ";
                    cin >> diasHospitalizacion;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

                    PacienteHospitalizado* ph = new PacienteHospitalizado(nombre, identificacion, edad, numeroHistoria, numeroCama, diasHospitalizacion);
                    pacientes.push_back(ph);
                } else {
                    cout << "Tipo de paciente invalido.\n";
                }

                
                historiasClinicas[identificacion] = new HistoriaClinica(numeroHistoria);

                break;
            }
            case 2: {
                
                string nombre, identificacion, especialidad;
                int edad;

                cout << "Ingrese nombre: ";
                getline(cin, nombre);
                cout << "Ingrese identificacion: ";
                getline(cin, identificacion);
                cout << "Ingrese edad: ";
                cin >> edad;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Ingrese especialidad: ";
                getline(cin, especialidad);

                Medico* medico = new Medico(nombre, identificacion, edad, especialidad);
                medicos.push_back(medico);

                break;
            }
            case 3: {
                // Agendar Cita Medica
                string idPaciente, idMedico, fecha, hora;

                cout << "Ingrese identificacion del paciente: ";
                getline(cin, idPaciente);
                cout << "Ingrese identificacion del medico: ";
                getline(cin, idMedico);
                cout << "Ingrese fecha (DD/MM/AAAA): ";
                getline(cin, fecha);
                cout << "Ingrese hora (HH:MM): ";
                getline(cin, hora);

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
                    cout << "Cita agendada exitosamente.\n";
                } else {
                    cout << "Paciente o Medico no encontrado.\n";
                }

                break;
            }
            case 4: {
                // Mostrar Pacientes Ordenados y Agrupados
                Utilidades::ordenarPacientesPorNombre(pacientes);
                Utilidades::agruparPacientesPorTipo(pacientes);
                break;
            }
            case 5: {
               
                string identificacion, numeroHistoria;
                cout << "Ingrese identificacion del paciente: ";
                getline(cin, identificacion);
                cout << "Ingrese numero de historia clinica: ";
                getline(cin, numeroHistoria);

                
                Paciente* paciente = nullptr;
                for (auto p : pacientes) {
                    if (p->getIdentificacion() == identificacion && p->getNumeroHistoriaClinica() == numeroHistoria) {
                        paciente = p;
                        break;
                    }
                }

                if (paciente) {
                    
                    cout << "\n--- Información del Paciente ---\n";
                    paciente->mostrarInformacion();

                    
                    if (dynamic_cast<PacienteAmbulatorio*>(paciente)) {
                        cout << "Tipo de Paciente: Ambulatorio\n";
                    } else if (dynamic_cast<PacienteHospitalizado*>(paciente)) {
                        cout << "Tipo de Paciente: Hospitalizado\n";
                    }

                   
                    auto it = historiasClinicas.find(identificacion);
                    if (it != historiasClinicas.end()) {
                        cout << "\n--- Historia Clínica ---\n";
                        it->second->mostrarHistoria();
                    } else {
                        cout << "Historia clínica no encontrada.\n";
                    }
                } else {
                    cout << "No se encontró un paciente con esa identificación y número de historia clínica.\n";
                }

                break;
            }
            case 6: {
                
                int contadorAmbulatorio = 0;
                int contadorHospitalizado = 0;

                for (auto cita : citas) {
                    if (dynamic_cast<PacienteAmbulatorio*>(cita->getPaciente())) {
                        contadorAmbulatorio++;
                    } else if (dynamic_cast<PacienteHospitalizado*>(cita->getPaciente())) {
                        contadorHospitalizado++;
                    }
                }

                cout << "Cantidad de citas para pacientes ambulatorios: " << contadorAmbulatorio << endl;
                cout << "Cantidad de citas para pacientes hospitalizados: " << contadorHospitalizado << endl;

                break;
            }
            case 7: {
                // Informe Médico
                string identificacion;
                cout << "Ingrese identificacion del paciente: ";
                getline(cin, identificacion);

                // ti
                Paciente* paciente = nullptr;
                for (auto p : pacientes) {
                    if (p->getIdentificacion() == identificacion) {
                        paciente = p;
                        break;
                    }
                }

                if (paciente) {
                    cout << "\n--- Información del Paciente ---\n";
                    paciente->mostrarInformacion();
                } else {
                    cout << "Paciente no encontrado.\n";
                }

                break;
            }
            case 8: {
                cout << "Saliendo del sistema...\n";
                break;
            }
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
                break;
        }

    } while (opcion != 8);

   
    for (auto p : pacientes) delete p;
    for (auto m : medicos) delete m;
    for (auto c : citas) delete c;
    for (auto& hc : historiasClinicas) delete hc.second;

    return 0;
}
