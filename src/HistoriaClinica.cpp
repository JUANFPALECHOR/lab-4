#include "HistoriaClinica.h"
#include <iostream>

using namespace std;

HistoriaClinica::HistoriaClinica(const string& numeroHistoria)
    : numeroHistoria(numeroHistoria) {}

HistoriaClinica::~HistoriaClinica() {}

void HistoriaClinica::agregarRegistro(const string& registro) {
    registros.push_back(registro);
}

void HistoriaClinica::mostrarHistoria() const {
    cout << "Historia Clinica No: " << numeroHistoria << endl;
    for (const auto& registro : registros) {
        cout << "- " << registro << endl;
    }
}

string HistoriaClinica::getNumeroHistoria() const {
    return numeroHistoria;
}
