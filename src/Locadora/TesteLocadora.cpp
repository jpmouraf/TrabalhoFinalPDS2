#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "../../include/Locadora/Locadora.hpp"
#include "../../include/Clientes/Clientes.hpp"
#include "../../include/ControleDeMidia/Deposito.hpp"
#include "../../include/ControleDeMidia/Jogo.hpp"
#include "../../include/ControleDeMidia/Dvd.hpp"
#include "../../include/ControleDeMidia/Fita.hpp"

/**
 * Teste da função validar_cpf
 */
TEST_CASE("Teste de validar Cpf") {
    ControleCliente cliente; /// Criando um objeto ControleCliente para teste
    CHECK(cliente.validar_CPF(12345678900) == true);
    CHECK(cliente.validar_CPF(0) == false);
    CHECK(cliente.validar_CPF(123456789000) == false);
}

/**
 * Teste da função Deposito get_midia
 */
TEST_CASE("Teste de deposito do get_midia") {
    Deposito deposito; /// Criando um objeto Deposito para teste

/**
 * Adicionando uma midia para teste
*/
    int codigo_existente = 123; /// Código de mídia existente
    Midia* midia_existente = new Promocao(codigo_existente, "Titulo", 8); /// Simulação de uma mídia existente
    deposito.cadastrar_dvd(8, codigo_existente, "Titulo", "Promocao"); ///cadastra a midia teste

    Midia* midia_retornada = deposito.get_midia(codigo_existente); /// Obtém a mídia e verifica se não é nulo
    CHECK(midia_retornada != nullptr); /// Verifica se a mídia retornada não é nula
/**
* Teste para código de mídia inexistente (deve lançar exceção)
*/
    int codigo_nao_existente = 456; /// Código de mídia inexistente
    CHECK_THROWS_AS(deposito.get_midia(codigo_nao_existente), DadosInexistente); /// Verifica se lança a exceção DadosInexistente
}

/**
 * Teste para calcular locacao do jogo
*/
TEST_CASE("Teste do método calcular_locacao da classe Jogo") {
    Jogo jogo(123, "Nome" , 5);

    int nivel_arranhado = 0; /// Testando o cálculo da locação com nível arranhado 0 (mínimo)
    int valor_esperado_minimo = 5 * nivel_arranhado + 5;
    int valor_retornado_minimo = jogo.calcular_locacao(1); /// Supondo 1 dia de locação

    CHECK(valor_retornado_minimo >= valor_esperado_minimo); /// Verifica se o valor retornado é maior ou igual ao valor mínimo esperado

    int nivel_arranhado_maximo = 9; /// Testando o cálculo da locação com nível arranhado 9 (máximo)
    int valor_esperado_maximo = 5 * nivel_arranhado_maximo + 5;
    int valor_retornado_maximo = jogo.calcular_locacao(1); /// Supondo 1 dia de locação

    CHECK(valor_retornado_maximo <= valor_esperado_maximo); /// Verifica se o valor retornado é menor ou igual ao valor máximo esperado
}

/**
 * Teste para calcular locacao da fita
*/
TEST_CASE("Teste do método calcular_locacao da classe Fita") {
    Fita fita(123, "Nome" , 4);

    SUBCASE("Fita não rebobinada") {
        int valor_nao_rebobinada = fita.calcular_locacao(1); /// Supondo 1 dia de locação para uma fita não rebobinada

        CHECK(valor_nao_rebobinada == 5); /// Verifica se o valor retornado para uma fita não rebobinada é 5
    }

    SUBCASE("Fita rebobinada") {
        int valor_rebobinada = fita.calcular_locacao(1); /// Supondo 1 dia de locação para uma fita rebobinada

        CHECK(valor_rebobinada == 7); /// Verifica se o valor retornado para uma fita rebobinada é 7
    }
}

/**
 * Teste para calcular locacao Lancamento
*/
TEST_CASE("Teste do método calcular_locacao da classe Lancamento") {
    Lancamento lancamento(125, "Titulo", 5); 

    SUBCASE("Locação por 1 dia para Lancamento") {
        int valor_retornado_1_dia = lancamento.calcular_locacao(1); /// Supondo 1 dia de locação para um Lancamento

        CHECK(valor_retornado_1_dia == 20); /// Verifica se o valor retornado para 1 dia de locação é 20
    }
}

/**
 * Teste para calcular locacao Estoque
*/
TEST_CASE("Teste do método calcular_locacao da classe Estoque") {
    Estoque estoque(126, "Titulo", 10);

    SUBCASE("Locação por 3 dias para Estoque") {
        int valor_retornado_3_dia = estoque.calcular_locacao(3); /// Supondo 3 dias de locação para um Estoque

        CHECK(valor_retornado_3_dia == 30); /// Verifica se o valor retornado para 3 dias de locação é 30
    }
}

/**
 * Teste para calcular locacao Promocao
*/
TEST_CASE("Teste do método calcular_locacao da classe Promocao") {
    Promocao promocao(127, "Titulo", 6);

    SUBCASE("Locação por 5 dias para Promocao") {
        int valor_retornado_5_dia = promocao.calcular_locacao(5); /// Supondo 5 dias de locação para uma Promocao

        CHECK(valor_retornado_5_dia == 10); /// Verifica se o valor retornado para 1 dia de locação é 10
    }
}
