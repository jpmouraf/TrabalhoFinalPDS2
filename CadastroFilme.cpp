#include "CadastroFilme.hpp"
#include "Filme.hpp"
#include "Dvd.hpp"
#include "Fita.hpp"
#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

void Cadastro_Filme::cadastrar_dvd(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo, string categoria) {
    _filmes.push_back(new Filme(codigo_numerico, titulo, unidades_disponiveis));
}

void Cadastro_Filme::cadastrar_fita(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo) {
    _filmes.push_back(new Filme(codigo_numerico, titulo, unidades_disponiveis));
}
    
void Cadastro_Filme::ler_estoque() {
    ifstream arquivo("estoque.txt");
    if (arquivo.is_open()) {
        string tipo, titulo, categoria;
        int unidades_disponiveis, codigo_numerico;

        while (arquivo >> tipo >> unidades_disponiveis >> codigo_numerico) {
            getline(arquivo, titulo);
            if (tipo == "DVD") {
                getline(arquivo, categoria);
                cadastrar_dvd(tipo, unidades_disponiveis, codigo_numerico, titulo, categoria);
            } else if (tipo == "FITA") {
                cadastrar_fita(tipo, unidades_disponiveis, codigo_numerico, titulo);
            }
        }
        arquivo.close();
    } else {
        cout << "ERRO: arquivo inexistente" << endl;
    }
}