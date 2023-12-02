#include <set>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "../../include/Clientes/Clientes.hpp"

//METODOS PRIVADOS
long long Cliente::getCPF(){
    return this->_cpf;
}

std::string Cliente::getNome(){
    return this->_nome;
}

int ControleCliente::calcula_dias(time_t data_locacao){
    time_t data_devolucao = time(0);
    const int segundosPorDia = 60 * 60 * 24;

    int diferencaSegundos = static_cast<int>(difftime(data_locacao, data_devolucao));
    int diferencaDias = diferencaSegundos / segundosPorDia;

    return diferencaDias;
};

time_t ControleCliente::encontrar_data_alocacao(long long cpf, int codigo) {
    std::ifstream banco_de_locacoes("../../data/banco_de_locacoes.csv");

    if (!banco_de_locacoes.is_open()) {
        throw ErroAbrirArquivo();
    }

    std::string linha;
    getline(banco_de_locacoes, linha);
    std::stringstream linhaStream(linha);

    std::string campo;
    std::vector<std::string> celulas;
    time_t datetime_alocacao;

    while (getline(linhaStream, campo, ',')) {
        celulas.push_back(campo);
    }

    long long cpf_csv = stol(celulas[0]);
    if (cpf_csv == cpf) {
        std::string datetime = celulas[4];
        tm tmStruct = {};
        std::istringstream ss(datetime);
        ss >> std::get_time(&tmStruct, "%Y-%m-%d %H:%M:%S");
        datetime_alocacao = mktime(&tmStruct);
    }

    banco_de_locacoes.close();
    return datetime_alocacao;
};

std::map<int, info_midia> ControleCliente::carregar_locacoes_csv_cliente(long long cpf){
    info_midia midia;
    std::map<int, info_midia> saida;
    std::ifstream banco_de_locacoes("../../data/banco_de_locacoes.csv");

    if (!banco_de_locacoes.is_open()) {
        throw ErroAbrirArquivo();
    }

    std::string linha;
    std::getline(banco_de_locacoes, linha);
    std::stringstream linhaStream(linha);

    std::string campo;
    std::vector<std::string> celulas;

    while (getline(linhaStream, campo, ',')) {
        celulas.push_back(campo);
    }

    long long cpf_csv = stol(celulas[0]);
    if (cpf_csv == cpf) {
        midia.cpf_cliente = cpf_csv;
        midia.titulo = celulas[1];
        int id = stol(celulas[2]);
        saida[id] = midia;
    }

    banco_de_locacoes.close();
    return saida;
};

//METODOS PUBLICOS
Cliente::Cliente(std::string nome, long long cpf) : _nome(nome) , _cpf(cpf) {}

void ControleCliente::listar_nome() {
    _clientes.sort([](Cliente& a, Cliente& b) {
        return a.getNome() < b.getNome();
    });

    for (auto& cliente : _clientes) {
        std::cout << cliente.getNome() << ": " << cliente.getCPF() << std::endl;
    }
};

void ControleCliente::listar_codigo() {
    for (auto& cliente : _clientes) {
        std::cout << cliente.getCPF() << ": " << cliente.getNome() << std::endl;
    }
};

bool ControleCliente::validar_CPF(long long cpf) {
    return cpf >= 10000000000 && cpf <= 99999999999;
};

void ControleCliente::remover_cliente(long long cpf) {
    for (auto it = _clientes.begin(); it != _clientes.end(); ++it) {
        if (it->getCPF() == cpf) {
            _clientes.erase(it);
            std::cout << "Cliente " << cpf << " removido com sucesso" << std::endl;
            return;
        }
    }
    throw ExcecaoCliente("ERRO: CPF inexistente");
};

void ControleCliente::cadastrar_cliente(long long cpf, std::string nome) {
    if(!validar_CPF(cpf)) {
        throw ExcecaoCliente("ERRO: dados incorretos");
    }
    else {
        for (auto& cliente : _clientes) {
            if (cliente.getCPF() == cpf) {
                throw ExcecaoCliente("ERRO: CPF repetido");
            }
        }
        Cliente novoCliente(nome, cpf);
        _clientes.push_back(novoCliente);
        std::cout << "Cliente " << cpf << " cadastrado com sucesso." << std::endl;
    }
}

void ControleCliente::midias_mais_alugadas() {
    // Mapa para armazenar a contagem de alugueis para cada titulo de midia
    std::map<std::string, int> contagem_alugueis;

    std::ifstream banco_de_locacoes("../../data/banco_de_locacoes.csv");

    if (!banco_de_locacoes.is_open()) {
        throw ErroAbrirArquivo();
    }

    std::string linha;
    while (getline(banco_de_locacoes, linha)) {
        std::stringstream linhaStream(linha);
        std::vector<std::string> celulas;
        std::string campo;

        while (getline(linhaStream, campo, ',')) {
            celulas.push_back(campo);
        }

        // Verificar se a linha possui as informacoes necessarias
        if (celulas.size() >= 4) {
            std::string titulo = celulas[1];
            contagem_alugueis[titulo]++;
        }
    }

    banco_de_locacoes.close();

    // Converter o mapa em um vetor de pares (titulo, contagem)
    std::vector<std::pair<std::string, int>> vetor_contagem(contagem_alugueis.begin(), contagem_alugueis.end());

    // Classificar o vetor com base na contagem (do maior para o menor)
    std::sort(vetor_contagem.begin(), vetor_contagem.end(),
              [](const auto &a, const auto &b) {
                  return a.second > b.second;
              });

    // Imprimir as 10 midias mais alugadas
    std::cout << "As 10 midias mais alugadas:" << std::endl;
    int contador = 0;
    for (const auto &par : vetor_contagem) {
        std::cout << "Titulo: " << par.first << ", Alugueis: " << par.second << std::endl;
        contador++;
        if (contador == 10) {
            break;
        }
    }
}

void ControleCliente::ler_informacoes_locacao(long long cpf){
    InformacoesLocacoes saida;
    saida.locacoes = this->carregar_locacoes_csv_cliente(cpf);
    int id_teste = saida.locacoes.begin()->first;
    saida.dias_desde_alocacao = this->calcula_dias(encontrar_data_alocacao(cpf, id_teste));
    this->informacoes_locacoes = saida;
};

void ControleCliente::escrever_locacoes_cliente(long long cpf, std::map<int, int> locacoes){
    std::ofstream banco_de_locacoes("../../data/banco_de_locacoes.csv", std::ios::app);
    if (!banco_de_locacoes.is_open()) {
        throw ErroAbrirArquivo();
    }

    time_t agora = time(0);

    for (auto& info_midia : locacoes) {
        banco_de_locacoes << cpf << "," << info_midia.first << "," << info_midia.second << "," << ctime(&agora) << ",,\n";
    }

    banco_de_locacoes.close();
}