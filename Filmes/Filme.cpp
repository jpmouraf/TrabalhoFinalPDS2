#include <iostream>
#include <string>
#include "Filme.hpp"

using namespace std;

Filme::Filme(int codigo_numerico, string titulo, int unidades_disponiveis) : _codigo_numerico(codigo_numerico) , _titulo(titulo) , _unidades_disponiveis(unidades_disponiveis)
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