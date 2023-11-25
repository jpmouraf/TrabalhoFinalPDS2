#ifndef FITA_H
#define FITA_H

#include "Midia.hpp"
#include <iostream>
#include <string>

using namespace std;

class Fita : public Midia {
    public:
        bool _isRebobinada;
        Fita(int codigo_numerico, string titulo, int unidades_disponiveis);
        virtual int calcular_locacao();
};

#endif