#ifndef DEPOSITO_H
#define DEPOSITO_H

#include "Midia.hpp"
#include "Dvd.hpp"
#include "Fita.hpp"
#include "Jogo.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

/**
 * Classe depósito que armazena as mídias em um map, que tem como identificador o código numérico do filme
 * Além disso, declara as variáveis tipo e categoria, que são necessárias para diferenciar os filmes entre si,
 * para fatores que as diferenciam, como o cálculo da locação
*/

class Deposito {
    private:
        map<int, Midia*> _midias;
        string tipo;
        string _categoria;
    
    public:
/**
 * Cria um construtor e um destrutor da classe Deposito
*/
        Deposito();
        ~Deposito();

/**
 * Cadastra os dvd's e os armazenam de forma dinâmica, diferenciando os filmes Promocao, Estoque e Lancamento
*/
        void cadastrar_dvd(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo, string categoria);
/**
 * Um extra da nossa locadora que adiciona um jogo na mapa das mídias
*/
        void cadastrar_jogo(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo);
/**
 *Assim como os outros, verifica se já existe uma mídia igual já cadastrada, caso contrário armazena dinamicamente 
 */             
       void cadastrar_fita(string tipo, int unidades_disponiveis, int codigo_numerico, string titulo);
/**
 * Percorre o mapa e apaga a mídia de acordo com o código númerico fornecido
*/
        void remover_midia(int codigo_numerico);
/**
 * Lê um estoque recebendo como parâmetro o nome do arquivo.
 * Ele lê cada linha do arquivo e cadastra as mídias conforme o esperado
 * Além disso, possui um contador para saber o número de mídias cadastradas
*/
        void ler_estoque(string nome_arquivo);
/**
 * Esta função aceita um parâmetro, que é o nome do arquivo onde as informações das mídias serão salvas.
 * Cria um objeto ofstream chamado estoque_saida e escreve as informações das mídias neste arquivo.
*/
        void salvar_estoque(string nome_arquivo);
/**
 * Esta é uma sobrecarga da função salvar_estoque que não requer um parâmetro explícito. 
 * Neste caso, o arquivo de destino é assumido como ../data/banco_de_midias.txt
*/
        void salvar_estoque();
/**
 * Ordena as mídias por código ou título.
 * Na ordenação por título, um caso um pouco mais complicado, foi necessário criar um map temporário,
 * que usa o título como identificador
*/
        void ordenar_codigo();
        void ordenar_titulo();
/**
 * Verifica se uma mídia com o código numérico fornecido existe no mapa _midias. 
 * Se existir, retorna um ponteiro para essa mídia. 
 * Se não existir, lança uma exceção indicando que a mídia não foi encontrada. 
*/
        Midia* get_midia(int codigo_numerico);
/**
 * Metodos que recebem o codigo numerico da mídia.
 * A primeria diminui da quantidade e a devolver mídia adiciona de volta a quantidade
*/
        void retirar_midia(int codigo_numerico, int quantidade); 
        void devolver_midia(int codigo_numerico, int quantidade); 
/**
 * Imprime as informações das mídias, código, titulo, tipo, categoria e quantidade
*/
        void imprimir_todas_midias();
/**
 * Percorre todas as mídias presentes no depósito, agrupa-as pelo nome/título e armazena no mapa categoria
 * Imprime as mídias com base em seus títulos, permitindo o acesso fácil a todas as mídias que compartilham o mesmo título.
*/
        void imprimir_todas_midias_agrupadas_nome();
};

/**
 * Classe base para exceções relacionadas ao Deposito.
 * Esta classe representa uma exceção genérica associada ao Deposito.
*/
class ExcecaoDeposito : public exception {
    private:
        const char* _mensagem;
    
    public:
        ExcecaoDeposito(char* mensagem) : _mensagem(mensagem) {}
        virtual const char* what() const noexcept {
            return _mensagem;
        }

};

/**
 * Esta classe representa uma exceção para dados que já existem no Deposito.
 * É derivada da classe ExcecaoDeposito.
*/
class DadosRepetidos : public ExcecaoDeposito {
    public:
        DadosRepetidos(char* mensagem) : ExcecaoDeposito(mensagem) {}
};

class DadosInexistente : public ExcecaoDeposito {
    public:
        DadosInexistente(char* mensagem) : ExcecaoDeposito(mensagem) {}
};

#endif
