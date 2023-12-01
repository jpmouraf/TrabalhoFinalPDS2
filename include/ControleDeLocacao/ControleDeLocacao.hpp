#ifndef LOCADOR_HPP
#define LOCADOR_HPP

#include <string>
#include <vector>
#include <ctime>
#include "../Clientes/Clientes.hpp"
#include "../ControleDeMidia/Deposito.hpp"


class Locador {
    private:
        Deposito armazenamento;

        time_t encontrar_data_alocacao(long cpf, int codigo);
        int calcula_dias(time_t data_locacao);
        void gravar_locacoes_csv(long int cpf_cliente, map<int, int> locacoes);

    public:
        void alugar_midias(long int cpf_cliente, map<int, int> locacoes, ControleCliente clientes);
        void devolver_midias(long int cpf_cliente, int dias, ControleCliente clientes);
        void gerar_relatorio(); //EXTRA
        void ler_estoque(std::string nome_do_arquivo);
        void salvar_estoque(std::string nome_do_arquivo);
        void cadastrar_midia(std::string tipo, int quantidade, int codigo, std::string titulo, std::string categoria);
        void remover_midia(int codigo_numerico);
        void ordenar_codigo();
        void ordenar_titulo();
        void imprimir_todas_midias();
};

class LocaErro : public exception {
    private:
        char* _mensagem;
    
    public:
        LocaErro(char* mensagem) : _mensagem(mensagem) {}
        char* what() const throw() {
            return _mensagem;
        }
};

class ErroArquivo : public LocaErro {
    public:
        ErroArquivo(char* mensagem) : LocaErro(mensagem) {}
};


#endif
