#include <iostream>
#include <string>
#include "Filme.hpp"

using namespace std;

Filme::Filme(int Codigo_numerico, string titulo, int Unidades_disponiveis) : _codigo_numerico(Codigo_numerico) , _titulo(titulo) , _unidades_disponiveis(Unidades_disponiveis)
{}

int Filme::getCodigoNumerico() {
    return this->_codigo_numerico;
}

string Filme::getTitulo() {
    return this->_titulo;
}

int Filme::getUnidadesDisponiveis() {
    return this->_unidades_disponiveis;
}