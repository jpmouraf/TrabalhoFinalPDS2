#ifndef CLIENTES_H
#define CLIENTES_H

#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

class Cliente {
    private:
        string _nome;
        long int _cpf;
 
    public:
        Cliente(string nome, long int cpf);

        long int getCPF();
        string getNome();
};

class ControleCliente {
    private:
        list<Cliente> _clientes;

    public:
        bool validarCPF(long int cpf);
        void cadastrar_cliente(long int cpf, string nome);
        void remover_cliente(long int cpf, string nome);
        void listar_codigo();
        void listar_nome();
        map<int, int> ler_locacoes_cliente(long int cpf_cliente);
        void escrever_locacoes_cliente(long int cpf_cliente, map<int, int> locacoes);
};


#endif