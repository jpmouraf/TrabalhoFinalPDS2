#include "Filme.hpp"
#include "Dvd.hpp"
#include <iostream>
#include <string>

using namespace std;

Lancamento::Lancamento(int codigo_numerico, string titulo, int unidades_disponiveis , int dias_locacao) :
                Filme(codigo_numerico, titulo, unidades_disponiveis) , _dias_locacao(dias_locacao) {}

int Lancamento::calcular_locacao() {
    int valor_lancamento = 20 * this->_dias_locacao;
    return valor_lancamento;
}

Estoque::Estoque(int codigo_numerico, string titulo, int unidades_disponiveis , int dias_locacao) :
                Filme(codigo_numerico, titulo, unidades_disponiveis) , _dias_locacao(dias_locacao) {}

int Estoque::calcular_locacao() {
    int valor_estoque = 10 * this->_dias_locacao;
    return valor_estoque;
}

Promocao::Promocao(int codigo_numerico, string titulo, int unidades_disponiveis , int dias_locacao) :
                Filme(codigo_numerico, titulo, unidades_disponiveis) , _dias_locacao(dias_locacao) {}

int Promocao::calcular_locacao() {
    int valor_promocao = 10;
    return valor_promocao;
}