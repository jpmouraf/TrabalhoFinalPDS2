#ifndef DVD_H
#define DVD_H

#include <string>
#include <iostream>
#include "Midia.hpp"

using namespace std;

/**
 * Classe que representa um DVD, derivada da classe Midia.
 * Declara a variavel tipo que diferencia os dvd's
*/
class Dvd : public Midia {
    private:
        static const string _tipo;
    public:
/**
 * Construtor da classe Dvd
*/
        Dvd(int codigo_numerico, string titulo, int unidades_disponiveis);
/**
 * Metodo para imprimir informações do Dvd
*/
        void imprimir_info() override;
/**
 * Metodo para retornar o tipo do Dvd
*/
        string gettipo() override;
};

/**
 * Subclasses que representam o tipo especifico de cada Dvd
 * Todas vao possuir o construtor e o meotodo de calcular_locacao
*/
class Lancamento : public Dvd {
    public:
        Lancamento(int codigo_numerico, string titulo, int unidades_disponiveis);
        virtual int calcular_locacao(int dias) override;
};

class Estoque : public Dvd {
        int _dias_locacao;
        Estoque(int codigo_numerico, string titulo, int unidades_disponiveis);
        virtual int calcular_locacao(int dias) override;
};

class Promocao : public Dvd {
    public:
        Promocao(int codigo_numerico, string titulo, int unidades_disponiveis);
        virtual int calcular_locacao(int dias) override;
};

#endif
