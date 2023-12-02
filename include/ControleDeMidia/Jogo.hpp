#ifndef JOGO_H
#define JOGO_H

#include <string>
#include <iostream>
#include "Midia.hpp"

class Jogo : public Midia {
    public:
        Jogo(int codigo_numerico, std::string titulo, int unidades_disponiveis);

        void imprimir_info() override;
        int calcular_locacao(int dias) override;
};

#endif