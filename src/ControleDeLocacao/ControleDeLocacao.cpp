#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../../include/ControleDeLocacao/ControleDeLocacao.hpp"

void Locador::alugar_midias(long int cpf_cliente, std::map<int, int> locacoes, ControleCliente clientes){ // futuramente adicionar um handler de exceção para quando o cliente quer alugar uma mídia que não existe no sistema.
    clientes.escrever_locacoes_cliente(cpf_cliente, locacoes);
    std::cout << "######### Recibo de Locação ###########" << std::endl;
    std::cout << "CPF: " << cpf_cliente << std::endl << std::endl;
    for (auto it : locacoes){
        int codigo_midia = it.first;
        int quantidade_midia = it.second;
        try {
            Midia* locada = armazenamento.get_midia(codigo_midia);
            std::cout << "Mídia: " << locada->getTitulo() << "Quantidade: x" << quantidade_midia << std::endl;
        } catch(DadosInexistente &e) {
            throw;
        }
        armazenamento.retirar_midia(codigo_midia, quantidade_midia);
    }
    std::cout << std::endl;
    std::cout << "######### Fim  do  Recibo ###########" << std::endl;
}

void Locador::devolver_midias(long int cpf_cliente, ControleCliente clientes){ //futuramente adicionar um handler de exceção para quando o cliente quer devolver uma mídia que não existe no sistema.
    clientes.ler_informacoes_locacao(cpf_cliente);
    std::map<int, info_midia> locacoes = clientes.informacoes_locacoes.locacoes;
    int dias = clientes.informacoes_locacoes.dias_desde_alocacao;
    std::cout << "######### Recibo de Aluguel ###########" << std::endl;
    std::cout << "CPF: " << cpf_cliente << std::endl << std::endl;
    int total_locacao;
    for (auto it : locacoes){
        int codigo_midia = it.first;
        int quantidade_midia = 1;
        try {
            armazenamento.devolver_midia(codigo_midia, quantidade_midia);

            Midia* devolvida = armazenamento.get_midia(codigo_midia);
            
            std::cout << "Mídia: " << devolvida->getTitulo() << "Quantidade: x" << quantidade_midia << " ";
            int total_midia;
            for(int i = 0; i<quantidade_midia; i++){
                total_midia += devolvida->calcular_locacao(dias);
            }
            std::cout << "Total: " << total_midia << " reais" << std::endl;
            total_locacao += total_midia;
        } catch(DadosInexistente &e){ //mudar para exceção de código de filme não existente
            std::cout << "[LOCADOR] Atenção: código de filme alugado '" << codigo_midia <<"' inexistente, verifique se o filme não foi retirado do sistema durante o período da locação." << std::endl;
            continue;
        }
    }
    std::cout << std::endl;
    std::cout << "Total a ser pago: " << total_locacao << " reais" << std::endl;
    std::cout << "######### Fim  do  Recibo ###########" << std::endl;
}

void Locador::gerar_relatorio(ControleCliente Clientes){
    Clientes.midias_mais_alugadas();
}

void Locador::ler_estoque(std::string nome_do_arquivo){
    this->armazenamento.ler_estoque(nome_do_arquivo);
}

void Locador::salvar_estoque(std::string nome_do_arquivo){
    this->armazenamento.salvar_estoque(nome_do_arquivo);
}


void Locador::cadastrar_midia(std::string tipo, int quantidade, int codigo, std::string titulo, std::string categoria){
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
