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
#include <filesystem>
#include <algorithm>
#include "../../include/Clientes/Clientes.hpp"
#include "../../include/ControleDeMidia/Deposito.hpp"

using namespace std;

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

    return abs(diferencaDias);
};

time_t ControleCliente::encontrar_data_alocacao(std::string data) {
    time_t datetime_alocacao;
    tm tmStruct = {};
    std::istringstream ss(data);
    ss >> std::get_time(&tmStruct, "%a %b %d %H:%M:%S %Y");
    datetime_alocacao = mktime(&tmStruct);
    return datetime_alocacao;
};

std::map<int, info_midia> ControleCliente::carregar_locacoes_csv_cliente(long long cpf){
    info_midia midia;
    std::map<int, info_midia> saida;
    std::filesystem::path caminho = std::filesystem::current_path()/"../data/banco_de_locacoes.csv";
    std::string nome_arquivo = caminho.string();
    std::ifstream banco_de_locacoes(caminho);

    if (!banco_de_locacoes.is_open()) {
        throw ErroAbrirArquivo();
    }

    vector<vector<string>> banco;
    std::string linha;
    std::getline(banco_de_locacoes, linha);//descartar headers
    while (std::getline(banco_de_locacoes, linha)){
        stringstream temp(linha);
        vector<string> lidos;
        std::string celula;
        while (getline(temp, celula, ',')) {
            lidos.push_back(celula);
        }
        banco.push_back(lidos);
    }
    
    for(auto linha: banco){
        long long int cpf_csv = stoi(linha[0]);
        if(cpf == cpf_csv){
            midia.cpf_cliente = cpf_csv;
            midia.titulo = linha[1];
            midia.quantidade = stoi(linha[3]);
            midia.data = linha[4];
            int id = stoi(linha[2]);
            saida[id] = midia;
        }
    }

    banco_de_locacoes.close();
    return saida;
};

//METODOS PUBLICOS
Cliente::Cliente(std::string nome, long long cpf) : _nome(nome) , _cpf(cpf) {}

ControleCliente::ControleCliente() {
    std::filesystem::path caminho = std::filesystem::current_path()/"../data/banco_de_clientes.txt";
    std::string nome_arquivo = caminho.string();
    std::cout << "Lendo informacoes de clientes da seguinte database (arquivo): " << nome_arquivo << std::endl;
    if (nome_arquivo.find(".txt") == std::string::npos) {
        throw FormatoInvalido("[DPST] ERRO: Você selecionou um formato de arquivo inválido. Apenas TXT são aceitos");
    }

    std::ifstream arquivo(nome_arquivo);
    if (arquivo.is_open()) {
        std::string linha;
        int contador = 0;

        while (std::getline(arquivo, linha)) {
            std::stringstream linhaStream(linha);
            std::string nome;
            long long cpf;

            linhaStream >> cpf >> nome;
            if (!validar_CPF(cpf)){
                arquivo.close();
                break;
            }
            this->cadastrar_cliente(cpf, nome);
            contador++;
        }

        arquivo.close();
        if (contador >= 1){
            std::cout << contador << " Clientes cadastrados com sucesso" << std::endl;
        }
    } else {
        throw ExcecaoCliente("ERRO: arquivo inexistente");
    }
}

ControleCliente::~ControleCliente(){
    std::filesystem::path caminho = std::filesystem::current_path()/"../data/banco_de_clientes.txt";
    std::string nome_arquivo = caminho.string();
    std::ofstream banco_de_clientes(nome_arquivo);

    for (auto& cliente : this->_clientes){
        banco_de_clientes << cliente.getCPF() << " " << cliente.getNome() << '\n';
    }
    
    banco_de_clientes.close();
}

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
    return cpf > 0 && cpf <= 99999999999;
};
bool ControleCliente::validar_cliente(long long cpf){
    for (auto it : _clientes){
        if(it.getCPF() == cpf) return true;
    }
    return false;
}

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

    std::filesystem::path caminho = std::filesystem::current_path()/"../data/banco_de_locacoes.csv";
    std::ifstream banco_de_locacoes(caminho.string(), std::ios::app);

    if (!banco_de_locacoes.is_open()) {
        std::cout << "RESTE";
        throw ErroAbrirArquivo();
    }

    std::string linha;
    std::getline(banco_de_locacoes, linha);//descartar headers
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
    int id1 = saida.locacoes.begin()->first;
    saida.dias_desde_alocacao = this->calcula_dias(encontrar_data_alocacao(saida.locacoes[id1].data)); //assumimos que todas as midias são alocadas na mesma data
    this->informacoes_locacoes = saida;
};

void ControleCliente::escrever_locacoes_cliente(long long cpf, std::map<int, info_midia> locacoes){
    std::filesystem::path caminho = std::filesystem::current_path()/"../data/banco_de_locacoes.csv";
    std::ofstream banco_de_locacoes(caminho.string(), std::ios::app);
    if (!banco_de_locacoes.is_open()) {
        throw ErroAbrirArquivo();
    }

    time_t agora = time(0);
    std::string data = ctime(&agora);
    data[data.size() - 1] = '\0';

    for (auto& info_midia : locacoes) {
        banco_de_locacoes << cpf << "," << info_midia.second.titulo << "," << info_midia.first << "," << info_midia.second.quantidade << "," << data << ",\n";
    }

    banco_de_locacoes.close();
}