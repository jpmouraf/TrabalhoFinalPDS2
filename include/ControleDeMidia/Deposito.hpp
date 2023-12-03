#ifndef DEPOSITO_H
#define DEPOSITO_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "Dvd.hpp"
#include "Fita.hpp"
#include "Jogo.hpp"
#include "Midia.hpp"

class Deposito {
    private:
        std::string tipo;
        std::string _categoria;
        std::map<int, Midia*> _midias;
    
    public:
        Deposito();
        ~Deposito();

        void cadastrar_jogo(int unidades_disponiveis, int codigo_numerico, std::string titulo);
        void cadastrar_fita(int unidades_disponiveis, int codigo_numerico, std::string titulo);
        void cadastrar_dvd(int unidades_disponiveis, int codigo_numerico, std::string titulo, std::string categoria);

        void remover_midia(int codigo_numerico);
        void ler_estoque(std::string nome_arquivo);
        void salvar_estoque(std::string nome_arquivo);

        void salvar_estoque();
        void ordenar_codigo();
        void ordenar_titulo();

        void imprimir_todas_midias();
        Midia* get_midia(int codigo_numerico);
        void imprimir_catalogo();
        void retirar_midia(int codigo_numerico, int quantidade); // se alguem pensar em nomes melhores para essas
        void devolver_midia(int codigo_numerico, int quantidade); // funcoes por favor sinta-se livre para mudar
};

class ExcecaoDeposito : public std::exception {
    private:
        const char* _mensagem;
    
    public:
        ExcecaoDeposito(char* mensagem) : _mensagem(mensagem) {}
        virtual const char* what() const noexcept {
            return _mensagem;
        }

};

class DadosRepetidos : public ExcecaoDeposito {
    public:
        DadosRepetidos(char* mensagem) : ExcecaoDeposito(mensagem) {}
};

class DadosInexistente : public ExcecaoDeposito {
    public:
        DadosInexistente(char* mensagem) : ExcecaoDeposito(mensagem) {}
};

class ArquivoInexistente : public std::runtime_error {
    public:
        ArquivoInexistente(char* mensagem) : std::runtime_error(mensagem) {}
};

class FormatoInvalido : public std::runtime_error {
    public:
        FormatoInvalido(char* mensagem) : std::runtime_error(mensagem) {}
};

#endif