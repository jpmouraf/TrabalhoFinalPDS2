#include "Filme.hpp"
#include "Dvd.hpp"

Dvd::Dvd(int codigo_numerico, string titulo, int unidades_disponiveis)
    :Filme(codigo_numerico, titulo, unidades_disponiveis) {}

Lancamento::Lancamento(int codigo_numerico, string titulo, int unidades_disponiveis)
    : Dvd(codigo_numerico, titulo, unidades_disponiveis) {}

int Lancamento::calcular_locacao(int dias) {
    int valor_lancamento = 20 * dias;
    return valor_lancamento;
}

Estoque::Estoque(int codigo_numerico, string titulo, int unidades_disponiveis)
    : Dvd(codigo_numerico, titulo, unidades_disponiveis) {}

int Estoque::calcular_locacao(int dias) {
    int valor_estoque = 10 * dias;
    return valor_estoque;
}

Promocao::Promocao(int codigo_numerico, string titulo, int unidades_disponiveis)
    : Dvd(codigo_numerico, titulo, unidades_disponiveis) {}

int Promocao::calcular_locacao(int dias) {
    int valor_promocao = 10;
    return valor_promocao;
}
