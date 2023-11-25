#ifndef FITA_H
#define FITA_H

#include "Filme.hpp"
#include <iostream>
#include <string>

using namespace std;

class Fita : public Filme {
    public:
        bool _isRebobinada;
        Fita(int codigo_numerico, string titulo, int unidades_disponiveis);
        virtual int calcular_locacao();
};

#endif