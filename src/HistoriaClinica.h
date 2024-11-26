#ifndef HISTORIACLINICA_H
#define HISTORIACLINICA_H

#include <string>
#include <vector>

class HistoriaClinica {
private:
    std::string numeroHistoria;
    std::vector<std::string> registros;

public:
    HistoriaClinica(const std::string& numeroHistoria);
    ~HistoriaClinica();

    void agregarRegistro(const std::string& registro);
    void mostrarHistoria() const;
    std::string getNumeroHistoria() const;
};

#endif 
