#ifndef MIDIA_H
#define MIDIA_H

#include <string>
#include <iostream>

/**
 * É a superclasse de todas as mídias.
 * Declara as variaveis comuns: Tipo, Código numérico, Título e Unidades disponíveis
 * Além de verificar se o tipo ja foi definido ou nao
*/
class Midia {
    private:
        bool _const_tipo = false;
        std::string _tipo;
        std::string _titulo;
        int _codigo_numerico;
        int _unidades_disponiveis;

    public:
/**
* Construtor da classe Midia
*/
        Midia(int codigo_numerico, std::string titulo, int unidades_disponiveis);

/**
* Retornam as variaveis que foram declaradas como privadas
*/
        std::string getTipo();
        std::string getTitulo();
        int getCodigoNumerico();
        int getUnidadesDisponiveis();
/**
 * Imprime as informações: código, titulo e unidades disponiveis
*/
        virtual void imprimir_info();
/**
* Verifica se o atributo tipo foi definido pela primeira vez
* Caso contrário, garante que o atributo não será modificado
*/
        void setTipo(std::string tipo);
/**
 * Declara o metodo calcular_locacao como virtual puro para ser subescrito nas classes filhas
*/
        virtual int calcular_locacao(int dias) = 0;
};

#endif
