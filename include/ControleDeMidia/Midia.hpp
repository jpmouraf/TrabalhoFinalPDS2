#ifndef MIDIA_H
#define MIDIA_H

#include <string>
#include <iostream>

class Midia {
    private:
        bool _const_tipo = false;
        std::string _tipo;
        std::string _titulo;
        int _codigo_numerico;
        int _unidades_disponiveis;

    public:
        Midia(int codigo_numerico, std::string titulo, int unidades_disponiveis);

        std::string getTipo();
        std::string getTitulo();
        int getCodigoNumerico();
        int getUnidadesDisponiveis();
        virtual void imprimir_info();
        void setTipo(std::string tipo);
        virtual int calcular_locacao(int dias) = 0;
};

#endif