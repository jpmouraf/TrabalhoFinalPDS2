#include "Locador.hpp"
#include <iostream>
#include <map>
using namespace std;

void Locador::alugar_midias(long int cpf_cliente, ControleCliente clientes){
    // receber cpf
    // usar cpf para pegar dados do cliente
    map<int, int> locacoes = clientes.ler_locacoes_cliente(cpf_cliente);
    for (auto it : locacoes){
        int codigo_midia = it.first;
        //adicionar checagem de programação defensiva para impedir o cliente de alugar mais cópias do que há disponíveis
        int quantidade_midia = it.second;
        armazenamento.remover_midia_no_estoque(codigo_midia, quantidade_midia);
    }
}

void Locador::devolver_midias(long int cpf_cliente){
    
}