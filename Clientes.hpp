#ifndef CLIENTES_H
#define CLIENTES_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Cliente {
    private:
        string _nome;
        long int _CPF;
 
    public:
        Cliente() : _nome(""), _CPF(0) {}
        Cliente(string nome, long int CPF);

        int getCPF();
        string getNome();
};

class CadastrarCliente {
    private:
        map<long int, Cliente> _clientes;

    public:
        bool validarCPF(long int CPF);
        void cadastrar_cliente(long int CPF, string nome);
        void remover_cliente(long int CPF);
        void listar_codigo();
        void listar_nome();
};


#endif