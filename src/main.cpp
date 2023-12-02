#include <string>
#include <sstream>
#include <iostream>
#include <filesystem>
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
            std::filesystem::path caminho = std::filesystem::current_path();
            std::string path = caminho.string() + "\\" + entrada.substr(3);// USAR '//' no linux
            try
            {
                cinerama.ler_estoque(path);
            }
            catch(const ExcecaoDeposito& e)
            {
                try{
                    path = caminho.string() + "//" + entrada.substr(3); // usando '\\' para windows.
                    cinerama.ler_estoque(path);
                } catch (const ExcecaoDeposito& e) {
                    std::cerr << e.what() << '\n';
                    std::cout << "Erro de leitura. Utilize o comando 'LA' novamente caso queira tentar outra vez." << std::endl;
                }
            }
        }
        
        // Cadastrar Midia
        else if (comando == "CF") {
            int codigo;
            int quantidade;
            std::string tipo;
            std::string titulo;
            std::string categoria;

            std::istringstream stream(entrada.substr(3));
            stream >> tipo >> quantidade >> codigo >> titulo >> categoria;

            try
            {
                cinerama.cadastrar_midia(tipo, quantidade, codigo, titulo, categoria);
            }
            catch(const DadosRepetidos& e)
            {
                std::cerr << e.what() << '\n';
                std::cout << "Codigo de midia ja cadastrado. Voce pode conferir as midias cadastradas com o comando CL" << '\n' ;
            }
            catch(const LocaErro& e)
            {
                std::cerr << e.what() << '\n';
            }
            catch(const DadosInexistente& e)
            {
                std::cerr << e.what() << '\n';
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        // Remover Midia
        else if (comando == "RF") {
            int codigo;

            try
            {
                std::istringstream stream(entrada.substr(3));
                stream >> codigo;
            }
            catch(const std::out_of_range& e)
            {
                std::cout << "Provavelmente sua entrada esta em branco, tente usar RF <int>." << '\n';
                continue;
            }

            try
            {
                cinerama.remover_midia(codigo);
            }
            catch(const DadosInexistente& e)
            {
                std::cerr << e.what() << '\n';
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }

        // Listar Midia ordenadas por Codigo ou Titulo
        else if (comando == "LF") {
            std::string tipo = entrada.substr(3);
            
            //Ordenar por Codigo
            if (tipo == "C"){
                cinerama.ordenar_midias_por_codigo();
            }

            //Ordenar por Titulo
            else if (tipo == "T"){
                cinerama.ordenar_midias_por_titulo();
            }

            else {
                std::cout << "ERRO: ainda nao e possivel ordenar por " << tipo << std::endl;
            }
        }

        // Imprimir midias organizadas por formato
        else if (comando == "CL"){
            cinerama.imprimir_catalogo();
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

        // Listar Clientes ordenados por Codigo ou Nome
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
                std::cout << "ERRO: nao foi possivel reconhecer o metodo para listar. Escolha LC C para ordenar por codigo e LC N para nomes." << std::endl;
            }
        }

        // Aluguel Midia
        else if (comando == "AL") {
            int quantidade_locada;
            long long int cpf;
            bool cpf_valido = false;
            std::map<int, int> locacoes;
            std::cout << "digite o cpf do cliente, 0 para cancelar" << std::endl;
            while (1){
                std::cin >> cpf;
                if(cpf == 0) break;
                else if(!cinerama.validar_CPF(cpf)){
                    std::cout << "Não há cliente com este CPF. Tente novamente, digite 0 para cancelar ou considere cadastrar o cliente." << std:: endl;
                } else {
                    cpf_valido = true;
                    break;
                }
            }
            if(!cpf_valido) continue;

            std::cout << "Digite o código da mídia que deseja se alugar, seguido de um espaço e a quantidade que se deseja alugar" << std::endl;
            std::cout << "Para encontrar códigos, utilize o catálogo. Para finalizar a locação, digite 0" << std::endl;
            while (1){
                int codigo, quantidade, disponiveis;
                std::cin >> codigo;
                if (codigo = 0){
                    break;
                }
                std::cin >> quantidade;

                try {
                    disponiveis = cinerama.get_midia(codigo)->getUnidadesDisponiveis();
                } catch (DadosInexistente &e){
                    std::cout << "Não existe uma mídia com esse código. Digite um novo código e uma nova quantidade." << std::endl;
                    continue;
                }
                
                
                if (quantidade < 1) {
                    std::cout << "Quantidade inválida selecionada. Digite novamente o código e insira uma quantidade entre 1 e o número de unidades disponíveis." << std::endl;
                    continue;
                }
                else if (quantidade > disponiveis) {
                    std::cout << "Quantidade inválida selecionada (maior do que as unidades em estoque). Digite novamente o código e insira uma quantidade entre 1 e o número de unidades disponíveis." << std::endl;
                    continue;
                } 
                else {
                    quantidade_locada++;
                    locacoes[codigo] = quantidade;
                }
            }
            std::cout << "Locação fechada, inciando processo..." << std::endl;
            try{
                cinerama.alugar_midias(cpf, locacoes);
            } catch(DadosInexistente &e){
                std::cout << "Algo deu errado, tente novamente:" << e.what() << std::endl;
            }
            std::cout << "Locação finalizada com sucesso!" << std::endl;
        }

        // Devolucao Midia
        else if (comando == "DV") {
            long long int cpf;
            bool cpf_valido;
            std::cout << "digite o cpf do cliente, 0 para cancelar" << std::endl;
            while (1){
                std::cin >> cpf;
                if(cpf == 0) break;
                else if(!cinerama.validar_CPF(cpf)){
                    std::cout << "Não há cliente com este CPF. Tente novamente, digite 0 para cancelar ou considere cadastrar o cliente." << std:: endl;
                } else {
                    cpf_valido = true;
                    break;
                }
            }
            if(!cpf_valido) continue;
            std::cout << "Cliente localizado, iniciando devolução....." << std::endl;
            try{
            cinerama.devolver_midias(cpf);
            }catch(DadosInexistente &e){
                std::cout<<"Algo deu errado, tente novamente: "<<e.what()<<std::endl;
            }
            std::cout << "Devolução finalizada com sucesso!" << std::endl;
        }

        // Finalizar Sistema
        else if (comando == "FS") {
            return 0;
        }

        else if (comando == "HP") {
            std::cout << "LA <nome_do_arquivo.txt> - Ler arquivo de cadastro" << std::endl;
            std::cout << "CF F <quantidade> <id> <titulo> - Cadastrar Midia do tipo Fita" << std::endl;
            std::cout << "CF D <quantidade> <id> <titulo> <categoria> - Cadastrar Midia do tipo DVD" << std::endl;
            std::cout << "CL - Imprimir midias organizadas por formato" << std::endl;
            std::cout << "RF <id> - Remover Midia" << std::endl;
            std::cout << "LF C - Listar Midia ordenadas por Codigo" << std::endl;
            std::cout << "LF T - Listar Midia ordenadas por Titulo" << std::endl;
            std::cout << "CC <cpf> <nome> - Cadastrar Cliente" << std::endl;
            std::cout << "RC <cpf> - Remover Cliente" << std::endl;
            std::cout << "LC C - Listar Clientes ordenados por CPF" << std::endl;
            std::cout << "LC N - Listar Clientes ordenados por Nome" << std::endl;
            std::cout << "AL - Alugar Midias" << std::endl;
            std::cout << "DV - Devolver Midia" << std::endl;
            std::cout << "PG <genero> - Criar Promocao de genero (APENAS DVD'S)" << std::endl;
            std::cout << "PI <id> - Criar Promocao por id (APENAS DVD'S)" << std::endl;
            std::cout << "RL - Relatorio das receitas do ultimo mês" << std::endl;
            std::cout << "FS - Encerrar o sistema" << std::endl;
        }

        else {
            std::cout << "ERRO: comando nao reconhecido! Insira HP para listar os comandos" << std::endl;
        }
    }
}
// Aluguel Filme
/*AL <CPF> <Codigo1> … <Codigo N>
Cliente <CPF> <Nome> alugou os filmes:
<codigo> <titulo> <FITA|DVD> (Lista com todos os itens, um por linha)
ERRO: CPF inexistente
ERRO: Filme <codigo> inexistente*/

