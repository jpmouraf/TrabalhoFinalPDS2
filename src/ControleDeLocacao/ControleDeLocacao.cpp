#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "../../include/ControleDeLocacao/ControleDeLocacao.hpp"

using namespace std;

void Locador::alugar_midias(long int cpf_cliente, map<int, int> locacoes, ControleCliente clientes){ // futuramente adicionar um handler de exceção para quando o cliente quer alugar uma mídia que não existe no sistema.
    clientes.escrever_locacoes_cliente(cpf_cliente, locacoes);
    cout << "######### Recibo de Locação ###########" << endl;
    cout << "CPF: " << cpf_cliente << endl << endl;
    for (auto it : locacoes){
        int codigo_midia = it.first;
        int quantidade_midia = it.second;
        try {
            Midia* locada = armazenamento.get_midia(codigo_midia);
            cout << "Mídia: " << locada->getTitulo() << "Quantidade: x" << quantidade_midia << endl;
        } catch(DadosInexistente e) {
            throw;
        }
        armazenamento.retirar_midia(codigo_midia, quantidade_midia);
    }
    cout << endl;
    cout << "######### Fim  do  Recibo ###########" << endl;
}

void Locador::devolver_midias(long int cpf_cliente, ControleCliente clientes){ //futuramente adicionar um handler de exceção para quando o cliente quer devolver uma mídia que não existe no sistema.
    InformacoesLocacao info = clientes.informacoes_locacao(cpf_cliente);
    map<int, int> locacoes = info.locacoes;
    int dias = info.dias;
    cout << "######### Recibo de Aluguel ###########" << endl;
    cout << "CPF: " << cpf_cliente << endl << endl;
    int total_locacao;
    for (auto it : locacoes){
        int codigo_midia = it.first;
        int quantidade_midia = it.second;
        try {
            armazenamento.devolver_midia(codigo_midia, quantidade_midia);

            Midia* devolvida = armazenamento.get_midia(codigo_midia);
            
            cout << "Mídia: " << devolvida->getTitulo() << "Quantidade: x" << quantidade_midia << " ";
            int total_midia;
            for(int i = 0; i<quantidade_midia; i++){
                total_midia += devolvida->calcular_locacao(dias);
            }
            cout << "Total: " << total_midia << " reais" << endl;
            total_locacao += total_midia;
        } catch(DadosInexistente e){ //mudar para exceção de código de filme não existente
            cout << "[LOCADOR] Atenção: código de filme alugado '" << codigo_midia <<"' inexistente, verifique se o filme não foi retirado do sistema durante o período da locação." << endl;
            continue;
        }
    }
    cout << endl;
    cout << "Total a ser pago: " << total_locacao << " reais" << endl;
    cout << "######### Fim  do  Recibo ###########" << endl;
}

void Locador::ler_estoque(string nome_do_arquivo){
    this->armazenamento.ler_estoque(nome_do_arquivo);
}

void Locador::salvar_estoque(std::string nome_do_arquivo){
    this->armazenamento.salvar_estoque(nome_do_arquivo);
}


void Locador::cadastrar_midia(string tipo, int quantidade, int codigo, string titulo, string categoria){
    if (tipo == "F"){
        this->armazenamento.cadastrar_fita("FITA", quantidade, codigo, titulo);
    }

    else if (tipo == "D"){
        this->armazenamento.cadastrar_dvd("DVD", quantidade, codigo, titulo, categoria);
    }

    else {
        throw LocaErro("ERRO: não foi posível identificar o tipo de midia escolhida");
    }
}

void Locador::remover_midia(int codigo_numerico){
    this->armazenamento.remover_midia(codigo_numerico);
}

void Locador::ordenar_codigo(){
    this->armazenamento.ordenar_codigo();
}

void Locador::ordenar_titulo(){
    this->armazenamento.ordenar_titulo();
}

void Locador::imprimir_todas_midias(){
    this->armazenamento.imprimir_todas_midias();
}
