#ifndef FITA_H
#define FITA_H

#include <string>
#include <iostream>
#include "Midia.hpp"

/**
 * Classe Fita, que é uma subclasse de Midia
 * Apresenta o construtor da classe Fita
*/
class Fita : public Midia {
    public:
        Fita(int codigo_numerico, std::string titulo, int unidades_disponiveis);

/**
 * Imprime as informações da fita
*/
        void imprimir_info() override;
/**
 * Calcula o valor de locação da fita.
 * O fato de ela ser rebobinada ou não está sendo de maneira aleatória, usando rand()
*/
        int calcular_locacao(int dias) override;
};

#endif
