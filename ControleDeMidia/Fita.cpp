#include "Midia.hpp"
#include "Fita.hpp"
#include <iostream>
#include <string>

using namespace std;

Fita::Fita(int codigo_numerico, string titulo, int unidades_disponiveis) :
            Midia(codigo_numerico, titulo, unidades_disponiveis) {}

int Fita::calcular_locacao() {
    int valor_fita = 0;
    if(_isRebobinada) {
        return valor_fita = 7;
    }
    else {
        return valor_fita = 5;
    }
}           