#ifndef DVD_H
#define DVD_H

#include "Midia.hpp"
#include <iostream>
#include <string>

using namespace std;

class Dvd : public Midia {
    public:
        Dvd(int codigo_numerico, string titulo, int unidades_disponiveis);
};



class Lancamento : public Dvd {
    public:
        Lancamento(int codigo_numerico, string titulo, int unidades_disponiveis);
        virtual int calcular_locacao(int dias) override;

};

class Estoque : public Dvd {
    public:
        int _dias_locacao;
        Estoque(int codigo_numerico, string titulo, int unidades_disponiveis);
        virtual int calcular_locacao(int dias) override;

};

class Promocao : public Dvd {
    public:
        int _dias_locacao;
        Promocao(int codigo_numerico, string titulo, int unidades_disponiveis);
        virtual int calcular_locacao(int dias) override;

};

#endif