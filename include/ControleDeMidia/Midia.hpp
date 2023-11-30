#ifndef MIDIA_H
#define MIDIA_H

#include <string>
#include <iostream>

using namespace std;

class Midia {
    private:
        int _codigo_numerico;
        string _titulo;
        int _unidades_disponiveis;

    public:
        Midia(int codigo_numerico, string titulo, int unidades_disponiveis);
        int getCodigoNumerico();
        string getTitulo();
        int getUnidadesDisponiveis();
        virtual void imprimir_info();
        virtual int calcular_locacao(int dias) = 0;
};


#endif