#include "Locador.hpp"
#include <iostream>
#include <map>
using namespace std;

//este módulo ainda não possui capacidades de armazenamento/edição das locações de um cliente.

void Locador::alugar_midias(long int cpf_cliente, map<int, int> locacoes, ControleCliente clientes){ // futuramente adicionar um handler de exceção para quando o cliente quer alugar uma mídia que não existe no sistema.
    clientes.escrever_locacoes_cliente(cpf_cliente, locacoes);
    cout << "######### Recibo de Locação ###########" << endl;
    cout << "CPF: " << cpf_cliente << endl << endl;
    for (auto it : locacoes){
        int codigo_midia = it.first;
        int quantidade_midia = it.second;
        
        Midia* locada = armazenamento.get_midia(codigo_midia);
        cout << "Mídia: " << locada->getTitulo() << "Quantidade: x" << quantidade_midia << endl;

        armazenamento.retirar_midia(codigo_midia, quantidade_midia);
    }
    cout << endl;
    cout << "######### Fim  do  Recibo ###########" << endl;
}

void Locador::devolver_midias(long int cpf_cliente, int dias, ControleCliente clientes){ //futuramente adicionar um handler de exceção para quando o cliente quer devolver uma mídia que não existe no sistema.
    map<int, int> locacoes = clientes.ler_locacoes_cliente(cpf_cliente);
    cout << "######### Recibo de Aluguel ###########" << endl;
    cout << "CPF: " << cpf_cliente << endl << endl;
    int total_locacao;
    for (auto it : locacoes){
        int codigo_midia = it.first;
        int quantidade_midia = it.second;
        Midia* devolvida = armazenamento.get_midia(codigo_midia);
        
        cout << "Mídia: " << devolvida->getTitulo() << "Quantidade: x" << quantidade_midia << " ";
        int total_midia;
        for(int i = 0; i<quantidade_midia; i++){
            total_midia += devolvida->calcular_locacao(dias);
        }
        cout << "Total: " << total_midia << " reais" << endl;
        total_locacao += total_midia;

        armazenamento.devolver_midia(codigo_midia, quantidade_midia);
    }
    cout << endl;
    cout << "Total a ser pago: " << total_locacao << " reais" << endl;
    cout << "######### Fim  do  Recibo ###########" << endl;
}