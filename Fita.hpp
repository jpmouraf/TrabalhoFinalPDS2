#ifndef FITA_H
#define FITA_H

#include "Filme.hpp"
#include <iostream>
#include <string>

using namespace std;

class Fita : public Filme {
    private:
        bool _isRebobinada;
    
    public:
        Fita(int codigo_numerico, string titulo, int unidades_disponiveis , bool isRebobinada);
        virtual int calcular_locacao();
};

#endif