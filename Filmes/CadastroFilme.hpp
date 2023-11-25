#ifndef CADASTROFILME_H
#define CADATROFILME_H

#include "Filme.hpp"
#include "Dvd.hpp"
#include "Fita.hpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Cadastro_Filme {
    private:
        map<int, Filme*> _filmes;
        string tipo;
        string _categoria;
    
    public:
        void cadastrar_dvd(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo, string categoria);
        void cadastrar_fita(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo);
        void remover_filme(int codigo_numerico);
        void ler_estoque(string nome_arquivo);
        void ordenar_codigo();
        void ordenar_nome();
};

#endif