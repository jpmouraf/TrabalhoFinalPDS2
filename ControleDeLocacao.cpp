#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "../../include/ControleDeLocacao/ControleDeLocacao.hpp"

using namespace std;

//PRIVATE
time_t encontrar_data_alocacao(long cpf, int codigo) {
    ifstream banco_de_locacoes("../../data/banco_de_locacoes.csv");

    if (!banco_de_locacoes.is_open()) {
        throw ErroArquivo ("Erro ao abrir o arquivo");
    }

    string linha;
    getline(banco_de_locacoes, linha);
    stringstream linhaStream(linha);

    string campo;
    vector<string> celulas;

    while (getline(linhaStream, campo, ',')) {
        celulas.push_back(campo);
    }

    long cpf_csv = stol(celulas[0]);
    if (cpf_csv == cpf) {
        string datetime = celulas[3];
        tm tmStruct = {};
        istringstream ss(datetime);
        ss >> get_time(&tmStruct, "%Y-%m-%d %H:%M:%S");
        time_t tempo = mktime(&tmStruct);
        cout << "Valor de time_t: " << tempo << endl;
        banco_de_locacoes.close();
        return tempo;
    }

    banco_de_locacoes.close();
    // throw exception
}

void gravar_locacoes_csv(long int cpf_cliente, map<int, int> locacoes){
    ofstream banco_de_locacoes("../../data/banco_de_locacoes.csv", ios::app);
    if (!banco_de_locacoes.is_open()) {
        throw ErroArquivo ("Erro ao abrir o arquivo");
    }

    time_t agora = time(0);

    for (auto& info_midia : locacoes) {
        banco_de_locacoes << cpf_cliente << "," << info_midia.first << "," << info_midia.second << "," << ctime(&agora) << ",,\n";
    }

    banco_de_locacoes.close();
}

int calcula_dias(time_t data_locacao){
    time_t data_devolucao = time(0);
    const int segundosPorDia = 60 * 60 * 24;

    int diferencaSegundos = static_cast<int>(difftime(data_locacao, data_devolucao));
    int diferencaDias = diferencaSegundos / segundosPorDia;

    return diferencaDias;
}

//PUBLIC

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
