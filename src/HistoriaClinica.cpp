#include "HistoriaClinica.h"
#include <iostream>

HistoriaClinica::HistoriaClinica(const std::string& numeroHistoria)
    : numeroHistoria(numeroHistoria) {}

HistoriaClinica::~HistoriaClinica() {}

void HistoriaClinica::agregarRegistro(const std::string& registro) {
    registros.push_back(registro);
}

void HistoriaClinica::mostrarHistoria() const {
    std::cout << "Historia Clinica No: " << numeroHistoria << std::endl;
    for (const auto& registro : registros) {
        std::cout << "- " << registro << std::endl;
    }
}

std::string HistoriaClinica::getNumeroHistoria() const {
    return numeroHistoria;
}
