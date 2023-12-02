#ifndef DVD_H
#define DVD_H

#include <string>
#include <iostream>
#include "Midia.hpp"

class Dvd : public Midia { 
    public:
        Dvd(int codigo_numerico, std::string titulo, int unidades_disponiveis);
        
        void imprimir_info() override;
};

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