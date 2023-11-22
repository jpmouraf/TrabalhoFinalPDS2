#ifndef DVD_H
#define DVD_H

#include "Filme.hpp"
#include <iostream>
#include <string>

using namespace std;

class Dvd : public Filme {
    public:
        virtual int calcular_locacao() = 0;
};



class Lancamento : public Dvd {
    private:
        int _dias_locacao;
    public:
        Lancamento(int codigo_numerico, string titulo, int unidades_disponiveis , int dias_locacao);
        virtual int calcular_locacao() override;

};

class Estoque : public Dvd {
    private:
        int _dias_locacao;
    public:
        Estoque(int codigo_numerico, string titulo, int unidades_disponiveis , int dias_locacao);
        virtual int calcular_locacao() override;

};

class Promocao : public Dvd {
    private:
        int _dias_locacao;
    public:
        Promocao(int codigo_numerico, string titulo, int unidades_disponiveis , int dias_locacao);
        virtual int calcular_locacao() override;


};

#endif