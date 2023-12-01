#include <string>
#include <iostream>
#include "../../include/ControleDeMidia/Jogo.hpp"
#include <cstdlib>

using namespace std;

Jogo::Jogo(int codigo_numerico, string titulo, int unidades_disponiveis) :
            Midia(codigo_numerico, titulo, unidades_disponiveis) {}

int Jogo::calcular_locacao(int dias) {
    int valor_jogo = 0;
    int nivel_arranhado = rand() % 10;
    return 5*nivel_arranhado + 5;
}

void Jogo::imprimir_info() {
    Midia::imprimir_info();
    cout << "Jogo" << endl;
}