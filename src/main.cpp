#include <string>
#include <sstream>
#include <iostream>
#include "../include/Locadora/Locadora.hpp"

int main(){
    Locadora cinerama;

    while(true){
        std::string entrada;
        getline(std::cin, entrada);

        if (entrada.length() < 2){
            continue;
        }

        std::string comando = entrada.substr(0, 2);

        // Ler Arquivo de Cadastro
        if (comando == "LA") {
            cinerama.ler_estoque(entrada.substr(2));
        }
        
        // Cadastrar Midia
        else if (comando == "CF") {
            int codigo;
            int quantidade;
            std::string tipo;
            std::string titulo;
            std::string categoria;

            std::istringstream stream(entrada.substr(2));
            stream >> tipo >> quantidade >> codigo >> titulo >> categoria;

            cinerama.cadastrar_midia(tipo, quantidade, codigo, titulo, categoria);
        }

        // Remover Midia
        else if (comando == "RF") {
            int codigo;
            std::istringstream stream(entrada.substr(2));
            stream >> codigo;

            cinerama.remover_midia(codigo);
        }

        // Listar Midia ordenadas por Código ou Título
        else if (comando == "LF") {
            std::string tipo = entrada.substr(2);
            
            //Ordenar por Código
            if (tipo == "C"){
                cinerama.ordenar_midias_por_codigo();
            }

            //Ordenar por Titulo
            else if (tipo == "T"){
                cinerama.ordenar_midias_por_titulo();
            }

            else {
                std::cout << "ERRO: ainda não é possível ordenar por " << tipo << std::endl;
            }
        }
        
        // Cadastrar Cliente
        else if (comando == "CC") {
            long cpf;
            std::string nome;

            std::istringstream stream(entrada.substr(2));
            stream >> cpf >> nome;

            cinerama.cadastrar_cliente(cpf, nome);

        }

        // Remover Cliente
        else if (comando == "RC") {
            long cpf;

            std::istringstream stream(entrada.substr(2));
            stream >> cpf;

            cinerama.remover_cliente(cpf);
        }

        // Listar Clientes ordenados por Código ou Nome
        else if (comando == "LC") {
            std::string tipo;

            std::istringstream stream(entrada.substr(2));
            stream >> tipo;

            if (tipo == "C"){
                cinerama.listar_clientes_por_cpf();
            }            

            else if (tipo == "N"){
                cinerama.listar_clientes_por_nome();
            }

            else {
                std::cout << "ERRO: não foi possivel reconhecer o método para listar. Escolha LC C para ordenar por código e LC N para nomes." << std::endl;
            }
        }

        // Aluguel Midia
        else if (comando == "AL") {
            map<int, int> locacoes;
            //VETOR DE ENTRADA PARA N MIDIAS
            //cinerama.escrever_locacoes_cliente()
        }

        // Devolução Midia
        else if (comando == "DV") {
            long cpf;
            std::istringstream stream(entrada.substr(2));
            stream >> cpf;

            //cinerama.devolver_midias();
            //cinerama.devolver_midias(cpf);
        }

        // Finalizar Sistema
        else if (comando == "FS") {
            return 0;
        }

        else if (comando == "HP") {
            std::cout << "LA <nome_do_arquivo.txt> - Ler arquivo de cadastro" << std::endl;
            std::cout << "CF F <quantidade> <id> <titulo> - Cadastrar Mídia do tipo Fita" << std::endl;
            std::cout << "CF D <quantidade> <id> <titulo> <categoria> - Cadastrar Mídia do tipo DVD" << std::endl;
            std::cout << "RF <id> - Remover Mídia" << std::endl;
            std::cout << "LF C - Listar Midia ordenadas por Código" << std::endl;
            std::cout << "LF T - Listar Midia ordenadas por Título" << std::endl;
            std::cout << "CC <cpf> <nome> - Cadastrar Cliente" << std::endl;
            std::cout << "RC <cpf> - Remover Cliente" << std::endl;
            std::cout << "LC C - Listar Clientes ordenados por CPF" << std::endl;
            std::cout << "LC N - Listar Clientes ordenados por Nome" << std::endl;
            std::cout << "AL - Alugar Mídias" << std::endl;
            std::cout << "DV - Devolver Mídia" << std::endl;
            std::cout << "PG <genero> - Criar Promoção de genero (APENAS DVD'S)" << std::endl;
            std::cout << "PI <id> - Criar Promoção por id (APENAS DVD'S)" << std::endl;
            std::cout << "RL - Relatorio das receitas do ultimo mês" << std::endl;
            std::cout << "FS - Encerrar o sistema" << std::endl;
        }

        else {
            std::cout << "ERRO: comando não reconhecido! Insira HP para listar os comandos" << std::endl;
        }
    }
}
// Aluguel Filme
/*AL <CPF> <Código1> … <Código N>
Cliente <CPF> <Nome> alugou os filmes:
<código> <título> <FITA|DVD> (Lista com todos os itens, um por linha)
ERRO: CPF inexistente
ERRO: Filme <codigo> inexistente*/

// Devolução Filme
/* NAO EXISTE UMA FUNCAO QUE RECEBE SOMENTE O CPF NO LOCADOR, FALTA METODO PARA LER O CLIENTE E CALCULAR
DV <CPF>
Cliente <CPF> <Nome> devolveu os filmes:
<código> [Valor a Pagar] (Lista com todos os itens, um por linha)
Total a pagar: [Total]
ERRO: CPF inexistente*/

/*
PROBLEMAS SEM SOLUCAO

- Aluguel e Devolução de filmes
- No método devolver_midias do Locador é esperado um parametro dias, porém este deve ser calculado pelo própio método
- Não temos Exceções e Programação Defensiva
- Tem como transformar um DVD Estoque em DVD Promoção? SIM, APENAS DESCADASTRAR E CADASTRAR COM NOVA CATEGORIA

PROBLEMAS SOLUCIONADOS

- Metodos faltando para a comunicacao entre Locador - Deposito
- Metodo para cadastrar mídia
- Controle de Adição/Edição de Locações por meio de CSV e CTIME (banco de locações)
- Escrever locação no banco de locações
- Classe Locadora
- Banco de Midias/Estoque
- Leitura do Banco de Midias ao construir um Deposito
- Salvar midias no Banco de Midias ao destruir um Deposito
- Comando HELP, para listar todos comandos existentes no main

FUNCOES QUE ESTAO/SERAO IMPLEMENTADAS

- Função genero, para classificar e colocar em promoção generos especificos, como terror. (DEVE SER VOTADO PELOS MEMBROS) ps: é uma função crucial para uma locadora
- Imprimir filmes mais alugados
- Imprimir filmes menos alugados - ignorando os lançamentos
- Imprimir receitas do ultimo mes

*/