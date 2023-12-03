#include "../../include/ControleDeMidia/Dvd.hpp"
#include "../../include/ControleDeMidia/Midia.hpp"

Dvd::Dvd(int codigo_numerico, std::string titulo, int unidades_disponiveis) : Midia(codigo_numerico, titulo, unidades_disponiveis) {
    try
    {
        this->setTipo("DVD");
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Dvd::imprimir_info(){
    Midia::imprimir_info();
    std::cout << "DVD" << std::endl;
}

Lancamento::Lancamento(int codigo_numerico, std::string titulo, int unidades_disponiveis)
    : Dvd(codigo_numerico, titulo, unidades_disponiveis) {}

int Lancamento::calcular_locacao(int dias) {
    if (dias < 0) {
            throw std::invalid_argument("O número de dias não pode ser negativo.");
        }
    int valor_lancamento = 20 * dias;
    return valor_lancamento;
}

Estoque::Estoque(int codigo_numerico, std::string titulo, int unidades_disponiveis)
    : Dvd(codigo_numerico, titulo, unidades_disponiveis) {}

int Estoque::calcular_locacao(int dias) {
    int valor_estoque = 10 * dias;
    return valor_estoque;
}

Promocao::Promocao(int codigo_numerico, std::string titulo, int unidades_disponiveis)
    : Dvd(codigo_numerico, titulo, unidades_disponiveis) {}

int Promocao::calcular_locacao(int dias) {
    int valor_promocao = 10;
    return valor_promocao;
}
