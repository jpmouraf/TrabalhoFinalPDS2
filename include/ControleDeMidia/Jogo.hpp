#ifndef JOGO_H
#define JOGO_H

#include <string>
#include <iostream>
#include "Midia.hpp"

using namespace std;

/**
 * Classe Jogo, subclasse de Midia.
 * É um tipo de mídia extra da nossa locadora
*/
class Jogo : public Midia {
    private:
/**
 * Defini o tipo de midia como "jogo"
*/
        static const string _tipo;
    public:
/**
 * Construtor da classe Jogo
*/
        Jogo(int codigo_numerico, string titulo, int unidades_disponiveis);
/**
 * Calcula a locação do tipo Jogo.
 * É aplicada uma multa de 5 reais caso o cliente retorno o jogo arranhado.
 * Essa variável é calculada aleatoriamente
*/
        int calcular_locacao(int dias) override;
/**
 * Imprime as informações do jogo.
*/
        void imprimir_info() override;
/**
 * Retorna o tipo "Jogo"
*/
        string gettipo() override;
};

#endif
