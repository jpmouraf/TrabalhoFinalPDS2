#ifndef LOCADOR_HPP
#define LOCADOR_HPP

#include <string>
#include <vector>
#include "../Clientes/Clientes.hpp"
#include "../ControleDeMidia/Deposito.hpp"


class Locador {
    private:
        Deposito armazenamento;

    public:
        void alugar_midias(long int cpf_cliente, map<int, int> locacoes, ControleCliente clientes);
        void devolver_midias(long int cpf_cliente, int dias, ControleCliente clientes);
        void gerar_relatorio();
        void ler_estoque(std::string nome_do_arquivo);
        void salvar_estoque(std::string nome_do_arquivo);
        void cadastrar_midia(std::string tipo, int quantidade, int codigo, std::string titulo, std::string categoria);
        void remover_midia(int codigo_numerico);
        void ordenar_codigo();
        void ordenar_titulo();
        void imprimir_todas_midias();
};

#endif