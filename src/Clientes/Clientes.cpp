#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
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

void ControleCliente::escrever_locacoes_cliente(long int cpf_cliente, map<int, int> locacoes){
    fstream banco_de_locacoes("../../data/banco_de_locacoes.csv");
    time_t agora = time(0);

    for (auto& info_midia : locacoes){
        banco_de_locacoes << cpf_cliente << ";" << info_midia.first << ";" << info_midia.second << ";" << ctime(&agora) << ";;\n";
    }
}
