#ifndef DVD_H
#define DVD_H

#include <string>
#include <iostream>
#include "Midia.hpp"

/**
 * Classe que representa um DVD, derivada da classe Midia.
 * Sobescreve o metodo imprimir informações.
*/
class Dvd : public Midia { 
    public:
        Dvd(int codigo_numerico, std::string titulo, int unidades_disponiveis);
        
        void imprimir_info() override;
};

/**
 * Subclasses que representam o tipo especifico de cada Dvd
 * Todas vao possuir o construtor, a variavel dias de locação e o meotodo calcular_locacao
*/
class Lancamento : public Dvd {
    public:
        Lancamento(int codigo_numerico, std::string titulo, int unidades_disponiveis);
        
        int dias_locacao;
        virtual int calcular_locacao(int dias) override;
};

class Estoque : public Dvd {
    public:
        Estoque(int codigo_numerico, std::string titulo, int unidades_disponiveis);

        int dias_locacao;
        virtual int calcular_locacao(int dias) override;
};

class Promocao : public Dvd {
    public:
        Promocao(int codigo_numerico, std::string titulo, int unidades_disponiveis);

        int dias_locacao;
        virtual int calcular_locacao(int dias) override;
};

#endif
