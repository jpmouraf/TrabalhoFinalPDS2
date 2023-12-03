#ifndef JOGO_H
#define JOGO_H

#include <string>
#include <iostream>
#include "Midia.hpp"

/**
 * Classe Jogo, subclasse de Midia.
 * É um tipo de mídia extra da nossa locadora
*/
class Jogo : public Midia {
    public:
/**
 * Construtor da classe Jogo
*/
        Jogo(int codigo_numerico, std::string titulo, int unidades_disponiveis);

/**
 * Imprime as informações do jogo.
*/
        void imprimir_info() override;
/**
 * Calcula a locação do tipo Jogo.
 * É aplicada uma multa de 5 reais caso o cliente retorno o jogo arranhado.
 * Essa variável é calculada aleatoriamente
*/
        int calcular_locacao(int dias) override;
};

#endif
