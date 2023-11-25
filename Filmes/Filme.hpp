#ifndef FILME_H
#define FILME_H

#include <iostream>
#include <string>

using namespace std;

class Filme {
    private:
        int _codigo_numerico;
        string _titulo;
        int _unidades_disponiveis;

    public:
        Filme(int codigo_numerico, string titulo, int unidades_disponiveis);
        int getCodigoNumerico();
        string getTitulo();
        int getUnidadesDisponiveis();
};


#endif