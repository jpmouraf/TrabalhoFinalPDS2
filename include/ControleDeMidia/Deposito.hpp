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

/**
 * Classe depósito que armazena as mídias em um map, que tem como identificador o código numérico do filme
 * Além disso, declara as variáveis tipo e categoria, que são necessárias para diferenciar os filmes entre si,
 * para fatores que as diferenciam, como o cálculo da locação
*/
class Deposito {
    private:
        std::string tipo;
        std::string _categoria;
        std::map<int, Midia*> _midias;
    
    public:
        Deposito();
        ~Deposito();
        /**
        * Recebe uma quantidade, um código e um título, e cadastra um jogo no sistema
        */  
        void cadastrar_jogo(int unidades_disponiveis, int codigo_numerico, std::string titulo);
        /**
        * Recebe uma quantidade, um código e um título, e cadastra uma fita no sistema
        */  
        void cadastrar_fita(int unidades_disponiveis, int codigo_numerico, std::string titulo);
        /**
        * Recebe uma quantidade, um código, um título e uma categoria, e cadastra um dvd no sistema
        */  
        void cadastrar_dvd(int unidades_disponiveis, int codigo_numerico, std::string titulo, std::string categoria);
        /**
        * Recebe um codigo numerico e remove uma mídia do sistema
        */
        void remover_midia(int codigo_numerico);
        /**
        * Recebe um nome de arquivo (ou caminho) e abre o arquivo para leitura de mídias
        */
        void ler_estoque(std::string nome_arquivo);
        /**
        * Recebe um nome de arquivo (ou caminho) e abre o arquivo para salvar mídias atualmente no sistema
        */
        void salvar_estoque(std::string nome_arquivo);
        /**
        * Salva as mídias atualmente no sistema no arquivo default (banco_de_midias.txt)
        */
        void salvar_estoque();
        /**
        * Imprime todas as mídias, ordenadas alfabeticamente
        */
        
        void ordenar_titulo();
        /**
        * Imprime todas as mídias, ordenadas por código numerico
        */
        void imprimir_todas_midias();
        /**
        * Busca e retorna uma midia no sistema a partir do codigo numerico dado
        */

        Midia* get_midia(int codigo_numerico);
        /**
        * Imprime todas as midias no sistema, suas quantidades e codigos numericos, agrupadas por titulo.
        */
        void imprimir_catalogo();
        /**
        * Recebe um codigo numerico e retira uma unidade de uma mídia do sistema
        */
        void retirar_midia(int codigo_numerico, int quantidade);
        /**
        * Recebe um codigo numerico e adiciona uma unidade de uma mídia do sistema
        */
        void devolver_midia(int codigo_numerico, int quantidade);
};

/**
 * Classe base para exceções relacionadas ao Deposito.
 * Esta classe representa uma exceção genérica associada ao Deposito.
*/
class ExcecaoDeposito : public std::exception {
    private:
        const char* _mensagem;
    
    public:
        ExcecaoDeposito(char* mensagem) : _mensagem(mensagem) {}
        virtual const char* what() const noexcept {
            return _mensagem;
        }

};

/**
 * Estas subclasses representam exceções específicas para dados que já existem no Deposito ou dados inexistentes.
 * São derivadas da classe ExcecaoDeposito.
*/
class DadosRepetidos : public ExcecaoDeposito {
    public:
        DadosRepetidos(char* mensagem) : ExcecaoDeposito(mensagem) {}
};

class DadosInexistente : public ExcecaoDeposito {
    public:
        DadosInexistente(char* mensagem) : ExcecaoDeposito(mensagem) {}
};

/** 
 * Estas classes são derivadas da classe runtime_error e são usadas para sinalizar
 * um erro que ocorre ao tentar abrir um arquivo ou arquivos com formatos inválidos.
 */
class ArquivoInexistente : public std::runtime_error {
    public:
        ArquivoInexistente(char* mensagem) : std::runtime_error(mensagem) {}
};

class FormatoInvalido : public std::runtime_error {
    public:
        FormatoInvalido(char* mensagem) : std::runtime_error(mensagem) {}
};

#endif
