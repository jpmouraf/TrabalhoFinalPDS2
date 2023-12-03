#ifndef LOCADOR_HPP
#define LOCADOR_HPP

#include <map>
#include <string>
#include <vector>
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
        void alugar_midias(long long cpf_cliente, std::map<int, info_midia> locacoes, ControleCliente clientes);
/**
 * Recebe as informações sobre a locação e cria um mapa para armazenar temporariamente essas informações
 * Depois, imprime um recibo com as informações das mídias devolvidas, calcula o total a ser pago e devolve a mídia
 * para o armazenamento
*/
        void devolver_midias(long long cpf_cliente, ControleCliente clientes);

/**
* Gera um relatória das midias mais alugadas pelos clientes
*/
        void gerar_relatorio(ControleCliente Clientes);
/**
 * Lê as informações necessárias em um arquvio e salvaa essas informações no depósito
*/
        void ler_estoque(std::string nome_do_arquivo);
        void salvar_estoque(std::string nome_do_arquivo);

/**
* Retorna onde a mídia está localizada no armazenamento, baseada pelo seu código numérico
*/
        Midia* get_midia(int codigo);
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
        void ordenar_titulo();
        void imprimir_todas_midias();
/**
* Imprime as informações de todas as mídias contidas em armazenamento
*/
        void imprimir_catalogo();
};

/**
 * Classe de exceção para os possiveis erros relacionados ao acesso de informações no cadastro
*/
class LocaErro : public std::exception {
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
