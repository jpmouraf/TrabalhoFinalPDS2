#ifndef CADASTROFILME_H
#define CADATROFILME_H

#include "Filme.hpp"
#include "Dvd.hpp"
#include "Fita.hpp"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Cadastro_Filme {
    private:
        list<Filme*> _filmes;
        string tipo;
        string _categoria;

    public:
        void cadastrar_dvd(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo, string categoria);
        void cadastrar_fita(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo);
        void ler_estoque();

};

#endif