#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "Clientes.hpp"

using namespace std;

Cliente::Cliente(string nome, int CPF) : _nome(nome) , _CPF(CPF) {}

int Cliente::getCPF() {
    return _CPF;
}

string Cliente::getNome() {
    return _nome;
}

bool CadastrarCliente::validarCPF(int CPF) {
    return CPF >= 10000000000 && CPF <= 99999999999;
}

void CadastrarCliente::cadastrar_cliente(int CPF, string nome) {
    if(!validarCPF(CPF)) {
        cout << "ERRO: dados incorretos" << endl;
    }
        else if (_clientes.find(CPF) != _clientes.end()) {
            cout << "Erro: CPF repetido." << endl;
        }
            else{    
        Cliente novoCliente(nome, CPF);
        _clientes[CPF] = novoCliente;
        cout << "Cliente " << CPF << " cadastrado com sucesso." << endl;
        }
}

void CadastrarCliente::remover_cliente(int CPF) {
    auto it = _clientes.find(CPF);
    if (it != _clientes.end()) {
        _clientes.erase(it);
        cout << "Cliente " << CPF << " removido com sucesso" << endl;
    } 
        else {
        cout << "ERRO: CPF inexistente" << endl;
     }
}


void CadastrarCliente::listar_codigo() {
    for (auto it = _clientes.begin(); it != _clientes.end(); it++) {
        cout << it->first << ": " << it->second.getNome() << endl;
    }
}
