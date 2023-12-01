#include <set>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Clientes.hpp"

using namespace std;

Cliente::Cliente(string nome, long int cpf) : _nome(nome) , _cpf(cpf) {}

long int Cliente::getCPF() {
    return _cpf;
}

string Cliente::getNome() {
    return _nome;
}

bool ControleCliente::validarCPF(long int cpf) {
    return cpf >= 10000000000 && cpf <= 99999999999;
}

void ControleCliente::cadastrar_cliente(long int cpf, string nome) {
    if(!validarCPF(cpf)) {
        throw ExcecaoCliente("ERRO: dados incorretos");
    }
    else {
        for (auto& cliente : _clientes) {
            if (cliente.getCPF() == cpf) {
                throw ExcecaoCliente("ERRO: CPF repetido");
            }
        }
        Cliente novoCliente(nome, cpf);
        _clientes.push_back(novoCliente);
        cout << "Cliente " << cpf << " cadastrado com sucesso." << endl;
    }
}

void ControleCliente::remover_cliente(long int cpf) {
    for (auto it = _clientes.begin(); it != _clientes.end(); ++it) {
        if (it->getCPF() == cpf) {
            _clientes.erase(it);
            cout << "Cliente " << cpf << " removido com sucesso" << endl;
            return;
        }
    }
    throw ExcecaoCliente("ERRO: CPF inexistente");
}


void ControleCliente::listar_codigo() {
    for (auto& cliente : _clientes) {
        cout << cliente.getCPF() << ": " << cliente.getNome() << endl;
    }
}

void ControleCliente::listar_nome() {
    _clientes.sort([](Cliente& a, Cliente& b) {
        return a.getNome() < b.getNome();
    });

    for (auto& cliente : _clientes) {
        std::cout << cliente.getNome() << ": " << cliente.getCPF() << std::endl;
    }
}

int ControleCliente::calcula_dias(time_t data_locacao){
    time_t data_devolucao = time(0);
    const int segundosPorDia = 60 * 60 * 24;

    int diferencaSegundos = static_cast<int>(difftime(data_locacao, data_devolucao));
    int diferencaDias = diferencaSegundos / segundosPorDia;

    return diferencaDias;
}

time_t ControleCliente::encontrar_data_alocacao(long cpf, int codigo) {
    ifstream banco_de_locacoes("../../data/banco_de_locacoes.csv");

    if (!banco_de_locacoes.is_open()) {
        throw ErroAbrirArquivo();
    }

    string linha;
    getline(banco_de_locacoes, linha);
    stringstream linhaStream(linha);

    string campo;
    vector<string> celulas;

    while (getline(linhaStream, campo, ',')) {
        celulas.push_back(campo);
    }

    long cpf_csv = stol(celulas[0]);
    if (cpf_csv == cpf) {
        string datetime = celulas[3];
        tm tmStruct = {};
        istringstream ss(datetime);
        ss >> get_time(&tmStruct, "%Y-%m-%d %H:%M:%S");
        time_t tempo = mktime(&tmStruct);
        cout << "Valor de time_t: " << tempo << endl;
        banco_de_locacoes.close();
        return tempo;
    }

    banco_de_locacoes.close();
}

void ControleCliente::escrever_locacoes_cliente(long int cpf_cliente, map<int, int> locacoes){
    ofstream banco_de_locacoes("../../data/banco_de_locacoes.csv", ios::app);
    if (!banco_de_locacoes.is_open()) {
        throw ErroAbrirArquivo();
    }

    time_t agora = time(0);

    for (auto& info_midia : locacoes) {
        banco_de_locacoes << cpf_cliente << "," << info_midia.first << "," << info_midia.second << "," << ctime(&agora) << ",,\n";
    }

    banco_de_locacoes.close();
}

map<int, int> ControleCliente::locacoes_cliente(long cpf){
    map<int, int> saida;
    ifstream banco_de_locacoes("../../data/banco_de_locacoes.csv");

    if (!banco_de_locacoes.is_open()) {
        throw ErroAbrirArquivo();
    }

    string linha;
    getline(banco_de_locacoes, linha);
    stringstream linhaStream(linha);

    string campo;
    vector<string> celulas;

    while (getline(linhaStream, campo, ',')) {
        celulas.push_back(campo);
    }

    long cpf_csv = stol(celulas[0]);
    if (cpf_csv == cpf) {
        int id = stol(celulas[1]);
        saida[id] = cpf;
    }

    banco_de_locacoes.close();
    return saida;
}

InformacoesLocacao ControleCliente::informacoes_locacao(long cpf){
    InformacoesLocacao saida;
    saida.locacoes = this->locacoes_cliente(cpf);
    int id_teste = saida.locacoes.begin()->first;
    saida.dias = this->calcula_dias(encontrar_data_alocacao(cpf, id_teste));
    return saida;
}
