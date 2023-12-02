#ifndef FITA_H
#define FITA_H

#include <string>
#include <iostream>
#include "Midia.hpp"

using namespace std;

/**
 * Classe Fita, que é uma subclasse de Midia
 * Declara também o tipo de Fita
*/
class Fita : public Midia {
    private:
        static const string _tipo;
    public:
/**
 * Construtor da classe Fita
*/
        Fita(int codigo_numerico, string titulo, int unidades_disponiveis);
/**
 * Calcula o valor de locação da fita.
 * O fato de ela ser rebobinada ou não está sendo de maneira aleatória, usando rand()
*/
        int calcular_locacao(int dias) override;
/**
 * Imprime as informações da fita
*/
        void imprimir_info() override;
/**
 * Retorna o tipo de fita
*/
        string gettipo() override;
};

#endif
