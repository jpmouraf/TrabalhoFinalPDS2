#ifndef MIDIA_H
#define MIDIA_H

#include <string>
#include <iostream>

using namespace std;

/**
 * É a superclasse de todas as mídias.
 * Declara as variaveis comuns: Código numérico, Título e Unidades disponíveis
*/
class Midia {
    private:
        int _codigo_numerico;
        string _titulo;
        int _unidades_disponiveis;
        
    public:
/**
* Construtor da classe Midia
*/
        Midia(int codigo_numerico, string titulo, int unidades_disponiveis);
/**
* Retorna as variaveis que foram declaradas como privadas
*/
        int getCodigoNumerico();
        string getTitulo();
        int getUnidadesDisponiveis();
/**
 * Imprime as informações: código, titulo e unidades disponiveis
*/
        virtual void imprimir_info();
/**
 * Declara os metodos virtuais puros que serão sobrescritos nas classes filhas
*/
        virtual string gettipo() = 0;
        virtual int calcular_locacao(int dias) = 0;
};


#endif
