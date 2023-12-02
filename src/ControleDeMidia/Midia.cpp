#include <iostream>
#include <string>
#include "../../include/ControleDeMidia/Midia.hpp"

using namespace std;

Midia::Midia(int codigo_numerico, string titulo, int unidades_disponiveis) : _codigo_numerico(codigo_numerico) , _titulo(titulo) , _unidades_disponiveis(unidades_disponiveis)
{}

int Midia::getCodigoNumerico() {
    return this->_codigo_numerico;
}

string Midia::getTitulo() {
    return this->_titulo;
}

int Midia::getUnidadesDisponiveis() {
    return this->_unidades_disponiveis;
}

void Midia::imprimir_info(){
    cout << this->getCodigoNumerico() << this->getTitulo() << this->getUnidadesDisponiveis();
}