// Devolucao Filme
/* NAO EXISTE UMA FUNCAO QUE RECEBE SOMENTE O CPF NO LOCADOR, FALTA METODO PARA LER O CLIENTE E CALCULAR
DV <CPF>
Cliente <CPF> <Nome> devolveu os filmes:
<codigo> [Valor a Pagar] (Lista com todos os itens, um por linha)
Total a pagar: [Total]
ERRO: CPF inexistente*/

/*
PROBLEMAS SEM SOLUCAO

- Aluguel e Devolucao de filmes
- No metodo devolver_midias do Locador e esperado um parametro dias, porem este deve ser calculado pelo propio metodo
- Nao temos Excecoes e Programacao Defensiva
- Tem como transformar um DVD Estoque em DVD Promocao? SIM, APENAS DESCADASTRAR E CADASTRAR COM NOVA CATEGORIA

PROBLEMAS SOLUCIONADOS

- Metodos faltando para a comunicacao entre Locador - Deposito
- Metodo para cadastrar midia
- Controle de Adicao/Edicao de Locacoes por meio de CSV e CTIME (banco de locacoes)
- Escrever locacao no banco de locacoes
- Classe Locadora
- Banco de Midias/Estoque
- Leitura do Banco de Midias ao construir um Deposito
- Salvar midias no Banco de Midias ao destruir um Deposito
- Comando HELP, para listar todos comandos existentes no main

FUNCOES QUE ESTAO/SERAO IMPLEMENTADAS

- Funcao genero, para classificar e colocar em promocao generos especificos, como terror. (DEVE SER VOTADO PELOS MEMBROS) ps: e uma funcao crucial para uma locadora
- Imprimir filmes mais alugados
- Imprimir filmes menos alugados - ignorando os lancamentos
- Imprimir receitas do ultimo mes

*/
