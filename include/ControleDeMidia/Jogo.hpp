#ifndef JOGO_H
#define JOGO_H

#include <string>
#include <iostream>
#include "Midia.hpp"

using namespace std;

class Jogo : public Midia {
    public:
        Jogo(int codigo_numerico, string titulo, int unidades_disponiveis);
        int calcular_locacao(int dias) override;
        void imprimir_info() override;
};

#endif