#ifndef CLIENTES_H
#define CLIENTES_H

#include <map>
#include <list>
#include <string>
#include <iostream>

class Cliente {
    private:
        long long _cpf; ///< CPF do cliente.
        std::string _nome; ///< Nome do cliente.
 
    public:
        /**
         * Construtor da classe Cliente.
         */
        Cliente(std::string nome, long long cpf);

        /**
         * retorna o CPF do cliente.
         */    
        long long getCPF();
        /**
         * retorna o nome do cliente.
         */
        std::string getNome();
};

struct info_midia{
    std::string titulo; ///< Titulo da Midia.
    long long cpf_cliente;  ///< CPF do cliente que alocou a midia.
};

/**
 * Estrutura para armazenar informacoes sobre locacoes de um cliente.
 */
struct InformacoesLocacoes{
    int dias_desde_alocacao; ///< Número de dias de locacao.
    std::map<int, info_midia> locacoes; ///< Mapa que associa codigos de locacao a informacoes da midia.
};

class ControleCliente {
    private:
        std::list<Cliente> _clientes; ///< Lista de clientes.

        /**
         * Calcula o número de dias desde a data de locacao.
         */
        int calcula_dias(time_t data_locacao);
        /**
        * Encontra a data da alocacao feita pelo cliente baseado em seu cpf e pelo codigo do filme
        */ 
        time_t encontrar_data_alocacao(long long cpf, int codigo);
        /**
        * Recebe o cpf e armazena todas as locacoes dele
        */
        std::map<int, info_midia> carregar_locacoes_csv_cliente(long long cpf);

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
        * Valida o cpf de acordo com a sua entrada. Verdadeiro se o CPF for valido, falso caso contrario.
        */
        bool validar_CPF(long long cpf);
        /**
        * Remove um cliente cadastrado de acordo com o seu cpf
        */
        void remover_cliente(long long cpf);
        /**
         * Cadastra um novo cliente a partir do seu cpf e nome
         */
        void cadastrar_cliente(long long cpf, std::string nome);

        /**
         * Imprime um relatorio informando as 10 midias mais alugadas na nossa locadora.
         */
        void midias_mais_alugadas();
        /**
         * Armazena informacoes de locacao para um cliente.
         */
        InformacoesLocacoes informacoes_locacoes;
        /**
         * Obtem informacoes de locacao para um cliente.
         */
        void ler_informacoes_locacao(long long cpf);
        /**
         * Escreve as locacoes de um cliente e a armazena no map criado
         */
        void escrever_locacoes_cliente(long long cpf, std::map<int, int> locacoes);
        
};

class ExcecaoCliente : public std::exception {
    private:
        const char* _mensagem; ///< Mensagem de excecao.

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
 * Classe para excecao relacionada a erro ao abrir arquivo.
 */
class ErroAbrirArquivo : public std::runtime_error {
    public:

        ErroAbrirArquivo() : std::runtime_error("Erro ao abrir o arquivo.") {}
};



#endif
