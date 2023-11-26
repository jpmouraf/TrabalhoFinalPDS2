#ifndef DEPOSITO_H
#define DEPOSITO_H

#include "Midia.hpp"
#include "Dvd.hpp"
#include "Fita.hpp"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Deposito {
    private:
        map<int, Midia*> _midias;
        string tipo;
        string _categoria;
    
    public:
        void cadastrar_dvd(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo, string categoria);
        void cadastrar_fita(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo);
        void remover_midia(int codigo_numerico);
        void ler_estoque(string nome_arquivo);
        void ordenar_codigo();
        void ordenar_nome();
        Midia* get_midia(int codigo_numerico);
        void retirar_midia(int codigo_numerico, int quantidade); // se alguem pensar em nomes melhores para essas
        void devolver_midia(int codigo_numerico, int quantidade); // funções por favor sinta-se livre para mudar
};

#endif