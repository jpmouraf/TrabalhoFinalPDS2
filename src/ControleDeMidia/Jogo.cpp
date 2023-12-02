#include <string>
#include <cstdlib>
#include <iostream>
#include "../../include/ControleDeMidia/Jogo.hpp"

Jogo::Jogo(int codigo_numerico, std::string titulo, int unidades_disponiveis) : Midia(codigo_numerico, titulo, unidades_disponiveis){
    try
    {
        this->setTipo("Jogo");
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int Jogo::calcular_locacao(int dias) {
    int valor_jogo = 0;
    int nivel_arranhado = rand() % 10;
    return 5*nivel_arranhado + 5;
}

void Jogo::imprimir_info() {
    Midia::imprimir_info();
    std::cout << "Jogo" << std::endl;
}
