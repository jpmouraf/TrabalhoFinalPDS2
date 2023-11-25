#include "CadastroFilme.hpp"
#include "Filme.hpp"
#include "Dvd.hpp"
#include "Fita.hpp"
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

void Cadastro_Filme::cadastrar_dvd(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo, string categoria) {
   auto it = _filmes.find(codigo_numerico);
    if (it != _filmes.end()) {
        cout << "ERRO: codigo repetido" << endl;
        return; 
    }
   Dvd* novo_dvd = nullptr;
    if (tipo == "DVD") {
        if (categoria == "Lancamento") {
            novo_dvd = new Lancamento(codigo_numerico, titulo, unidades_disponiveis);
        } 
        else if (categoria == "Estoque") {
            novo_dvd = new Estoque(codigo_numerico, titulo, unidades_disponiveis);
        } 
        else if (categoria == "Promocao") {
            novo_dvd = new Promocao(codigo_numerico, titulo, unidades_disponiveis);
        }
    }
    if (novo_dvd != nullptr) {
        _filmes[codigo_numerico] = novo_dvd;
        cout << "Filme " << codigo_numerico << " cadastrado com sucesso" << endl;
    }
    else {
        cout << "ERRO: dados incorretos" << endl;
    }
}

void Cadastro_Filme::cadastrar_fita(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo) {
    auto it = _filmes.find(codigo_numerico);
    if (it != _filmes.end()) {
        cout << "ERRO: codigo repetido" << endl;
        return; 
    }
    if(tipo == "FITA") {
        Fita* nova_fita = new Fita(codigo_numerico, titulo, unidades_disponiveis);
        _filmes[codigo_numerico] = nova_fita;
        cout << "Filme " << codigo_numerico << " cadastrado com sucesso" << endl;
    }
    else {
        cout << "ERRO: dados incorretos" << endl;
    }
}

void Cadastro_Filme::remover_filme(int codigo_numerico) {
    auto it = _filmes.find(codigo_numerico);
    if(it != _filmes.end()) {
        _filmes.erase(it);
        cout << "Filme " << codigo_numerico << " removido com sucesso" << endl;
    } else {
        cout << "ERRO: codigo inexistente" << endl;
    }
}

void Cadastro_Filme::ler_estoque(string nome_arquivo) {
    ifstream arquivo(nome_arquivo);
    if (arquivo.is_open()) {
        string tipo, titulo, categoria;
        int unidades_disponiveis, codigo_numerico;
        int contador = 0;

        while (arquivo >> tipo >> unidades_disponiveis >> codigo_numerico) {
            getline(arquivo, titulo);
            if (tipo == "DVD") {
                getline(arquivo, categoria);
                cadastrar_dvd(tipo, unidades_disponiveis, codigo_numerico, titulo, categoria);
            } else if (tipo == "FITA") {
                cadastrar_fita(tipo, unidades_disponiveis, codigo_numerico, titulo);
            }
            contador++;
        }
        arquivo.close();
        cout << contador << " Filmes cadastrados com sucesso" << endl;
    } else {
        cout << "ERRO: arquivo inexistente" << endl;
    }
}    

void Cadastro_Filme::ordenar_codigo() {
    map<int, Filme*>::iterator it;
    for(it = _filmes.begin(); it != _filmes.end(); it++) {
        cout << it ->first << ": " << it->second << endl;
    }
}


void Cadastro_Filme::ordenar_nome() {
    
}
