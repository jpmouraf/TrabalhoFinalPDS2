#ifndef FITA_H
#define FITA_H

#include <string>
#include <iostream>
#include "Midia.hpp"

using namespace std;

class Fita : public Midia {
    public:
        bool _isRebobinada;
        Fita(int codigo_numerico, string titulo, int unidades_disponiveis);
        int calcular_locacao(int dias) override;
        void imprimir_info() override;
};

#endif