#include <string>
#include <iostream>
#include "../../include/ControleDeMidia/Fita.hpp"
#include "cstdlib"

using namespace std;

const string Fita::_tipo = "Fita cassete";

Fita::Fita(int codigo_numerico, string titulo, int unidades_disponiveis) :
            Midia(codigo_numerico, titulo, unidades_disponiveis) {}

string Fita::gettipo() {
    cout << _tipo << endl;
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

void Fita::imprimir_info() {
    Midia::imprimir_info();
    cout << "FITA" << endl;
}