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

    public:
        void alugar_midias(long int cpf_cliente, map<int, int> locacoes, ControleCliente clientes);
        void devolver_midias(long int cpf_cliente, ControleCliente clientes);
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
        const char* _mensagem;
    
    public:
        LocaErro(const char* mensagem) : _mensagem(mensagem) {}
        
        virtual const char* what() const noexcept {
            return _mensagem;
        }
};

class ErroArquivo : public LocaErro {
    public:
        ErroArquivo(char* mensagem) : LocaErro(mensagem) {}
};


#endif
