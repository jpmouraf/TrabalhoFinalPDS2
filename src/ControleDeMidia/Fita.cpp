#include <string>
#include "cstdlib"
#include <iostream>
#include "../../include/ControleDeMidia/Fita.hpp"

Fita::Fita(int codigo_numerico, std::string titulo, int unidades_disponiveis) : Midia(codigo_numerico, titulo, unidades_disponiveis) {
    try
    {
        this->setTipo("FITA");
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Fita::imprimir_info() {
    Midia::imprimir_info();
    std::cout << "FITA" << std::endl;
}

int Fita::calcular_locacao(int dias) {
    int valor_fita = 0;
    bool _isRebobinada = rand() % 2;
    if(_isRebobinada) {
        return valor_fita = 7;
    }
    else {
        return valor_fita = 5;
    }
}
