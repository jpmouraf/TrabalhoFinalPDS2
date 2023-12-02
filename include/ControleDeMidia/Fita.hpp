#ifndef FITA_H
#define FITA_H

#include <string>
#include <iostream>
#include "Midia.hpp"

class Fita : public Midia {
    public:
        Fita(int codigo_numerico, std::string titulo, int unidades_disponiveis);

        void imprimir_info() override;
        int calcular_locacao(int dias) override;
};

#endif