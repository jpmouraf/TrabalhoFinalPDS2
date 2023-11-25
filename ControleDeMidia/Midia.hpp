#ifndef MIDIA_H
#define MIDIA_H

#include <iostream>
#include <string>

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
};


#endif