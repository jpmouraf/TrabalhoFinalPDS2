#include <iostream>
#include <set>
#include <string>
#include "Clientes.hpp"

using namespace std;

Cliente::Cliente(string nome, long int cpf) : _nome(nome) , _cpf(cpf) {}

int Cliente::getCPF() {
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
        cout << "ERRO: dados incorretos" << endl;
    }
    else {
        for (auto& cliente : _clientes) {
            if (cliente.getCPF() == cpf) {
                cout << "Erro: CPF repetido." << endl;
                return;
            }
        }
        Cliente novoCliente(nome, cpf);
        _clientes.push_back(novoCliente);
        cout << "Cliente " << cpf << " cadastrado com sucesso." << endl;
    }
}

void ControleCliente::remover_cliente(long int cpf, string nome) {
    for (auto it = _clientes.begin(); it != _clientes.end(); ++it) {
        if (it->getCPF() == cpf) {
            _clientes.erase(it);
            cout << "Cliente " << cpf << " removido com sucesso" << endl;
            return;
        }
    }
    cout << "ERRO: CPF inexistente" << endl;
}


void ControleCliente::listar_codigo() {
    for (auto& cliente : _clientes) {
        cout << cliente.getCPF() << ": " << cliente.getNome() << endl;
    }
}

void ControleCliente::listar_nome() {
//Nao esta listando os nomes em ordem alfabetica, apenas pela ordem do codigo
    for (auto& cliente : _clientes) {
        cout << cliente.getNome() << ": " << cliente.getCPF() << endl;
    }
}
