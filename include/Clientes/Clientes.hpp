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

        void escrever_data_devolucao();
        time_t encontrar_data_alocacao(long cpf, int codigo);
        int calcula_dias(time_t data_locacao);
        map<int, int> locacoes_cliente(long cpf);

    public:
        bool validarCPF(long int cpf);
        void cadastrar_cliente(long int cpf, string nome);
        void remover_cliente(long int cpf);
        void listar_codigo();
        void listar_nome();
        void escrever_locacoes_cliente(long int cpf_cliente, map<int, int> locacoes);
        InformacoesLocacao informacoes_locacao(long cpf);
};

struct InformacoesLocacao{
    map<int, int> locacoes;
    int dias;
};

class ExcecaoCliente : public std::exception {
private:
    const char* _mensagem;
    
public:
    ExcecaoCliente(const char* mensagem) : _mensagem(mensagem) {}
    
    virtual const  char* what() const noexcept {
        return _mensagem;
    }
};

class ErroAbrirArquivo : public runtime_error {
    public:
         ErroAbrirArquivo() : std::runtime_error("Erro ao abrir o arquivo.") {}
};



#endif