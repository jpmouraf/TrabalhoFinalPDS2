#ifndef CLIENTES_H
#define CLIENTES_H

#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

/**
 * Estrutura para armazenar informações sobre locações de um cliente.
 */
struct InformacoesLocacao {
    map<int, int> locacoes; ///< Mapa que associa códigos de locação a dias.
    int dias; ///< Número de dias de locação.
};

/**
 * Classe que representa um cliente.
 */
class Cliente {
private:
    string _nome; ///< Nome do cliente.
    long int _cpf; ///< CPF do cliente.

public:
    /**
     * Construtor da classe Cliente.
     */
    Cliente(string nome, long int cpf);

    /**
     * retorna o CPF do cliente.
     */
    long int getCPF();

    /**
     * retorna o nome do cliente.
     */
    string getNome();
};

/**
 * Classe para controle de clientes.
 */
class ControleCliente {
private:
    list<Cliente> _clientes; ///< Lista de clientes.

    void escrever_data_devolucao();

    /**
     * Encontra a data da alocação feita pelo cliente baseado em seu cpf e pelo código do filme
     */
    time_t encontrar_data_alocacao(long cpf, int codigo);

    /**
     * Calcula o número de dias desde a data de locação.
     */
    int calcula_dias(time_t data_locacao);

    /**
     * Recebe o cpf e o codigo e armazena as locações
     */
    map<int, int> locacoes_cliente(long cpf);

public:
    /**
     * Valida o cpf de acordo com a sua entrada. Verdadeiro se o CPF for válido, falso caso contrário.
     */
    bool validarCPF(long int cpf);

    /**
     * Cadastra um novo cliente a partir do seu cpf e nome
     */
    void cadastrar_cliente(long int cpf, string nome);

    /**
     * Remove um cliente cadastrado de acordo com o seu cpf
     */
    void remover_cliente(long int cpf);

    /**
     * Lista os clientes em ordem de cpf
     */
    void listar_codigo();

    /**
     * Lista os clientes em ordem alfabetica
     */
    void listar_nome();

    /**
     * Escreve as locações de um cliente e a armazena no map criado
     */
    void escrever_locacoes_cliente(long int cpf_cliente, map<int, int> locacoes);

    /**
     * Obtém informações de locação para um cliente.
     */
    InformacoesLocacao informacoes_locacao(long cpf);
};

/**
 * Classe para exceção relacionada a clientes.
 */
class ExcecaoCliente : public std::exception {
private:
    const char* _mensagem; ///< Mensagem de exceção.

public:

    ExcecaoCliente(const char* mensagem) : _mensagem(mensagem) {}

    /**
     * retorna a mensagem de excecao de acordo com o tipo especifico necessario
     */
    virtual const char* what() const noexcept {
        return _mensagem;
    }
};

/**
 * Classe para exceção relacionada a erro ao abrir arquivo.
 */
class ErroAbrirArquivo : public runtime_error {
public:

    ErroAbrirArquivo() : std::runtime_error("Erro ao abrir o arquivo.") {}
};

#endif