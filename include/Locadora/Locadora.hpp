#ifndef LOCADORA_H
#define LOCADORA_H

#include <map>
#include <string>
#include "../Clientes/Clientes.hpp"
#include "../ControleDeLocacao/ControleDeLocacao.hpp"

class Locadora{
    private:
        Locador central_midia_locacoes;
        ControleCliente central_de_clientes;

    public:
        // Controle de Midias
        void ler_estoque(std::string nome_do_arquivo);
        void salvar_estoque(std::string nome_do_arquivo);
        void cadastrar_midia(std::string tipo, int quantidade, int codigo, std::string titulo, std::string categoria);
        void remover_midia(int codigo_numerico);
        void ordenar_midias_por_codigo();
        void ordenar_midias_por_titulo();
        void imprimir_catalogo();

        // Controle de Clientes
        void cadastrar_cliente(long cpf, std::string nome);
        void remover_cliente(long cpf);
        void listar_clientes_por_nome();
        void listar_clientes_por_cpf();

        // Controle de Locacao
        void alugar_midias(long cpf, std::map<int, int> locacoes);
        void devolver_midias(long cpf);

};

#endif