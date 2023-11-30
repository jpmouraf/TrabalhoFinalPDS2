#include <string>
#include <sstream>
#include <iostream>
#include "../include/Clientes/Clientes.hpp"
#include "../include/ControleDeLocacao/Locador.hpp"

int main(){
    Locador controle_de_locacoes;
    ControleCliente controle_de_clientes;


    while(true){
        std::string entrada;
        getline(std::cin, entrada);

        if (entrada.length() < 2){
            continue;
        }

        std::string comando = entrada.substr(0, 2);

        // Ler Arquivo de Cadastro
        if (comando == "LA") {
            controle_de_locacoes.ler_estoque(entrada.substr(2));
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

            controle_de_locacoes.cadastrar_midia(tipo, quantidade, codigo, titulo, categoria);
        }

        // Remover Midia
        else if (comando == "RF") {
            int codigo;
            std::istringstream stream(entrada.substr(2));
            stream >> codigo;

            controle_de_locacoes.remover_midia(codigo);
        }

        // Listar Midia ordenadas por Código ou Título
        else if (comando == "LF") {
            std::string tipo = entrada.substr(2);
            
            //Ordenar por Código
            if (tipo == "C"){
                controle_de_locacoes.ordenar_codigo();
                controle_de_locacoes.imprimir_todas_midias();
            }

            //Ordenar por Titulo
            else if (tipo == "T"){
                controle_de_locacoes.ordenar_titulo();
                controle_de_locacoes.imprimir_todas_midias();
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

            controle_de_clientes.cadastrar_cliente(cpf, nome);

        }

        // Remover Cliente
        else if (comando == "RC") {
            long cpf;

            std::istringstream stream(entrada.substr(2));
            stream >> cpf;

            controle_de_clientes.remover_cliente(cpf);
        }

        // Listar Clientes ordenados por Código ou Nome
        else if (comando == "LC") {
            std::string tipo;

            std::istringstream stream(entrada.substr(2));
            stream >> tipo;

            if (tipo == "C"){
                controle_de_clientes.listar_codigo();
            }            

            else if (tipo == "N"){
                controle_de_clientes.listar_nome();
            }

            else {
                std::cout << "ERRO: não foi possivel reconhecer o método para listar. Escolha LC C para ordenar por código e LC N para nomes." << std::endl;
            }
        }

        // Aluguel Midia
        else if (comando == "AL") {
            map<int, int> locacoes;
            //VETOR DE ENTRADA PARA N MIDIAS
            controle_de_clientes.escrever_locacoes_cliente()
        }

        // Devolução Midia
        else if (comando == "DV") {
            long cpf;
            std::istringstream stream(entrada.substr(2));
            stream >> cpf;

            controle_de_locacoes.devolver_midias();
            //cinerama.devolver_midias(cpf);
        }

        // Finalizar Sistema
        else if (comando == "FS") {
            return 0;
        }

        else if (comando == "CM") {
            std::cout << "LA - Ler arquivo de cadastro" << std::endl;
            std::cout << "CF - Cadastrar Mídia" << std::endl;
            std::cout << "RF - Remover Mídia" << std::endl;
            std::cout << "LF - Listar Midia ordenadas por Código ou Título" << std::endl;
            std::cout << "CC - Cadastrar Cliente" << std::endl;
            std::cout << "RC - Remover Cliente" << std::endl;
            std::cout << "AL - Listar Midia ordenadas por Código ou Título" << std::endl;
            std::cout << "DV - Listar Midia ordenadas por Código ou Título" << std::endl;
            std::cout << "PR - Criar Promoção de uma categoria ou genero" << std::endl;
            std::cout << "RL - Relatorio das receitas do ultimo mês" << std::endl;       
        }

        else {
            std::cout << "ERRO: comando não reconhecido! Insira CM para listar os comandos" << std::endl;
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

- Não temos uma classe Locadora
- No método devolver_midias do Locador é esperado um parametro dias, porém este deve ser calculado pelo própio método
- Não temos Exceções e Programação Defensiva
- Tem como transformar um DVD Estoque em DVD Promoção?

PROBLEMAS SOLUCIONADOS

- Metodos faltando para a comunicacao entre Locador - Deposito;

FUNCOES QUE ESTAO/SERAO IMPLEMENTADAS

- Comando HELP, para listar todos comandos existentes no main
- Função genero, para classificar e colocar em promoção generos especificos, como terror. (DEVE SER VOTADO PELOS MEMBROS) ps: é uma função crucial para uma locadora
- Imprimir filmes mais alugados
- Imprimir filmes menos alugados - ignorando os lançamentos

*/
