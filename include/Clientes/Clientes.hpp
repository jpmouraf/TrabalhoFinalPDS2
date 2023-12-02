#ifndef CLIENTES_H
#define CLIENTES_H

#include <map>
#include <list>
#include <string>
#include <iostream>

class Cliente {
    private:
        long int _cpf; ///< CPF do cliente.
        std::string _nome; ///< Nome do cliente.
 
    public:
        /**
         * Construtor da classe Cliente.
         */
        Cliente(std::string nome, long int cpf);

        /**
         * retorna o CPF do cliente.
         */    
        long int getCPF();
        /**
         * retorna o nome do cliente.
         */
        std::string getNome();
};

struct info_midia{
    std::string titulo; ///< Titulo da Midia.
    long int cpf_cliente;  ///< CPF do cliente que alocou a mídia.
};

/**
 * Estrutura para armazenar informações sobre locações de um cliente.
 */
struct InformacoesLocacoes{
    int dias_desde_alocacao; ///< Número de dias de locação.
    std::map<int, info_midia> locacoes; ///< Mapa que associa códigos de locação a informacoes da midia.
};

class ControleCliente {
    private:
        std::list<Cliente> _clientes; ///< Lista de clientes.

        /**
         * Calcula o número de dias desde a data de locação.
         */
        int calcula_dias(time_t data_locacao);
        /**
        * Encontra a data da alocação feita pelo cliente baseado em seu cpf e pelo código do filme
        */ 
        time_t encontrar_data_alocacao(long cpf, int codigo);
        /**
        * Recebe o cpf e armazena todas as locações dele
        */
        std::map<int, info_midia> carregar_locacoes_csv_cliente(long cpf);

    public:
        /**
         * Lista os clientes em ordem alfabetica
         */
        void listar_nome();
        /**
         * Lista os clientes em ordem de cpf
         */
        void listar_codigo();
        /**
        * Valida o cpf de acordo com a sua entrada. Verdadeiro se o CPF for válido, falso caso contrário.
        */
        bool validar_CPF(long int cpf);
        /**
        * Remove um cliente cadastrado de acordo com o seu cpf
        */
        void remover_cliente(long int cpf);
        /**
         * Cadastra um novo cliente a partir do seu cpf e nome
         */
        void cadastrar_cliente(long int cpf, std::string nome);

        /**
         * Imprime um relatório informando as 10 midias mais alugadas na nossa locadora.
         */
        void midias_mais_alugadas();
        /**
         * Armazena informações de locação para um cliente.
         */
        InformacoesLocacoes informacoes_locacoes;
        /**
         * Obtém informações de locação para um cliente.
         */
        void ler_informacoes_locacao(long int cpf);
        /**
         * Escreve as locações de um cliente e a armazena no map criado
         */
        void escrever_locacoes_cliente(long int cpf, std::map<int, int> locacoes);
        
};

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
class ErroAbrirArquivo : public std::runtime_error {
    public:

        ErroAbrirArquivo() : std::runtime_error("Erro ao abrir o arquivo.") {}
};



#endif
