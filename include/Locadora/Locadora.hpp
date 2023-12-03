#ifndef LOCADORA_H
#define LOCADORA_H

#include <map>
#include <string>
#include "../Clientes/Clientes.hpp"
#include "../ControleDeLocacao/ControleDeLocacao.hpp"

/**
 * Classe Locadora que cria objetos das classes Locador e Controle Cliente
 * Ela será responsável pelo controle do estoque e das mídias em todos os aspectos
*/
class Locadora{
    private:
        Locador central_midia_locacoes;
        ControleCliente central_de_clientes;

    public:
/**
 * Inicializa os métodos que já foram criados e explicados nas classes Locador e Controle Cliente
*/

/**
* Controle de Midias
*/
        void ler_estoque(std::string nome_do_arquivo);
        void salvar_estoque(std::string nome_do_arquivo);
        void cadastrar_midia(std::string tipo, int quantidade, int codigo, std::string titulo, std::string categoria);
        void remover_midia(int codigo_numerico);
        void ordenar_midias_por_codigo();
        void ordenar_midias_por_titulo();
        void imprimir_catalogo();
        Midia* get_midia(int codigo);

/**
 * Controle de Clientes
*/
        void cadastrar_cliente(long long cpf, std::string nome);
        void remover_cliente(long long cpf);
        void listar_clientes_por_nome();
        void listar_clientes_por_cpf();
        bool validar_CPF(long long int cpf);
        bool validar_cliente(long long int cpf);

/**
 * Controle de Locação
*/
        void alugar_midias(long long cpf, std::map<int, int> locacoes);
        void devolver_midias(long long cpf);
        void mais_alugadas();

};

#endif
