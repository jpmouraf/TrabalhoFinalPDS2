#include "Deposito.hpp"
#include "Midia.hpp"
#include "Dvd.hpp"
#include "Fita.hpp"
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

void Deposito::cadastrar_dvd(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo, string categoria) {
   auto it = _midias.find(codigo_numerico);
    if (it != _midias.end()) {
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
        _midias[codigo_numerico] = novo_dvd;
        cout << "Midia " << codigo_numerico << " cadastrado com sucesso" << endl;
    }
    else {
        cout << "ERRO: dados incorretos" << endl;
    }
}

void Deposito::cadastrar_fita(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo) {
    auto it = _midias.find(codigo_numerico);
    if (it != _midias.end()) {
        cout << "ERRO: codigo repetido" << endl;
        return; 
    }
    if(tipo == "FITA") {
        Fita* nova_fita = new Fita(codigo_numerico, titulo, unidades_disponiveis);
        _midias[codigo_numerico] = nova_fita;
        cout << "Mídia " << codigo_numerico << " cadastrada com sucesso" << endl;
    }
    else {
        cout << "ERRO: dados incorretos" << endl;
    }
}

void Deposito::remover_midia(int codigo_numerico) {
    auto it = _midias.find(codigo_numerico);
    if(it != _midias.end()) {
        _midias.erase(it);
        cout << "Mídia " << codigo_numerico << " removida com sucesso" << endl;
    } else {
        cout << "ERRO: codigo inexistente" << endl;
    }
}

void Deposito::ler_estoque(string nome_arquivo) {
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
        cout << contador << " Mídias cadastradas com sucesso" << endl;
    } else {
        cout << "ERRO: arquivo inexistente" << endl;
    }
}    

void Deposito::ordenar_codigo() {
    map<int, Midia*>::iterator it;
    for(it = _midias.begin(); it != _midias.end(); it++) {
        cout << it ->first << ": " << it->second << endl;
    }
}


void Deposito::ordenar_nome() {
    
}
