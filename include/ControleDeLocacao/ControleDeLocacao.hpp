#ifndef LOCADOR_HPP
#define LOCADOR_HPP

#include <string>
#include <vector>
#include <ctime>
#include "../Clientes/Clientes.hpp"
#include "../ControleDeMidia/Deposito.hpp"

/**
 * Classe locador responsável por todo o controle de locação da locadora
*/

class Locador {
    private:
/**
 * Inicializa um objeto da classe depósito que irá auxiliar nas funções, salvando as informações 
*/
        Deposito armazenamento;

    public:
/**
 * Recebe as informações do cliente em escrever_locacao_cliente e imprime um recibo para o cliente
 * com o seu cpf, quais filmes e quantidade alugadas por ele. Além de retirar a mídia do armazenamento
*/
        void alugar_midias(long int cpf_cliente, map<int, int> locacoes, ControleCliente clientes);
/**
 * Recebe as informações sobre a locação e cria um mapa para armazenar temporariamente essas informações
 * Depois, imprime um recibo com as informações das mídias devolvidas, calcula o total a ser pago e devolve a mídia
 * para o armazenamento
*/
        void devolver_midias(long int cpf_cliente, ControleCliente clientes);
/**
 * ler as informações necessárias em um arquvio e salvar essas informações no depósito
*/
        void ler_estoque(std::string nome_do_arquivo);
        void salvar_estoque(std::string nome_do_arquivo);
/**
 * Cadastra a mídia no sistema, diferenciando se é fita ou DVD, além das informações básicas, como quantidade, código e título
*/
        void cadastrar_midia(std::string tipo, int quantidade, int codigo, std::string titulo, std::string categoria);
/**
 * Remove as midias do armazenamento, recebendo como parâmetro o código numérico
*/
        void remover_midia(int codigo_numerico);
/**
 * Ordena as midias em ordem de código númerico e pelo título
*/
        void ordenar_codigo();
        void ordenar_titulo();
/**
 * Imprime as informações de todas as mídias cadastradas no armazenamento
*/
        void imprimir_todas_midias();
};

/**
 * Classe de exceção para os possiveis erros relacionados ao acesso de informações no cadastro
*/

class LocaErro : public exception {
    private:
        const char* _mensagem;
    
    public:
        LocaErro(const char* mensagem) : _mensagem(mensagem) {}
        
        virtual const char* what() const noexcept {
            return _mensagem;
        }
};

/**
 * Sublasse da LocaErro, para os casos específicos de erro ao abrir ou manusear um arquivo
*/

class ErroArquivo : public LocaErro {
    public:
        ErroArquivo(char* mensagem) : LocaErro(mensagem) {}
};


#endif
