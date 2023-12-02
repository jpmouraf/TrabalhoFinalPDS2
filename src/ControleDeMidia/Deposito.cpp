#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "../../include/ControleDeMidia/Deposito.hpp"


using namespace std;

Deposito::Deposito(){
    this->ler_estoque("../../data/banco_de_midias.txt");
}

Deposito::~Deposito(){
    this->salvar_estoque();
}

void Deposito::cadastrar_dvd(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo, string categoria) {
   auto it = _midias.find(codigo_numerico);
    if (it != _midias.end()) {
        throw DadosRepetidos ("ERRO: codigo repetido");
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
        throw DadosInexistente ("ERRO: dados incorretos");
    }
}

void Deposito::cadastrar_fita(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo) {
    auto it = _midias.find(codigo_numerico);
    if (it != _midias.end()) {
        throw DadosRepetidos ("ERRO: codigo repetido");
    }
    if(tipo == "FITA") {
        Fita* nova_fita = new Fita(codigo_numerico, titulo, unidades_disponiveis);
        _midias[codigo_numerico] = nova_fita;
        cout << "Mídia " << codigo_numerico << " cadastrada com sucesso" << endl;
    }
    else {
        throw DadosInexistente ("ERRO: dados incorretos");
    }
}

void Deposito::cadastrar_jogo(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo) {
    auto it = _midias.find(codigo_numerico);
    if (it != _midias.end()) {
        throw DadosRepetidos ("ERRO: codigo repetido");
    }
    if(tipo == "FITA") {
        Jogo* nova_fita = new Jogo(codigo_numerico, titulo, unidades_disponiveis);
        _midias[codigo_numerico] = nova_fita;
        cout << "Mídia " << codigo_numerico << " cadastrada com sucesso" << endl;
    }
    else {
        throw DadosInexistente ("ERRO: dados incorretos");
    }
}

void Deposito::remover_midia(int codigo_numerico) {
    auto it = _midias.find(codigo_numerico);
    if(it != _midias.end()) {
        _midias.erase(it);
        cout << "Mídia " << codigo_numerico << " removida com sucesso" << endl;
    } else {
        throw DadosInexistente ("ERRO: código inexistente");
    }
}

void Deposito::devolver_midia(int codigo_numerico, int quantidade){ //talvez tenhamos que revisar isso
    try {
        _midias[codigo_numerico] += quantidade;
    } catch(out_of_range e){
        throw DadosInexistente(("[DPST] ERRO: Mídia não existe na base de dados. Verifique se a mídia não foi descadastrada durante o período de locação."));
    }
}

void Deposito::retirar_midia(int codigo_numerico, int quantidade){
    try {
        _midias[codigo_numerico] += quantidade;
    } catch(out_of_range e){
        throw DadosInexistente("ERRO: Mídia não existente na base de dados.");
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
        throw ExcecaoDeposito ("ERRO: arquivo inexistente");
    }
}


void Deposito::salvar_estoque(string nome_do_arquivo){
    ofstream estoque_saida(nome_do_arquivo);

    for (auto& midia : this->_midias){
        if (typeid(*midia.second) == typeid(Promocao)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "promocao\n";
        }

        else if (typeid(*midia.second) == typeid(Lancamento)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "lancamento\n";
        }

        else if (typeid(*midia.second) == typeid(Estoque)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "estoque\n";
        }
        
        else if (typeid(*midia.second) == typeid(Fita)) {
            estoque_saida << "F" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "\n";
        }
    }
    
    estoque_saida.close();
}

void Deposito::salvar_estoque(){
    ofstream estoque_saida;
    estoque_saida.open("../data/banco_de_midias.txt");

    for (auto& midia : this->_midias){
        if (typeid(*midia.second) == typeid(Promocao)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "promocao\n";
        }

        else if (typeid(*midia.second) == typeid(Lancamento)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "lancamento\n";
        }

        else if (typeid(*midia.second) == typeid(Estoque)) {
            estoque_saida << "D" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "estoque\n";
        }
        
        else if (typeid(*midia.second) == typeid(Fita)) {
            estoque_saida << "F" << midia.second->getUnidadesDisponiveis() << midia.first << midia.second->getTitulo() << "\n";
        }
    }
    
    estoque_saida.close();
}

void Deposito::ordenar_codigo() {
    map<int, Midia*>::iterator it;
    for(it = _midias.begin(); it != _midias.end(); it++) {
        cout << it ->first << ": " << it->second << endl;
    }
}


void Deposito::ordenar_titulo() {
    map <string, Midia*> temp_map;
    for(auto it : _midias){
        string nome = it.second->getTitulo();
        if(temp_map.find(nome) == temp_map.end()){
            temp_map[nome] = it.second;
        }
    }
    cout << "## {RELATÓRIO}: Título de todas as mídias em estoque ##" << endl;
    for(auto it : temp_map){
        cout << it.first << endl;
    }
    cout << "################## FIM DO RELATÓRIO ##################" << endl;
    
}

void Deposito::imprimir_todas_midias(){

    
    for (auto& midia : this->_midias) {
        midia.second->imprimir_info();
    }
}